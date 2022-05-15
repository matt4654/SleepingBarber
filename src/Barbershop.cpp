#include "../include/Babershop.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h> 
#include <time.h>

Barbershop::Barbershop()
    : WaitingRoomChairs(5), CustomerNumber(0) {}

void Barbershop::CustomerProcess()
{
    srand(time(0));
    while(true)
    {
        static int NextCustomerTime;
        NextCustomerTime = (rand() % 5000) + 1;
        std::this_thread::sleep_for(std::chrono:: milliseconds(NextCustomerTime)); 

        std::shared_ptr<Customer> NewCustomer = std::make_shared<Customer>(++CustomerNumber);
        std::cout << "Customer" << NewCustomer->GetNumber() << " enters" << std::endl;

        std::unique_lock<std::mutex> qLock(queue); 
        if(WaitingCustomers.size() == WaitingRoomChairs)
        {
            std::cout << "No free chairs so customer" << NewCustomer->GetNumber() << " LEAVES" << std::endl;
        }
        else if(WaitingCustomers.size() == 0 && theBarber.GetSleeping())
        {
            std::cout << "Customer" << NewCustomer->GetNumber() << " sits down in waiting room and WAKES BARBER" << std::endl;
            WaitingCustomers.push(NewCustomer);
            theBarber.SetSleeping(false);
            CustomerReady.notify_one();
            qLock.unlock();
        }
        else
        {
            std::cout << "Customer" << NewCustomer->GetNumber() << " sits down in waiting room" << std::endl;
            WaitingCustomers.push(NewCustomer);
        }
    }
}

void Barbershop::BarberProcess()
{
    srand(time(0));
    while(true)
    {
        std::cout << "Barber checks wating room" << std::endl;

        std::unique_lock<std::mutex> qLock(queue);
        if(WaitingCustomers.size() == 0)
        {
            std::cout << "No customers waiting, so barber FALLS ASLEEP" << std::endl;
            theBarber.SetSleeping(true);
            CustomerReady.wait(qLock);
        }
        if(WaitingCustomers.size() != 0)
        {
            std::cout << "Barber STARTS cutting customer" << WaitingCustomers.front()->GetNumber() << "'s hair" << std::endl;

            qLock.unlock();
            static int HairCutTime;
            HairCutTime = (rand() % 5000) + 1;
            std::this_thread::sleep_for(std::chrono:: milliseconds(HairCutTime));
            qLock.lock();

            std::cout << "Barber FINISHES cutting customer" << WaitingCustomers.front()->GetNumber() << "'s hair" << std::endl;
            WaitingCustomers.pop();
        }
    }
}
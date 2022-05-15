#ifndef BARBERSHOP_H
#define BARBERSHOP_H

#include "../include/Barber.h"
#include "../include/Customer.h"

#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

class Barbershop
{
    private:
        int CustomerNumber;
        int WaitingRoomChairs;
        Barber theBarber;
        std::queue<std::shared_ptr<Customer>> WaitingCustomers;
        std::mutex queue;
        std::condition_variable CustomerReady;

    public:
        //Constructor
        Barbershop();

        //Methods
        void BarberProcess();
        void CustomerProcess();
};

#endif
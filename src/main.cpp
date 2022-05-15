#include "../include/Babershop.h"

#include <thread>
#include <iostream>
#include <stdlib.h> 
#include <chrono>

int main()
{
    srand(time(0));

    Barbershop myBarbershop;

    std::thread thread2(&Barbershop::BarberProcess, &myBarbershop);
    std::thread thread1(&Barbershop::CustomerProcess, &myBarbershop);    
    
    thread1.join();
    thread2.join();

    return 0;    
}
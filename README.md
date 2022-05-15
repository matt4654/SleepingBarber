# Sleeping Barber Problem - C++

##Problem Statement 

https://en.wikipedia.org/wiki/Sleeping_barber_problem#Problem_statement

## Description

* Two functions, `CustomerProcess()` and `BarberProcess()`, running on separate threads, track the behaviour of `Customer` and `Barber` objects, respectively, within a `Barbershop` object
* Customers enter the barbershop at random time intervals
* A customer's haircuts takes a random time interval to complete
* If there are no customers in the barbershop, `BarberProcess()` waits until a customer enters before trying to see another customer
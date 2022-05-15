#include "../include/Customer.h"

Customer::Customer(int n)
    : Number(n) {}

int Customer::GetNumber() const 
{
    return Number;
}

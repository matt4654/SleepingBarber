#include "../include/Barber.h"

Barber::Barber()
    : Sleeping(false) {}


bool Barber::GetSleeping() const
{
    return Sleeping;
}

void Barber::SetSleeping(bool s)
{
    Sleeping = s;
}


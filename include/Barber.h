#ifndef BARBER_H
#define BARBER_H

class Barber
{
    private:
        bool Sleeping;
    
    public:
        //Constructor 
        Barber();

        //Get/Set
        bool GetSleeping() const;
        void SetSleeping(bool s);
};

#endif
#ifndef CUSTOMER_H  
#define CUSTOMER_H

class Customer
{
    private:
        const int Number;

    public:
        //Constructor
        explicit Customer(int);

        //Get
        int GetNumber() const;

};

#endif
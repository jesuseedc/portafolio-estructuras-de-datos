#ifndef CUSTOMER_CPP_INCLUDED
#define CUSTOMER_CPP_INCLUDED


#include <iostream>
#include <cstdlib>
#include <string>

class Customer{
    friend std::ostream &operator<<(std::ostream &o, const Customer &c);

public:

    /** \brief Customer name constructor.
     *
     * \param Name of the customer
     * \param Surname of the customer
     *
     */
    Customer(std::string name = "No", std::string surname = "one");

private:
    std::string Name, Surname;
};



#endif // CUSTOMER_CPP_INCLUDED

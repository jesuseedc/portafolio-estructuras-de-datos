#include "Customer.h"
//****************************************************************
Customer::Customer(std::string name, std::string surname)
{
    Name = name;
    Surname = surname;
}

//****************************************************************
std::ostream &operator<<(std::ostream &o, const Customer &c)
{
    return o << c.Name << " " << c.Surname;
}

//****************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h> //Linux
//#include <windows.h> //Windows

#include "Queue.h"
#include "Customer.h"

#include <unistd.h>

using namespace std;

int main()
{
    string Name[14] = {"John", "Claudius", "Patrick", "Henry", "Ana", "Grace", "Kelly", "Tyra", "Angela", "Steve", "Sophie", "Judith", "Ann", "Joseph"};
    string Surname[12] = {"Doe", "Dunn", "Walsh", "Wilson", "Marshall", "Rodriguez", "Lee", "Phillips", "Zimmermann", "Edison", "Brown", "Garcia"};

    try{
        srand(time(NULL));
        Queue<Customer> customers, served;
        Customer cust, custOnCash;

        int waiting = 0;
        int timeOpened = 0;

        while (timeOpened <= 480){
            cout << "[A bank queue simulation using FIFO structure by Jesus Escobedo]" << endl << endl;
            cout << "Time left to close: " << ((480 - timeOpened) / 60) << " hours" << endl;

            if((rand() % 30) % 6 == 0){
                cust = Customer(Name[rand() % 14], Surname[rand() % 8]);
                customers.Add(cust);
            }

            if(customers.ItsEmpty()){
                cout << "Cashier is ready for service!";
            }else{
                if(waiting == 10){
                    served.Add(customers.GetFirst());
                    waiting = 0;
                    custOnCash = customers.GetFirst();
                    customers.Remove();
                }

                cout << custOnCash << " it's on the cash." << endl;
                cout << "Time elapsed: " << waiting;
                ++waiting;
            }

            cout << endl << endl << "Waiting: " << endl;
            customers.Print();
            ++timeOpened;
            usleep(1000000); // Para Linux
            //Sleep(1000000); // Para Win2

            system("clear");
        }

        cout << "Bank is closed now, " << served.GetSize() << " customers were attended and ";
        cout << customers.GetSize() << " are pending." << endl;
        cout << "Customers pending: " << endl;
        customers.Print();

    }catch(bad_alloc &exc){
        cout << "bad_alloc caught: " << exc.what() << endl;
    }catch(...){
        cout << "Sorry, we have a unexpected error." << endl;
    }

    cout << endl << "Press enter to close." ;
    while(getchar() != '\n');

    return 0;
}

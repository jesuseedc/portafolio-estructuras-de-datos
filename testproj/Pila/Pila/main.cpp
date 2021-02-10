#include <iostream>
#include <ctime>

#include "Pila.h"

using namespace std;

int main()
{
    try {
        Pila<int, 100> p;

        p.Imprimir();
        cout << "La pila contiene " << p.ObtenerTam() << " elemento(s)" << endl;

        srand(time(NULL));
        for(int i = 0; i < 100; ++i){
            p.Apilar(rand()%100 / 10.0);
            p.Imprimir();
            cout << "La pila contiene " << p.ObtenerTam() << " elemento(s)" << endl;
        }
    }catch(const exception & exc){
        cout << "Error: " << exc.what() << endl;
    }

    return 0;

}

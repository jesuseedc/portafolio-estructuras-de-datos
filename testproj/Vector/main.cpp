#include <iostream>
#include <limits>

#include "Vector.h"

using namespace std;

int main()
{
    try{
       Vector v(3), w(3), z(3);

       //cout << v.ObtenerDimension() << endl;

       cout << "Suma de dos vectores." << endl;

       cout << "Capturando las " << v.ObtenerDimension() << " componentes del primer vector..." << endl;
       v.Capturar();

       cout << "Capturando las " << w.ObtenerDimension() << " componentes del segundo vector..." << endl;
       w.Capturar();

       Vector y;

       y = z = v + w;
       //z = v.operator+(w);

       cout << "\n\n Resultados" << endl;
       cout << "\nV = ";
       v.Imprimir();
       cout << "\nW = ";
       w.Imprimir();
       cout << "\nV + W = ";
       (z).Imprimir();

       //Vector a = 5.3;

       //a.Imprimir();

       y = 2.5*v;
       cout << "v * 2.5 = ";
       (y).Imprimir();

    }catch(out_of_range &exc){
        cout << "\n Error: " << exc.what() << endl;
    }catch(logic_error &exc){
        cout << "\n Error: " << exc.what() << endl;
    }catch(bad_alloc &exc){
        cout << "\n Error: " << exc.what() << endl;
    }

    return 0;

}

#include "Vector.h"

//----------------------------------------------------------------------------
Vector::Vector()
{
    EstablecerDimension(1);
    componente = new double[1];
    componente[0] = 0;
}

//----------------------------------------------------------------------------
Vector::Vector(int dim)
{
    EstablecerDimension(dim);
    componente = new double[dim];
    for(int i = 0 ; i < dimension ; ++i) componente[i] = 0;
}

//----------------------------------------------------------------------------
Vector::Vector(int dim, double valorInicial)
{
    EstablecerDimension(dim);
    componente = new double[dim];
    for(int i = 0 ; i < dimension ; ++i) componente[i] = valorInicial;
}

//----------------------------------------------------------------------------

Vector::Vector(const Vector &v)
{
    EstablecerDimension(v.dimension);
    componente = new double [dimension];
    for(int i = 0 ; i < dimension ; ++i) componente[i] = v.componente[i];
}

//----------------------------------------------------------------------------

Vector::~Vector()
{
    delete [] componente;
    std::cout << std::endl << "Destruyendo un Vector.." << std::endl;
}

//----------------------------------------------------------------------------
void Vector::EstablecerComponente(int i, double comp)
{
    if(i < 0 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    componente[i] = comp;
}

//----------------------------------------------------------------------------
void Vector::EstablecerDimension(int dim)
{
    if(dim < 1 || dim > MAXDIM) throw std::logic_error("Dimensi\242n fuera de rango");
    dimension = dim;
}

//----------------------------------------------------------------------------
double Vector::ObtenerComponente(int i) const
{
    if(i < 0 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    return componente[i];
}

//----------------------------------------------------------------------------
int Vector::ObtenerDimension() const
{
    return dimension;
}

//----------------------------------------------------------------------------
void Vector::Imprimir() const
{
    std::cout << "(";
    for(int i = 0 ; i < dimension ; ++i) std::cout << componente[i] << ", ";
    std::cout << "\b\b)";
}

//----------------------------------------------------------------------------
void Vector::Capturar()
{
    for(int i = 0 ; i < dimension ; ++i){
        std::cout << "Componente #" << i + 1 << ": ";
        std::cin >> componente[i];
    }
}

//----------------------------------------------------------------------------
/*
Vector Vector::Sumar(Vector v) const
{
    if(dimension != v.dimension) throw std::logic_error("Dimensiones incompatibles para la suma.");
    Vector S(dimension);
    for(int i = 0; i < S.dimension ; ++i)
        S.componente[i] = componente[i] + v.componente[i];
    return S;
}
*/
//----------------------------------------------------------------------------
Vector Vector::Resta(Vector v) const
{
    if(dimension != v.dimension) throw "Dimensiones incompatibles para restar.";
    Vector R(dimension);
    for(int i = 0; i < R.dimension ; ++i)
        R.componente[i] = componente[i] - v.componente[i];
    return R;
}

//----------------------------------------------------------------------------
Vector Vector::operator*(double escalar) const
{
    Vector P(dimension);
    for(int i = 0; i < dimension; ++i)
        P.componente[i] = componente[i] * escalar;
    return P;
}

//----------------------------------------------------------------------------

#include <cmath>
double Vector::ObtenerMagnitud() const
{
    double suma = 0;
    for(int i = 0; i < dimension ; ++i) suma += componente[i]*componente[i];
    return std::sqrt(suma);
}

//----------------------------------------------------------------------------

Vector Vector::operator+(Vector v) const
{
    if(dimension != v.dimension) throw "Dimensiones incompatibles para restar.";
    Vector R(dimension);
    for(int i = 0; i < R.dimension ; ++i)
        R.componente[i] = componente[i] + v.componente[i];
    return R;
}

//----------------------------------------------------------------------------
Vector & Vector::operator=(const Vector &v)
{
    if(this == &v) return * this;
    delete[] componente;
    EstablecerDimension(v.dimension);
    componente = new double[dimension];
    for(int i = 0; i < dimension ; ++i) componente[i] = v.componente[i];
    return * this;
}

//----------------------------------------------------------------------------
// Funcines amikas de Vector

Vector operator*(double escalar, const Vector &v)
{
    return v * escalar;
}

//----------------------------------------------------------------------------
// Funciones externas

void operator<<(std::ostream &fsalida, const Vector &v)
{
    fsalida << "(";
    for(int i = 0 ; i < v.ObtenerDimension() ; ++i) fsalida << v.ObtenerComponente(i) << ", ";
    fsalida << "\b\b)";
}

//----------------------------------------------------------------------------

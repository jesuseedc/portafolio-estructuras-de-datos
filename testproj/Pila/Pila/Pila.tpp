#define SIN_ELEM -1

//------------------------------------------------------------------------
template <typename T, unsigned s>
Pila<T, s>::Pila(): tope(SIN_ELEM) {}

//------------------------------------------------------------------------
template <typename T, unsigned s>
void Pila<T, s>::Apilar(T valor)
{
    if(EstaLlena()) throw PilaLlena();
    contenido[++tope] = valor;
}

//------------------------------------------------------------------------
template <typename T, unsigned s>
void Pila<T, s>::Desapilar(T valor)
{
    if(EstaVacia()) throw PilaVacia();
    --tope;
}

//------------------------------------------------------------------------
template <typename T, unsigned s>
const T & Pila<T, s>::ObtenerTope() const
{
    if(EstaVacia()) throw PilaVacia();
    return contenido[tope];
}

//------------------------------------------------------------------------
template <typename T, unsigned s>
bool Pila<T, s>::EstaVacia() const
{
    return tope == SIN_ELEM;
}

//------------------------------------------------------------------------
template <typename T, unsigned s>
bool Pila<T, s>::EstaLlena() const
{
    return tope == s - 1;
}

//------------------------------------------------------------------------
template <typename T, unsigned s>
unsigned Pila<T, s>::ObtenerTam() const
{
    return unsigned(tope + 1);
}

//------------------------------------------------------------------------
template <typename T, unsigned s>
void Pila<T, s>::Vaciar()
{
    tope = SIN_ELEM;
}
//------------------------------------------------------------------------
template <typename T, unsigned s>
void Pila<T, s>::Imprimir() const
{
    std::cout << *this;
}

//------------------------------------------------------------------------
//funcion de clase anidada
template <typename T, unsigned s>
const char * Pila<T, s>::PilaLlena::what() const throw()
{
    return "La pila est\240 llena.";
}

//------------------------------------------------------------------------
//funcion de clase anidada
template <typename T, unsigned s>
const char * Pila<T, s>::PilaVacia::what() const throw()
{
    return "La pila est\240 vac\241a.";
}

//------------------------------------------------------------------------
// clase amiga
/*
template <typename T>
std::ostream & operator<< (std::ostream & salida, const Pila<T> &p)
{
    salida << std::endl;
    if(!p.EstaVacia()) salida << p.contenido[p.tope];
    salida << " <- Tope" << std::endl;
    for(int i = p.tope - 1; i >= 0; --i) salida << p.contenido[i] << std::endl;
    return salida << "____________" << std::endl;
}
*/

//------------------------------------------------------------------------

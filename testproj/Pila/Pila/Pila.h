#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>
#include <exception>

#define TAM 10

template <typename T, unsigned s>
class Pila;

template <typename T, unsigned s>
std::ostream & operator<< (std::ostream & salida, const Pila<T, s> &p)
{
    salida << std::endl;
    if(!p.EstaVacia()) salida << p.contenido[p.tope];
    salida << " <- Tope" << std::endl;
    for(int i = p.tope - 1; i >= 0; --i) salida << p.contenido[i] << std::endl;
    return salida << "____________" << std::endl;
}

/** \brief LIFO
 *
 * \tparam T Tipo de los elementos de la pila
 * \return
 *
 */
template <typename T, unsigned s>
class Pila{

    /** \brief
     *
     * \param salida std::ostream&
     * \param p const Pila<T>&
     * \return friend std::ostream&
     *
     */
    friend std::ostream & operator<< <> (std::ostream & salida, const Pila<T, s> &p);
public:

    /** \brief
     */
    class PilaLlena : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \brief
     */
    class PilaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
    };

    /** \brief
     *
     *
     */
    Pila();

    /** \brief
     *
     * \param valor double
     * \return void
     *
     */
    void Apilar(T valor);

    /** \brief
     *
     * \return void
     *
     */
    void Desapilar(T valor);

    /** \brief
     *
     * \return int
     *
     */
    const T &ObtenerTope() const;

    /** \brief
     *
     * \return bool
     *
     */
    bool EstaVacia() const;

    /** \brief
     *
     * \return bool
     *
     */
    bool EstaLlena() const;

    /** \brief
     *
     * \return unsigned
     *
     */
    unsigned ObtenerTam() const;

    /** \brief
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief
     *
     * \return void
     *
     */
    void Imprimir() const;



private:
    int tope;
    T contenido[s];
};


#include "Pila.tpp"

#endif // PILA_H_INCLUDED

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdexcept>
#include <iostream>

#define MAXDIM 100


class Vector{
    // Operador escalar * Vector
    friend Vector operator*(double escalar, const Vector &v);
public:
    Vector();           // constructor por default
    explicit Vector(int dim);    // constructor u operador de conversion
    Vector(int dim, double valorInicial);
    Vector(const Vector &v); // constructor de copias


    ~Vector();

    /** \brief Funci&oacute;n que establece un nuevo componente
     *
     * \param i int
     * \param comp double
     * \return void
     *
     */
    void EstablecerComponente(int i, double comp);

    /** \brief Funci&oacute;n que establece la dimension para los vectores de nueva creacion
     *
     * \param dim int
     * \return void
     *
     */
    void EstablecerDimension(int dim);


    /** \brief
     *
     * \param i int
     * \return double
     *
     */
    double ObtenerComponente(int i) const;

    /** \brief Funci&oacute;n que obtiene la dimension del vector
     *
     * \return int dimension del vector.
     *
     */
    int ObtenerDimension() const;


    /** \brief Funci&oacute;n dedicada a la impresion de vectores
     *
     * \return void
     *
     */
    void Imprimir() const;

    /** \brief Funci&oacute;nn interfaz para captura manual de vectores.
     *
     * \return void
     *
     */
    void Capturar();

    /** \brief Funci&oacute;n que realiza la suma de dos vectores
     *
     * \param v Vector
     * \return Vector vector resultante.
     *
     */
    //Vector Sumar(Vector v) const;

    /** \brief Funci&oacute;n que realiza la resta de dos vectores
     *
     * \param v Vector
     * \return Vector vector resultante.
     *
     */
    Vector Resta(Vector v) const;

    /** \brief Funci&oacute;n que opera la multiplicaci&oacute;n de un vector por un escalar.
     *
     * \param escalar double escalar para la multiplicaci&oacute;n
     * \return Vector vector resultante.
     *
     */
    Vector operator*(double escalar) const;

    /** \brief Funcion que calcula la magnitud de dos vectores
     *
     * \return double el resultado de la magnitud.
     *
     */
    double ObtenerMagnitud() const;

    Vector operator+(Vector v) const;

    Vector & operator=(const Vector &v);


private:
    int dimension;
    //double componente[MAXDIM];
    double *componente;

};

void operator<<(std::ostream &fsalida, const Vector &v);

#endif // VECTOR_H_INCLUDED

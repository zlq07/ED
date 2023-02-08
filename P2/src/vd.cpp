#include <cassert>

// Cambio del tamaño del vector dinamico
template <class T>
void VD<T>::resize(int tam)
{
    T *aux = new T[tam];
    int min_copia = (tam < n) ? tam : n;
    for (int i = 0; i < min_copia; i++)
        aux[i] = datos[i];
    reservados = tam;
    n = min_copia;
    delete[] datos;
    datos = aux;
}

// copias de la clase
template <class T>
void VD<T>::copiar(const VD<T> &v)
{
    reservados = v.reservados;
    n = v.n;
    datos = new T[reservados];
    for (int i = 0; i < n; i++)
        datos[i] = v.datos[i];
}

// liberar la clase
template <class T>
void VD<T>::liberar()
{
    if (datos != nullptr)
        delete[] datos;
}

// Constructor 
template <class T>
VD<T>::VD(int tam)
{
    reservados = tam;
    n = 0;
    if (tam > 0)
        datos = new T[reservados];
    else
        datos = nullptr;
}

// Constructor de copia
template <class T>
VD<T>::VD(const VD<T> &v)
{
    copiar(v);
}

// Operador +
template <class T>
VD<T> &VD<T>::operator=(const VD<T> &v)
{
    if (this != &v)
    {
        liberar();
        copiar(v);
    }
    return *this;
}

// Destructor 
template <class T>
VD<T>::~VD()
{
    liberar();
}

template <class T>
int VD<T>::size() const
{
    return n;
}

// Operador []
template <class T>
T &VD<T>::operator[](int i)
{
    assert(i >= 0 && i < n);
    return datos[i];
}

template <class T>
const T &VD<T>::operator[](int i) const
{
    assert(i >= 0 && i < n);
    return datos[i];
}

// Metodo insertar
template <class T>
void VD<T>::insert(int pos, const T &d)
{
    assert(pos >= 0 && pos <= n);
    if (n == reservados)
        resize(2 * reservados);
    for (int i = n; i > pos; i--)
        datos[i] = datos[i - 1];
    datos[pos] = d;
    n++;
}

// metodo eliminar
template <class T>
void VD<T>::erase(int pos)
{
    assert(pos >= 0 && pos < n);
    for (int i = pos; i < n - 1; i++)
        datos[i] = datos[i + 1];
    n--;
    if (n < reservados / 4) // siempre tenemos el doble de espacio pero no mas
        resize(reservados / 2);
}

template <class T>
void VD<T>::clear()
{
    n = 0;
}

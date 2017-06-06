#include "Problema.h"
#include <fstream>
#include <iostream>

using namespace std;


Problema::Problema() {
    N= 0;
    V= 0;
}

Problema::Problema(const Problema & p) {
    N= 0;
    V= 0;
    *this= p;
}

Problema & Problema::operator=(const Problema &p) {
    if (&p == this) // Para evitar cosas como mivariables= mivariables
        return *this;
    if (N > 0)  // Liberar la memoria previa
        delete [] v;
    V= p.V;
    N= p.N; // Reserva de memoria nueva si es necesario y copia
    if (N>0) {
        v= new double[N];
        for (unsigned int i= 0; i<N; i++)
            v[i]= p.v[i];
    }
    return *this;
}

Problema::~Problema() {
    if (N!= 0)
        delete [] v;
}

int Problema::getNumObjetos() {
    return (int)N;
}

double Problema::getVolumen() {
    return V;
}

double Problema::getVolumen(int i) {
    return v[i];
}

bool Problema::cargarDesdeFlujo(const char *nombreFichero) {

    /*
        Formato del fichero
        Línea 1: Volumen de cada embalaje
        Línea 2: Número de objetos a insertar
        En las demás líneas están los volúmenes de cada objeto (uno por línea)
        Ver ejemplo: Problema.dat
    */

    // Liberar memoria si la hubiese
    if (N!= 0)
        delete [] v;

    // Inicializar a problema vacío
    N= 0;
    V= 0;

    ifstream fichero;

    fichero.open( nombreFichero );
    if ( !fichero )
        return false;

    fichero >> V;
    fichero >> N;

    if (V<=0 || N<=0) {
        fichero.close();
        N= 0;
        return false;
    }

    // Reserva de la memoria para el "N" nuevo
    v= new double[N];

    // Leemos volúmenes
    for (unsigned int i= 0; i<N; i++)
        fichero >> v[i];

    fichero.close();

    return true;
}

void Problema::prettyPrint(){
  cout << "Volumen máximo de una caja: " << V << '\n';
  for (size_t i = 0; i < N; i++) {
    cout << "Objeto " << i << ": " << v[i] << '\n';
  }
}

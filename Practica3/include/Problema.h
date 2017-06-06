#ifndef PROBLEMA_H
#define PROBLEMA_H

using namespace std;

class Problema {

    private:

    double V;           // Volumen de los embalajes
    unsigned int N;     // Número de objetos
    double *v;          // Volumenes de los N objetos

    public:

    Problema();
    Problema(const Problema & p);
    Problema & operator=(const Problema &p);
    ~Problema();

    int getNumObjetos();    // Devuleve el número total de objetos
    double getVolumen();    // Devuelve el volumen máximo de una caja
    double getVolumen(int i);   // Devuelve el volumen del objeto i
    bool cargarDesdeFlujo(const char *nombreFichero);   // Lee el problema desde un fichero
    void prettyPrint();   // Imprime el problema en un formato legible

};

#endif // PROBLEMA_H

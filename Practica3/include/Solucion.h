#ifndef SOLUCION_H
#define SOLUCION_H

#include "Problema.h"
#include <vector>

class Solucion
{
    private:

    vector<vector<pair<int,double> > > posiciones;  // Vector de cajas

    public:

    int getNumCajas();    // Devuelve el total de cajas usadas
    void addCaja();       // Crea una nueva caja vacía
    void addObjeto(int pos, pair<int, double> obj);   // Añade el objeto obj a la caja pos
    double getVolumen(int pos);   // Devuleve el volumen ocupado en la caja pos
    vector<pair<int, double> > getObjetos(int caja);    // Devuleve los objetos que hay en la caja

};

#endif

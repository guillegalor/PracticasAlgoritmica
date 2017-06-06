#include "Solucion.h"

int Solucion::getNumCajas() {
    return posiciones.size();
}

void Solucion::addObjeto(int pos, pair<int, double> obj) {
    posiciones[pos].push_back(obj);
}

void Solucion::addCaja(){
    posiciones.resize(posiciones.size()+1);
}

double Solucion::getVolumen(int pos) {
    double vol = 0;
    for(unsigned i=0; i<posiciones[pos].size(); i++)
        vol += (posiciones[pos][i]).second;
    return vol;
}

vector<pair<int, double> > Solucion::getObjetos(int caja){
    return posiciones[caja];
}

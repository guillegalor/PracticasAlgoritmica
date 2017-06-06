#include "Algoritmos.h"
#include <iostream>
#include <vector>

using namespace std;


Solucion AlgorimoGreedyBinPacking(Problema p){
  Solucion S;
  vector<pair<int,double> > candidatos(p.getNumObjetos());

  //Inicializamos lista de candidatos
  for (int i = 0; i < p.getNumObjetos(); i++) {
    candidatos[i].first = i;
    candidatos[i].second = p.getVolumen(i);
  }
  // Añadimos la primera caja
  S.addCaja();

  //Mientras queden objetos sin incluir en cajas
  while (!candidatos.empty()) {
    //Funcion de seleccion (elemento con el máximo volumen)
    vector<pair<int, double> >::iterator it, sol;
    pair<int, double> max(-1,0);

    for (it = candidatos.begin(); it != candidatos.end(); it++) {
      if (max.second < it->second) {
        max = *it;
        sol = it;
      }
    }

    //Eliminamos el objeto elegido de la lista de candidatos
    candidatos.erase(sol);

    //Incluimos el objeto elegido en la solucion
    bool add = false;
    for (int i = 0; i < S.getNumCajas() && !add; i++) {
      //Si el objeto cabe en una caja existente, lo incluimos y salimos del bucle
      if (S.getVolumen(i) + max.second <= p.getVolumen()){
        S.addObjeto(i,max);
        add = true;
      }
    }
    //Si no, creamos una caja nueva y añadimos el objeto
    if(!add){
      S.addCaja();
      S.addObjeto(S.getNumCajas()-1, max);
    }
  }

  return S;
}

#include <iostream>
#include "Problema.cpp"
#include "Solucion.cpp"
#include "Algoritmos.cpp"
#include <vector>

using namespace std;

int main() {

    Problema prob;
    Solucion sol;

    if(!prob.cargarDesdeFlujo("Problema.dat"))
        cout << "El fichero no se puede abrir" << endl;

    cout << "PROBLEMA: " << endl;
    prob.prettyPrint();

    // Resolvemos con algoritmo greedy
    sol = AlgorimoGreedyBinPacking(prob);

    // Mostramos la solución
    cout << "\nSOLUCION: " << endl;
    vector<pair<int,double> > objetos;
    vector<pair<int,double> >::iterator it;
    cout << "Número de cajas -> " << sol.getNumCajas() << endl;
    cout << "Contenido de las cajas (objeto->volumen)" << endl;
    for(int i=0; i < sol.getNumCajas(); i++){
        cout << "Caja " << i << ": ";
        objetos = sol.getObjetos(i);
        for(it=objetos.begin(); it!=objetos.end(); it++){
            cout << it->first << "->" << it->second << " ";
        }
        cout << endl;
    }
}

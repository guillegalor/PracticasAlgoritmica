#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

#define ALGORITMO 2

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}


// Resolución del problema mediante un algoritmo de fuerza bruta
int fuerzabruta(int *v, int n){
  int inversiones = 0;
  bool encontrado1 = false;
  bool encontrado2 = false;
  int posi, posj;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      for(int k=0; k<n && (!encontrado1 || !encontrado2); k++){
        if(v[k] == i){
          posi = k;
          encontrado1 = true;
        }

        if(v[k] == j){
          posj = k;
          encontrado2 = true;
        }

      }
      encontrado2 = false;
      encontrado1 = false;
      if(posi > posj)
        inversiones ++;
    }
  }

  return inversiones;

}

// Resolucion del problema mediante el algoritmo Divide y Venceras
int DyV(int *v, int n){
    int inversiones = 0;

    if (n == 1){
        return inversiones;
    }

    int tam = n/2;

    for (int i = 0; i < tam; i++){
        for (int j = tam; j< n; j++){
            if (v[i] > v[j])
                inversiones++;
        }
    }

    inversiones += DyV(v, tam);
    inversiones += DyV(v+tam, n-tam);
    return inversiones;
}


int main(int argc, char * argv[])
{

    double tiempo;
    clock_t tantes, tdespues;
  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

srand(time(0));

for (int j=0; j<n; j++) T[j]=j;
//for (int j=0; j<n; j++) {cout << T[j] << " ";}
//cout <<endl;

//algoritmo de random shuffling the Knuth (permutaci�n aleatoria)
for (int j=n-1; j>0; j--) {
   double u=uniforme();
   int k=(int)(j*u);
   int tmp=T[j];
   T[j]=T[k];
   T[k]=tmp;
}

//for (int j=0; j<n; j++) {cout << T[j] << " ";}
//cout << endl;

#if ALGORITMO == 1
    tantes = clock();
    fuerzabruta(T,n);
    tdespues = clock();

#else
    tantes = clock();
    cout << DyV(T,n);
    tdespues = clock();
#endif // ALGORITMO

tiempo = ((double)(tdespues-tantes)/CLOCKS_PER_SEC);

delete[] T;
cout << n << "\t" << tiempo << endl;
}

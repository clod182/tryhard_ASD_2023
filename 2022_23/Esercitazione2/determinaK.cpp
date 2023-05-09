#include <iostream>
#include <vector>
#include <algorithm>
#include "funzioniMie.h"

using namespace std;

/* #region funzione es */
vector<int> determinaK(const vector<int>& arr, int n, int k) //un vettore "const" non posso ordinarlo
{
  cout << "\n ----    determinaK  ----";

  /*int l = n-k;
  int min_int = n*n +1;
  int max_int = n*n +n;
  bool flag = false;
  vector<int> ret;

  for (int j = min_int; j <= max_int; j++){    
    int valorAtm = -1;
    for(int i = 0; i < arr.size(); i++){
      if(arr[i] == j){
        flag = true;
      }
    }
    if (flag == false){
        ret.push_back(j);
    }   
    flag = false;    
  }*/
  vector<bool> occ(n, false); //vettore delle occorrenze di dimensione n e con tutte le celle a false.
  vector<int> ris;
  size_t i{0};
  //viene sfruttata l’ipotesi riguardo l’intervallo di numeri naturali. Il minimo valore e’ n*n+1
  int min = n * n + 1;
  for (size_t j=0; j< arr.size(); j++)
      occ[arr[j] - min] = true; //viene utilizzato true per indicare i valori presenti in arr
  while (k > 0){
      if (!occ[i]){
          ris.push_back(i + min); //vengono inseriti in ris solo gli elementi non contenuti in arr
          k--; 
      }
      i++; 
  }

  myPrintVector(arr); //WIP to delete
  myPrintVector(ris); //WIP to delete
  return ris;
}

/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n * m)" con m numero di elementi dell'array.
Il primo ciclo for ha una complessità di "O(n)" data dal suo iterare gli elementi da min_int a max_int.
Il secondo ciclo for ha una complessità di "O(m)" data dal suo iterare gli elementi del vettore di input.
All'interno del secondo ciclo è presente un confronto che però ha ovviamente complessità costate "O(1)".

Quindi la complessità totale della funzione sarà "O(n)" * "O(m)" --> "O(n * m)"
-------------------------------------------------------------------------------------------------------- */
/* #endregion funzione es */

/* #region MAIN DI PROVA */
int main() {

  vector<int> vect{55, 50, 56};
  vector<int> final = determinaK(vect, 7, 4);
  return 0;
}
/* #endregion MAIN DI PROVA */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* #region funzione es */
vector<int> determinaK(const vector<int>& arr, int n, int k){

  int l = n-k;
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
  }
  return ret;
}

/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n * m)" con m numero di elementi dell'array.
Il primo ciclo for ha una complessità di "O(n)" data dal suo iterare gli elementi da min_int a max_int.
Il secondo ciclo for ha una complessità di "O(m)" data dal suo iterare gli elementi del vettore di input.
All'interno del secondo ciclo è presente un confronto che però ha ovviamente complessità costate "O(1)".

Quindi la complessità totale della funzione sarà "O(n)" * "O(m)" --> "O(n * m)"
-------------------------------------------------------------------------------------------------------- */
/* #endregion funzione es */
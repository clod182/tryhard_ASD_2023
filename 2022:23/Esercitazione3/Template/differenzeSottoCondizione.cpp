#include <iostream>
#include <vector>
#include <algorithm>
#include "funzioniMie.h"
using namespace std;

/* #region funzioni ausiliarie es */

/* #endregion funzioni ausiliarie es */

/* #region funzione es */
void differenzeSottoCondizione(vector<int>& arr){
    int n = arr.size();
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    int diff = max_val - min_val;
    if (diff >= n) {
        Quicksort(arr, 0, n-1);
        return;
    }
    // Ordina solo gli elementi intermedi di arr in ordine decrescente
    Quicksort(arr, 1, n-2);
    // Riordina i due elementi estremi se necessario
    if (arr[0] != min_val) {
        swap(arr[0], arr[find(arr.begin(), arr.end(), min_val) - arr.begin()]);
    }
    if (arr[n-1] != max_val) {
        swap(arr[n-1], arr[find(arr.begin(), arr.end(), max_val) - arr.begin()]);
    }

    //WIP aggiungere funzione di QuickSort
}

/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n log n)" e con n numero di elementi del vettore.

Quindi la complessità totale della funzione sarà dominata dalla complessità della funzione di ordinamento 
avendo come complessità totale --> "O(n log n)".
-------------------------------------------------------------------------------------------------------- */
/* #endregion funzione es */

/* #region MAIN DI PROVA */
int main(){
    std::cout << "ES1 *** ESERCITAZIONE 3 \n";

    vector<int> vect{1, 6, 5, 2, 4, 3}; //(diff max e min = 5) < (n=6) 
    std::cout << "Vettore pre --> \n";
    myPrintVector(vect);

    differenzeSottoCondizione(vect);
    
    std::cout << "Vettore post --> \n";
    myPrintVector(vect);

    return 0;
}
/* #endregion MAIN DI PROVA */
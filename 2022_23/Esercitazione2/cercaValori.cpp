#include <iostream>
#include <vector>
#include <algorithm>
#include "funzioniMie.h"

using namespace std;

//#region funzioni ausiliarie

vector<int> mySortVector(vector<int> &vect){
    vector<int> ret;
    //todo
    return ret;
}

//#endregion funzioni ausiliarie

/* #region funzione es */
vector<int> cercaValori(vector<int>& arr, int k){

    cout << "\n ----    cercaValori  ----";

    vector <int> ret;

    /*ordino l'array di partenza in ordine crescente*/
    /*da decidere quale algoritmo tenere, per ora uso quick*/

    Quicksort(arr, 0 ,arr.size()-1);
    int pointer = 0;
    int count = 0;
    int l = arr.size() / k;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == arr[pointer]){
            count ++;
            if(i == arr.size()-1){ //caso in cui sono all'ultimo elemento e fà sempre parte della serie di num uguali
                if(count >= l) {
                    ret.push_back(arr[pointer]);
                } 
            }
        }
        else {
            if(count >= l) {
                ret.push_back(arr[pointer]);
            }
            count = 1;
            pointer = i;
        }
    }
    return ret;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O((n log n) * n)" e con n numero di elementi del vettore.
L'ordinamento del vettore di input tramite Quicksort ha una complessità di "O(n log n)".
Il ciclo for ha una complessità di "O(n)" perchè itera tutti gli elementi dell'array.
Quindi la complessità totale della funzione sarà "O(n log n)" + "O(n)" --> "O((n log n) * n)".
-------------------------------------------------------------------------------------------------------- */

/* #endregion funzione es */

/* #region MAIN DI PROVA */
int main(){

    vector<int> vect{43, 3, 8, 43, 1, 9, 9, 7};
    vector<int> final = cercaValori(vect, 4);

    myPrintVector(vect);
    myPrintVector(final);

    return 0;
}
/* #endregion MAIN DI PROVA */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* #region domande es */
/*
    1)Nelle prime due posizioni del vettore dovranno essere spostati rispettivamente l'elemento più grande e quello più piccolo del vettore.
*/
/* #endregion domande es */

/* #region funzioni ausiliarie es */

//#region Quicksort


// last element is taken as pivot
int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]>v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

//#endregion Quicksort

void differenzeAux(vector<int>& arr){

    Quicksort(arr, 0, arr.size()-1); //complessità di O(n log n)
    vector<int> arr_copy(arr.size());
    for (int i=0; i<arr.size(); i++){
        arr_copy[i] = arr[i];
    }
    int i=0; 
    int j=arr.size()-1;
    int k = 0;
    while (k < arr.size()){
        if (k%2 == 0){
            arr[k]=arr_copy[i];
            i ++;
        }
        else {
            arr[k] = arr_copy[j];
            j --;
        }
        k++;
    }
}
/* #endregion funzioni ausiliarie es */

/* #region funzione es */
void differenze(vector<int>& arr){  

    //differenzeAux_old(arr, 0);
    differenzeAux(arr);
    
}

/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n log n)" e con n numero di elementi del vettore.
Le funzione per ordinare il vettore Quick sort ha complessità "O(n log n)".
Il ciclo usato per fare una copia del vettore ha una complessità di "O(n)" perchè bisona comunque iterare 
tutto il vettore di input.
L'ultima parte della funzione, usata per "modificare" il vettore di input nel modo desiderato ha sempre
complessità O(n) perchè bisogna scorrerlo tutto di nuovo.
Quindi la complessità totale della funzione sarà dominata dalla complessità della funzione di ordinamento 
avendo come complessità totale --> "O(n log n)".
-------------------------------------------------------------------------------------------------------- */
/* #endregion funzione es */
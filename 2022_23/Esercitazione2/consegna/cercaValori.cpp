#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//#region funzioni ausiliarie

//#region Quicksort
int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
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

//#endregion funzioni ausiliarie

/* #region funzione es */
vector<int> cercaValori(vector<int>& arr, int k){

    vector <int> ret;

    Quicksort(arr, 0 ,arr.size()-1);
    int pointer = 0;
    int count = 0;
    int l = arr.size() / k;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == arr[pointer]){
            count ++;
            if(i == arr.size()-1){
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
#include <iostream>
#include <vector>
#include <algorithm>
#include "esercizioCodaMaxPriorita.cpp"

/* #region testo es */
/*
    Uilizzando le funzioni dello scorso es, realizzare la funzione differenza che dati 2 MaxHeap conteneti
    interi (anche ripetuti) ritorna in output un nuovo maxHeap contenente la differenza.
    Se x compare k1 volte in H1 e  k2 volte in H2, nel maxHeap finale dovrà comparire max (0, k1-k2).
*/
/* #endregion testo es */

/* #region funzione es */

/* #region funzioni ausiliarie es */

/* #endregion funzioni ausiliarie es */

void differenza(MaxHeap& h1, MaxHeap& h2, MaxHeap& hris){

  while(h1.heapEmpty() == false || h2.heapEmpty() == false){
    if(h1.heapEmpty() == false && h2.heapEmpty() == false) /* 2 heap con elementi */
    {
      int valAtm = h1.heapExtractMax();
      int x = h2.heapSearch(valAtm);  
      if (x == -1) { /* se non lo trovo, lo inserisco */
        hris.heapInsert(valAtm);      
      }
      else{ /* altrimenti non lo inserisco e lo elimino anche da h2 */
        h2.heapDelete(x);
      } 
    }

    else if(h1.heapEmpty() == true && h2.heapEmpty() == false) /* h2 heap con elementi */
    {
      int valAtm = h2.heapExtractMax();    
      hris.heapInsert(valAtm); 
    }

    else if(h2.heapEmpty() == true && h1.heapEmpty() == false) /* h1 heap con elementi, unico caso in cui dovrebbe entrare qui è quando h2 è vuoto in partenza */
    {
      int valAtm = h1.heapExtractMax();    
      hris.heapInsert(valAtm); 
    }
  }
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "" con n numero .
-------------------------------------------------------------------------------------------------------- */

/* #endregion funzione es */

/* #region MAIN DI PROVA */
int main() {

  vector<int> vect1{10, 20, 25, 6, 12, 15, 4, 16};  
  //vector<int> vect1{10, 10, 10, 41};  
  MaxHeap MaxHeap_created1(vect1);  
  cout << "Heap 1 is ------------------ \n";
  MaxHeap_created1.mySimplePrintMaxHeap(0,0);

  vector<int> vect2{4,8,14,9,17,18,20,6,33,12};  
  //vector<int> vect2{10,10};  
  MaxHeap MaxHeap_created2(vect2);  
  cout << "Heap 2 is ------------------ \n";
  MaxHeap_created2.mySimplePrintMaxHeap(0,0);

  //TEST
  //int xd = MaxHeap_created2.heapSearch(12);

  MaxHeap test_heap;
  differenza(MaxHeap_created1, MaxHeap_created2, test_heap);

  cout << "Heap FINALE is ------------------ \n";
  test_heap.mySimplePrintMaxHeap(0,0);
 
  return 0;
}
/* #endregion MAIN DI PROVA */
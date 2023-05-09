#include "maxheap.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

struct MaxHeap::Impl{
  vector<int> elements;
  size_t heapsize;
};


/* Post: Restituisce il padre di i se i non e' la radice, altrimenti -1
*/
int parent(size_t i){
  return (i-1)/2;
}

size_t left(size_t i){
  return (2*i + 1);
}

size_t right(size_t i){
  return (2*i + 2);
}

void MaxHeap::maxHeapify(size_t i){
  size_t size = pimpl->heapsize;
  size_t l = left(i);
  size_t r = right(i);
  size_t max = i;

  if (l < size && pimpl->elements[l] > pimpl->elements[max])
    max = l;
  if (r < size && pimpl->elements[r] > pimpl->elements[max])
    max = r;
  if (max != i){
    swap(pimpl->elements[i], pimpl->elements[max]);
    maxHeapify(max);
  }
}
/* --------------------------------------------------------------------------------------------------------
La complessità di parent, left e right è ovviamente costante e quindi "O(n)".

La complessità di questa funzione è "O(log n)" con n numero di nodi dell'heap, 
la funzione viene chiamata ricorsivamente nei nodi dell'heap e ad ogni passata confronta i valori del nodo
con quelli dei figli e li scambia se opportuno. L'altezza dell'albero è "log n" e nel peggiore dei casi la 
funzione deve attraversarlo tutto. 
Ad ogni livello dell'albero la funzione richiede "O(1)" tempo per il confronto e lo scambio dei valori
quindi la complessità totale è --> "O(log n)".
-------------------------------------------------------------------------------------------------------- */

/*post: restituisce un Max Heap vuoto (heapsize = 0) */
MaxHeap::MaxHeap(){
  pimpl->heapsize = 0;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*post: trasforma il vettore arr in un Max Heap   */
MaxHeap::MaxHeap(vector<int>& arr){
  pimpl = new Impl;
  pimpl->elements = arr;
  pimpl->heapsize = arr.size();
  for (int i = pimpl->heapsize/2 -1; i >= 0; i--) { //for (size_t i = pimpl->heapsize/2; i != (size_t)-1; i--) {
    maxHeapify(i);
  }
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n log n)" con n dimensione del vettore di input.
Il costruttore copia gli elementi del vettore nell'heap con tempo "O(n)".
Poi viene chiamata la funzione maxHeapify che scorre l'heap dall'ultimo nodo non foglia fino alla radice.
Dato che maxHeapify() ha una complessità di "O(log n)" 
la complessità totale sarà --> "O(n) + O(log n)" = "O(n log n)"
-------------------------------------------------------------------------------------------------------- */

/*post: rimuove il Max Heap ternario
 */
MaxHeap::~MaxHeap(){
  //WIP todo
}
 
/*post: restituisce true se lo heap e' vuoto, false altrimenti */
bool MaxHeap::heapEmpty() const{
  if(pimpl->heapsize == 0) return true;
  else return false;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*pre: lo heap e' non vuoto */
/*post: restituisce la chiave piu' grande nello Heap */
int MaxHeap::heapMaximum() const{
  return pimpl->elements[0];
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*pre: lo heap e' non vuoto */
/*post: restituisce la chiave piu' piccola nello Heap */
int MaxHeap::heapMinimum() const{
  return pimpl->elements[pimpl->heapsize - 1];
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*pre: lo heap e' non vuoto */
/*post: elimina e restituisce la chiave piu' grande nello heap. */
int MaxHeap::heapExtractMax(){

  int ret = heapMaximum();

  swap(pimpl->elements[pimpl->heapsize-1], pimpl->elements[0]);
  pimpl->elements.pop_back(); 
  pimpl->heapsize --;

  maxHeapify(0);

  return ret;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(log n)" con n numero di nodi nell'albero.
Fare lo swap dei due elementi è una operazione di tempo costante e quindi di complessità "O(1)".
Poi usare la funzione maxHeapify dalla radice ha una complessità di "O(log n)", quind
la complessità totale è --> "O(log n)"
-------------------------------------------------------------------------------------------------------- */

/*post: inserisce l'elemento con chiave k nello heap */
void MaxHeap::heapInsert(int k){
 pimpl->elements.push_back(k); //pimpl->element[pimpl->heapsize + 1] = k;
 pimpl->heapsize ++;

 //maxHeapify(0); //sarebbe andato bene fare direttamente un maxHeapify dalla radice?
 int i = pimpl->heapsize-1;
 while (i > 0 && pimpl->elements[parent(i)] < pimpl->elements[i]) {
      swap(pimpl->elements[i], pimpl->elements[parent(i)]);
      i = parent(i);
    }    
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(log n)" con n numero dei nodi nell'albero.
Inserire l'elemento alla fine del vettore è un'operazione costante di tempo O(1).
Poi dobbiamo andare a ciclare e scambiare i nodi quando serve per ripristinare le proprietà del maxHeap 
scorrendo come caso peggiore tutto l'albero di altezza "log n", quindi il ciclo verrà eseguito al massimo
"log n" volte dando così una complessità totale alla funzione di --> "O(log n)".
-------------------------------------------------------------------------------------------------------- */

/* cancella l'elemento in poszione i dello Heap */
void MaxHeap::heapDelete(size_t i){
  swap(pimpl->elements[pimpl->heapsize-1], pimpl->elements[i]);
  pimpl->elements.pop_back();
  pimpl->heapsize --;

  maxHeapify(i);
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(log n)" con n numero di nodi dell'heap, 
Nel peggiore dei casi l'altezza dell'albero è "log n" e questa determina il numero di volte
per la quale viena chiamata ricorsivamente la funzione maxHeapify(). Ogni sua chiamata richiede tempo "O(1)"
quindi la complessità totale è --> "O(log n)"
-------------------------------------------------------------------------------------------------------- */

int MaxHeap::auxSearch(int k, size_t node) const{
  if(node > (pimpl->heapsize-1)){
    return -1;
  }

  if(pimpl->elements[node] == k){
    return node;
  }

  int l = auxSearch(k, left(node));
  if (l =! -1){
    return l;
  }

  int r = auxSearch(k, right(node));
  if (r =! -1){
    return r;
  }
}

/*post: restituisce la posizione dello heap che contiene k se k e' nello heap altrimenti -1 */
int MaxHeap::heapSearch(int k) const{
  return auxSearch(k, 0);
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" con n numero di nodi dell'heap.
Nella peggiore delle ipotesi la funzione deve scorrere tutti i nodi e, nel caso non trovasse la chiave nell'abero,
ritornare -1.
Quindi nel peggiore dei casi la complessità totale è --> "O(n)" (nel migliore dei casi sarà sempre "O(log n)" come
nelle funzioni precedenti).
-------------------------------------------------------------------------------------------------------- */
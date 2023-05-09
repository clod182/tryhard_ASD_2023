#include "dizionario.hpp"
#include <vector>
#include <iostream>

constexpr int hashsize = 8;
constexpr int hashaux = 5;

using namespace std;

struct Elem{
    int key;
    int info;
    //WIP add elements?
};

/* DEL e' un elemento fittizio che rappresenta un elemento cancellato */
struct Dizionario::Impl{
  vector<PElem> content;
  int numchiavi;
  PElem DEL;
};

int funHash(int val, int i){
  return (val%hashsize + i*(1+2*(val%hashaux)))%hashsize;
}

/* --------------------------------------------------------------------------------------------------------
   --------------------------------------------------------------------------------------------------------
NB: Con "aplha" si intende il fattore di carico della tabella tabella hash, dato da 
= (numero elementi memorizzati)/(dimensione della tabella hash)
-------------------------------------------------------------------------------------------------------- 
-------------------------------------------------------------------------------------------------------- */

/*post: costruisce un dizionario vuoto */
Dizionario::Dizionario(){
  pimpl = new Impl();
  pimpl->content.resize(hashsize, nullptr);
  pimpl->numchiavi = 0;
}    
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante. Sia caso medio che caso peggiore.
-------------------------------------------------------------------------------------------------------- */

/*post: rimuove il dizionario */
Dizionario::~Dizionario(){
  for (int i = 0; i < hashsize; ++i){
    PElem current = pimpl->content[i];
    delete current;
  }
  delete pimpl;
}    
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize nel caso 
peggiore ed anche nel caso medio perchè per eliminare il tutto devo in ogni caso scorrere tutto il vettore
ed eliminare gli "slot" presenti.
-------------------------------------------------------------------------------------------------------- */

/*pre: k non e' presente nel dizionario*/
/*post: associa il valore val alla chiave k nel dizionario*/
void Dizionario::inserisci(int k, int val){
  bool insered = false;
  for (int i=0; i<hashsize & insered==false; i++){
    int hash_value = funHash(k, i);
    if(pimpl->content[hash_value] == nullptr){
      PElem elem = new Elem();
      elem->key = k;
      elem->info = val;
      pimpl->content[hash_value] = elem;
      pimpl->numchiavi++;
      insered = true;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize nel caso 
peggiore. Nel caso medio, assumendo vi sia una buona funzione hash che distribuisce bene gli elementi del
dizionario nel vettore, la complessità è costante e quindi "O(1 + alpha)" dato che il numero medio di posizioni
da verificare prima di trovarne una libera è costante.
-------------------------------------------------------------------------------------------------------- */

/*pre: l'elemento x e' contenuto nel dizionario*/
/*post: rimuove l'elemento x dal dizionario */
void Dizionario::cancella(PElem x){
  bool deleted = false;
  for(int i=0; i<hashsize & deleted == false; i++){
    int hash_value = funHash(x->key, i);
    PElem current = pimpl->content[hash_value];
    if(current == x){     
      delete current; //WIP setta a 0,0 ma non calcella ??
      pimpl->numchiavi --;
      deleted = true;
    }
  }
 }    
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize nel caso 
peggiore. Nel caso medio, assumendo vi sia una buona funzione hash che distribuisce bene gli elementi del
dizionario nel vettore, la complessità è costante e quindi "O(1 + alpha)" dato che il numero medio di posizioni
da verificare prima di trovare l'elemento da eliminare è costante.
-------------------------------------------------------------------------------------------------------- */

/*post: restituisce un elemento con chiave k se esiste, nullptr altrimenti */
PElem Dizionario::cerca(int k){
  for(int i=0; i<hashsize; i++){
    int hash_value = funHash(k, i);
    PElem current = pimpl->content[hash_value];
    if(pimpl->content[hash_value] && pimpl->content[hash_value]->key == k){
      return current;
    }
  }
  return nullptr;
 }   
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize nel caso 
peggiore. Nel caso medio, assumendo vi sia una buona funzione hash che distribuisce bene gli elementi del
dizionario nel vettore, la complessità è costante e quindi "O(1 + alpha)" dato che il numero medio di posizioni
da verificare prima di trovare l'elemento cercato è costante. 
-------------------------------------------------------------------------------------------------------- */

/*post: restituisce il numero di chiavi nel dizionario*/
int Dizionario::numChiavi(){
  return pimpl->numchiavi;
}
 /* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce la chiave di x*/
int Dizionario::leggiChiave(PElem x){
  return x->key;
}
 /* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*pre: l'elemento x e' contenuto nel dizionario */
/*post: restituisce il valore di x*/
int Dizionario::leggiInfo(PElem x){
    return x->info;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante.
-------------------------------------------------------------------------------------------------------- */

/*post: stampa il contenuto del dizionario */
void Dizionario::stampa(){
  for (int i=0; i<hashsize; i++){
    PElem current = pimpl->content[i];
    if (current){
      cout << current->key << ": " << current->info << endl;    
    }
  }
}    
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize del vettore nel caso 
peggiore.
Nel caso medio la complessità diventa "O(n/m)" dove n sono il numero di elementi effetivamente
presenti nel dizionario ed m la dimensione del vettore
-------------------------------------------------------------------------------------------------------- */

int main(){
  Dizionario mainDict;
  mainDict.inserisci(10, 10);
  mainDict.inserisci(66, 66);
  mainDict.inserisci(71, 71);
  mainDict.inserisci(157, 157);

  mainDict.stampa();

  PElem toBeDeleted = mainDict.cerca(10);
  mainDict.cancella(toBeDeleted);

  PElem testCerca = mainDict.cerca(157);
  cout << "Elemento cercato --> " + to_string(testCerca->key) + "\n"; 
  mainDict.inserisci(31, 31);

  mainDict.stampa();

  return 0;
}

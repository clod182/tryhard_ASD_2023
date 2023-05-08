#include "dizionario.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <string> 

constexpr int hashsize = 8;

using namespace std;

struct Elem{
    int key;
    int info;
    PElem next;
};

struct Dizionario::Impl{
  vector<PElem> content;
  int numchiavi;
};


int funHash(int val){
  return val%hashsize;
}

/*post: costruisce un dizionario vuoto */
Dizionario::Dizionario(){
  pimpl = new Impl();
  pimpl->content.resize(hashsize, nullptr);
  pimpl->numchiavi = 0;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante. Sia caso medio che caso peggiore.
-------------------------------------------------------------------------------------------------------- */

/*post: rimuove il dizionario*/
Dizionario::~Dizionario(){
  for (int i = 0; i < hashsize; ++i)
  {
    PElem current = pimpl->content[i];
    while (current)
    {
      PElem next = current->next;
      delete current;
      current = next;
    }
  }
  delete pimpl;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize nel caso medio
assumendo vi sia una buona funzione hash che mantiene otimizzato l'heap.

Nel caso peggiore la complessità potrebbe diventare "O(n^2)" ipotizzando che tutti gli elementi siano riposti
nello stesso indice del vettore della tabella hash. Tuttavia nella pratica la tabella hash dovrebbe aver distribuiti
tutti gli elementi in maniera bilanciata tra gli indici del vettore portando ad una complessità media decisamente
più efficiente di "O(n)".
-------------------------------------------------------------------------------------------------------- */

/*pre: k non e' presente nel dizionario*/
/*post: associa il valore val alla chiave k nel dizionario*/
void Dizionario::inserisci(int k, int val){
  int hash_value = funHash(k);
  PElem elem = new Elem();
  elem->key = k;
  elem->info = val;
  elem->next = pimpl->content[hash_value];
  pimpl->content[hash_value] = elem;

  pimpl->numchiavi++;
}   
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante nel caso medio.

Nel caso peggiore la complessità potrebbe diventare "O(n)" con n numero massimo di elementi che possono 
essere concatenati assieme nello stesso indice del vettore della tabella hash. 
-------------------------------------------------------------------------------------------------------- */

/*pre: l'elemento x e' contenuto nel dizionario*/
/*post: rimuove l'elemento x dal dizionario */
void Dizionario::cancella(PElem x){
  int hash_value = funHash(x->key);
  PElem current = pimpl->content[hash_value];
  PElem prev = nullptr;

  while(current){
    if (current == x){
      if (prev){
        prev->next = current->next;
      }
      else{
        pimpl->content[hash_value] = current->next;
      }
      delete current;
      pimpl->numchiavi --;
      break; 
    }
    prev = current;
    current = current->next;
  }
}    
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante nel caso medio assumendo vi sia una buona 
funzione hash.

Nel caso peggiore la complessità potrebbe diventare "O(n)" con n numero massimo di elementi che possono 
essere concatenati assieme nello stesso indice del vettore della tabella hash. 
-------------------------------------------------------------------------------------------------------- */

/*post: restituisce un elemento con chiave k se esiste, nullptr altrimenti */
PElem Dizionario::cerca(int k){
  int hash_value = funHash(k);
  PElem current = pimpl->content[hash_value];

  while(current){
    if (current->key == k){
      return current;
    }
    else{
      current = current->next;
    }
  }
  return nullptr;
}   
 /* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(1)" e quindi costante nel caso medio assumendo vi sia una buona 
funzione hash.

Nel caso peggiore la complessità potrebbe diventare "O(n)" con n numero massimo di elementi che possono 
essere concatenati assieme nello stesso indice del vettore della tabella hash. 
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
    while (current){
      cout << current->key << ": " << current->info << endl;
      current = current->next;
    }    
  }
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" e con n numero di elementi dell'hashsize nel caso medio
assumendo vi sia una buona funzione hash che mantiene otimizzato l'heap.

Nel caso peggiore la complessità potrebbe diventare "O(n^2)" ipotizzando che tutti gli elementi siano riposti
nello stesso indice del vettore della tabella hash. Tuttavia nella pratica la tabella hash dovrebbe aver distribuiti
tutti gli elementi in maniera bilanciata tra gli indici del vettore portando ad una complessità media decisamente
più efficiente di "O(n)".
-------------------------------------------------------------------------------------------------------- */
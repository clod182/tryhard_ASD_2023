#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* #region definizioni */
struct Node{
    int key;
    Node* p;
    Node* left;
    Node* right;
    Node(int val, Node* parent = nullptr, Node* sx = nullptr, Node* dx = nullptr)
        : key{val}, p{parent}, left{sx}, right{dx}{}
};

typedef Node* PNode;

struct Tree{
    PNode root;
    Tree(PNode r = nullptr) : root{r} {}
};

typedef Tree* PTree;

/* #endregion definizioni */

/*#region DOMANDE ES*/

/* --------------------------------------------------------------------------------------------------------
Termini usati: 
    -Bst -> Binary Search Tree

    1) No, non potrà sempre esserci un bst T' che soddisfa le condizioni. Un bst deve rispettare 
    determinati vincoli per essere definito tale quindi T deve avere i propri nodi, con le relative chiavi, 
    organizzati con determinate regole e gerarchie  per poter avere una visita in pre_ordine 
    equivalente a quella di un bst.
-------------------------------------------------------------------------------------------------------- */

/*#endregion DOMANDE ES*/

//#region funzioni ausiliarie


int myFindFirstGreater(const vector<int>& vect, int x, int start, int end){
    bool found = false;
    int index = start;
    while(found == false && index <= end){
        if(vect[index] > x){
            found = true;
        }
        index ++;
    }

    if (found == false) return -1;
    else return index-1;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n)" con n elementi del sotto-vettore di input da start ad end.
Essendoci quindi un ciclo che itera su questi elementi la funzione ausiliaria avrà complessità
totale --> "O(n)"
-------------------------------------------------------------------------------------------------------- */

PNode preOrderAux(const vector<int>& v, int start, int end){
    if(start > end || start == -1){
        return nullptr;
    }

    PNode root = new Node(v[start]);

    int curInd = myFindFirstGreater(v, v[start], start, end);
    root->left = preOrderAux(v, start+1, curInd-1); 
    root->right = preOrderAux(v, curInd, end);   
    
    return root;
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(log n)" con n elementi del sotto-vettore di input da start ad end.
Essendoci una ricorsione che per scorrere gli elementi del vettore siamo anche in questo caso davanti ad 
una complessità nell'ordine di "O(n)".
Il resto delle operazioni viene svolto con complessità costante e quindi sarà "O(1)".
La funzione ausiliaria avrà quindi complessità totale --> "O(n)".
-------------------------------------------------------------------------------------------------------- */

//#endregion funzioni ausiliarie

/* #region funzione es */

PTree preOrder(const vector<int> &v){
    
    PNode root = preOrderAux(v, 0, v.size());

    PTree retTree = new Tree(root);
    return retTree;
}

/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(n^2)" con n numero di elementi del vettore di input.
Considerando quando già detto nell'analisi delle 2 funzioni ausiliarie, ad ogni chiamata della funzione
preOrderAux la funzione myFindFirstGreater è chiamata una volta dando così una complessità totale
per la funzione preOrder di "O(n) * O(n)" --> "O(n^2)".
-------------------------------------------------------------------------------------------------------- */

/* #endregion funzione es */
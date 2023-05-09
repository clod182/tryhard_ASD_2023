#include "dizionario.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <string> 

using namespace std;

int main()
{
    Dizionario mainDict;
    mainDict.inserisci(10, 10);
    mainDict.inserisci(66, 66);
    mainDict.inserisci(71, 71);
    mainDict.inserisci(157, 157);

    mainDict.stampa();

    PElem toBeDeleted = mainDict.cerca(10);
    mainDict.cancella(toBeDeleted);

    PElem testCerca = mainDict.cerca(157);
    mainDict.inserisci(31, 31);

    mainDict.stampa();

    return 0;
}

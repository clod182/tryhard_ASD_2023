#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/* #region funzioni MIE es */
/* #endregion funzioni MIE es */

/* #region es */
//*****************************************************************************approccio ricorsivo
bool perfettamenteBilanciatoRecAux(std::vector<int>& arr, int sum, int index) {
  // Caso base: multiinsieme vuoto
  if (sum == 0) {
    return true;
  }

  // Caso base: somma totale negativa o indice supera la dimensione del vettore
  if (sum < 0 || index >= arr.size()) {
    return false;
  }

  // Prova due possibilità ricorsive:
  // 1. Includere l'elemento corrente nella somma
  if (perfettamenteBilanciatoRecAux(arr, sum - arr[index], index + 1)) {
    return true;
  }

  // 2. Escludere l'elemento corrente dalla somma
  return perfettamenteBilanciatoRecAux(arr, sum, index + 1);
}

bool perfettamenteBilanciatoRec(std::vector<int>& arr) {
  int sum = 0;
  for (int num : arr) {
    sum += num;
  }

  // Se la somma totale è dispari, non può essere perfettamente bilanciato
  if (sum % 2 != 0) {
    return false;
  }

  return perfettamenteBilanciatoRecAux(arr, sum / 2, 0);
}
  //*****************************************************************************approccio programmazione dinamica top-down
  bool perfettamenteBilanciatoTopDown(std::vector<int>& arr) {
    int totalSum = 0;
    // Calcolo somma tot
    for (int num : arr) {
        totalSum += num;
    }
    
    // Verifica se la somma totale è dispari
    if (totalSum % 2 != 0) {
        return false;
    }
    
    int targetSum = totalSum / 2;
    
    // Creazione di una unordered_set per memorizzare le somme parziali raggiungibili
    std::unordered_set<int> sums;
    sums.insert(0);
    
    for (int num : arr) {
        std::unordered_set<int> newSums;
        for (int sum : sums) {
            int newSum = sum + num;
            newSums.insert(newSum);
        }
        sums.insert(newSums.begin(), newSums.end());
    }
    
    // Verifica se la somma target è presente nell'insieme delle somme parziali
    return sums.find(targetSum) != sums.end();
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(N * 2^N)" con n numero di elementi del vettore dato in input.

All'inizio calcoliamo la somma totale degli elementi dell'array, che richiede "O(N)" tempo.

Poi cro dell'insieme delle somme parziali: L'algoritmo esegue un ciclo esterno sugli elementi dell'array 
e un ciclo interno sulle somme parziali. Nel caso peggiore, il numero di somme parziali raggiungibili può 
essere 2^N, dove N è la dimensione dell'array di input. Quindi, il tempo complessivo per la creazione 
dell'insieme delle somme parziali è O(N * 2^N).

Pertanto la complessità temporale totale dell'algoritmo top-down è "O(N * 2^N)".
-------------------------------------------------------------------------------------------------------- */

/* #endregion  es */


int main()
{
    string dim_temp;
    getline(cin, dim_temp);
    int dim = stoi(ltrim(rtrim(dim_temp)));
    
    vector<int> arr;
    arr.resize(dim);
    
  	string arr_temp_temp_int;
    getline(cin, arr_temp_temp_int);
    vector<string> arr_temp_int = split(rtrim(arr_temp_temp_int));
  
    for (int i = 0; i < dim; i++) {
        int arr_temp = stoi(arr_temp_int[i]);
        arr[i] = arr_temp;
    }
        
    cout << perfettamenteBilanciatoTopDown(arr);
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
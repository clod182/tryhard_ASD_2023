#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/* #region funzioni MIE es */
/* #endregion funzioni MIE es */

/* #region funzioni ausiliarie es */
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
/* #endregion funzioni ausiliarie es */

/* #region es */
//approccio ricorsivo
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
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(2^N)" con n numero di elementi del vettore dato in input.

...
-------------------------------------------------------------------------------------------------------- */

/* #endregion  es */


int perfettamenteBilanciatoTopDown(vector<int> &arr);


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
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/* #region funzioni MIE es */
void myPrintMatrix (int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
/* #endregion funzioni MIE es */

/* #region funzioni ausiliarie es */
int aux_numberSubsequenceLessThanK(vector<int> &arr,int n, int k){
    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));

    //initialize the base cases
    for (int i=0; i<=n; i++){
        dp[i][1] = 1;
    }    

    // Compute the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) {
                dp[i][j] += dp[i-1][j/arr[i-1]];
            }
        }
    }

    return dp[n][k];
    myPrintMatrix((int**)dp, n+1, k+1);
}

int aux_Rec_numberSubsequenceLessThanK(vector<int>& arr, int n, int k) //Compiled successfully.12/15 test cases passed
{
    // Base cases
    if (n == 0) {
        return 0;  // Empty array, no subsequences
    }

    // If the last element of arr is greater than k, recurse on the array without the last element
    if (arr[n - 1] > k) {
        return aux_Rec_numberSubsequenceLessThanK(arr, n - 1, k);
    }

    // Calculate the number of subsequences by including or excluding the last element
    return aux_Rec_numberSubsequenceLessThanK(arr, n - 1, k) + aux_Rec_numberSubsequenceLessThanK(arr, n - 1, k / arr[n - 1]) + 1;
}
/* #endregion funzioni ausiliarie es */

/* #region funzioni ES */

//recursive----------------------------------------------------------------------------
/*int numberSubsequenceLessThanK(vector<int> &arr, int k){
    int ret = aux_Rec_numberSubsequenceLessThanK(arr, arr.size(), k);
    return ret;
}*/

//dynamic programming----------------------------------------------------------------------------
int numberSubsequenceLessThanK(vector<int> &arr, int k){
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i)
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
        }
    }
    return dp[k][n];
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(k*n)" con n numero di elementi del vettore e k vaolore massimo della somma dato in input.
Questa complessità è abbastanza intuitiva da calcolare ed data dai due cicli for "innestati".

La complessità della soluzione ricorsiva è invece "O(2^n)", data dalle due chiamate ricorsive ed al caso base ("O(1)") che portano a questa 
situazione: "2 * T(n-1) + O(1)" --> "O(2^n)".
Nel dettaglio, in ogni chiamata ricorsiva, l'algoritmo esegue operazioni aggiuntive (O(1)) per calcolare il conteggio delle sottosequenze. 
Queste operazioni non dipendono dalla dimensione dell'input e possono essere considerate a tempo costante.
Combinando i passaggi precedenti, possiamo esprimere la complessità temporale dell'algoritmo nel seguente modo:
T(n) = 2 * T(n-1) + O(1)

Ora, valutiamo la relazione di ricorrenza:

T(n) = 2 * T(n-1) + O(1)
= 2 * (2 * T(n-2) + O(1)) + O(1)
= 2^2 * T(n-2) + 2 * O(1) + O(1)
= 2^2 * (2 * T(n-3) + O(1)) + 2 * O(1) + O(1)
= 2^3 * T(n-3) + 2^2 * O(1) + 2 * O(1) + O(1)
ecc...

Continuando in questo modo, possiamo generalizzare l'equazione:

T(n) = 2^n * T(0) + 2^(n-1) * O(1) + 2^(n-2) * O(1) + ... + O(1)

Poiché "T(0)" è una costante e i termini "O(1)" si sommano a una costante, possiamo semplificare l'equazione in:

T(n) = O(2^n)

Pertanto, la complessità temporale complessiva dell'algoritmo è "O(2^n)".
-------------------------------------------------------------------------------------------------------- */
/* #endregion funzioni ES */


int main()
{  
    /* #region WIP TEST*/
    int rows = 3;
    int cols = 4;

    // Allocate a 2D array dynamically
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Fill the matrix with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    // Print the matrix
    myPrintMatrix(matrix, rows, cols);

    // Deallocate the 2D array
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;   

    vector<int> arrForMatrix = {1, 2, 3, 4};
    int test = aux_numberSubsequenceLessThanK(arrForMatrix, 4, 10);
    
    /* #endregion WIP TEST */
    
    string k_temp;
    getline(cin, k_temp);
    int k = stoi(ltrim(rtrim(k_temp)));
    
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
    cout << numberSubsequenceLessThanK(arr, k);
    
    return 0;
}
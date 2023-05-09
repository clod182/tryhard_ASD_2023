#include <iostream>
#include <vector>
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
        for (int j = 2; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) {
                dp[i][j] += dp[i-1][j/arr[i-1]];
            }
        }
    }

    return dp[n][k];

    myPrintMatrix((int**)dp, n+1, k+1);
}

int aux_Rec_numberSubsequenceLessThanK(vector<int> &arr, int n, int k, int i = 0, int prod = 1)
{
    if (i == n)
    {
        if (prod <= k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int count = 0;
    // Include the current element in the subsequence
    count += aux_Rec_numberSubsequenceLessThanK(arr, n, k, i + 1, prod * arr[i]);
    // Exclude the current element from the subsequence
    count += aux_Rec_numberSubsequenceLessThanK(arr, n, k, i + 1, prod);
    return count;
}
/* #endregion funzioni ausiliarie es */

/* #region funzioni ES */
//dynamic programming
/*int numberSubsequenceLessThanK(vector<int> &arr, int k){
    int ret = aux_numberSubsequenceLessThanK(arr, arr.size(), k);

    return ret;
}*/

//recursive
int numberSubsequenceLessThanK(vector<int> &arr, int k){
    int ret = aux_Rec_numberSubsequenceLessThanK(arr, arr.size(), k);

    return ret;
}
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

    int arrForMatrix [4] = {1, 2, 3, 4};
    int test = aux_numberSubsequenceLessThanK(arrForMatrix, 4, 10);
    /* #endregion WIP TEST*/
    
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
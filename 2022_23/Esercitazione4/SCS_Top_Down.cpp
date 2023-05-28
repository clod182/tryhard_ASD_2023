#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string shortestCommonSupersequence(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));

    // Calcolo della SCS utilizzando la programmazione dinamica top-down
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = s2.substr(0, j);
            else if (j == 0)
                dp[i][j] = s1.substr(0, i);
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            else {
                if (dp[i - 1][j].length() < dp[i][j - 1].length())
                    dp[i][j] = dp[i - 1][j] + s1[i - 1];
                else
                    dp[i][j] = dp[i][j - 1] + s2[j - 1];
            }
        }
    }

    return dp[m][n];
}
/* --------------------------------------------------------------------------------------------------------
La complessità di questa funzione è "O(m * n)" con n numero di elementi del vettore dato in input.

L'algoritmo utilizza una matrice dp di dimensione (m+1)x(n+1), dove m è la lunghezza della prima sequenza s1 
e n è la lunghezza della seconda sequenza s2. Il numero totale di celle nella matrice è (m+1) * (n+1).

In totale, dobbiamo calcolare il valore di tutte le (m+1) * (n+1) celle della matrice dp. Pertanto, il 
numero totale di operazioni richieste per l'algoritmo sarà proporzionale al prodotto (m+1) * (n+1).

Ecco quindi che arriviamo alla conclusione, la complessità totoale è --> "O(m * n)".
-------------------------------------------------------------------------------------------------------- */


int main()
{  
    
    string s1, s1_temp;
    getline(cin, s1_temp);
    s1 = ltrim(rtrim(s1_temp));
    
    string s2, s2_temp;
    getline(cin, s2_temp);
    s2 = ltrim(rtrim(s2_temp));
        
    cout << shortestCommonSupersequence(s1, s2);
    
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
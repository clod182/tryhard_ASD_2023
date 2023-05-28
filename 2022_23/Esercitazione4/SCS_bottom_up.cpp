#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//---------------------------------------- with Matrix --------------------------------
/*
int lungSCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D array of size (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialize the first row and column of the array
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Calculate the lengths of the SCS using bottom-up dynamic programming
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
*/

int lungSCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Creazione di un array di dimensione min(m, n) + 1
    int size = min(m, n) + 1;
    vector<int> dp(size, 0);

    // Calcolo delle lunghezze delle SCS utilizzando la programmazione dinamica
    for (int i = 0; i <= m; i++) {
        int prev = dp[0];
        for (int j = 0; j <= n; j++) {
            int temp = dp[j];
            if (i == 0 || j == 0) {
                dp[j] = i + j;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[j] = 1 + prev;
            } else {
                dp[j] = 1 + min(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }

    return dp[n];
}


int main()
{  
    
    string s1, s1_temp;
    getline(cin, s1_temp);
    s1 = ltrim(rtrim(s1_temp));
    
    string s2, s2_temp;
    getline(cin, s2_temp);
    s2 = ltrim(rtrim(s2_temp));
        
    cout << lungSCS(s1, s2);
    
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
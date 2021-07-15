#include <bits/stdc++.h>
#include <string>
using namespace std;

#define N 100
int L[N][N];

int LCS(string X, string Y, int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
            	L[i][j] = 0;
			} else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;            	
			} else {
            	L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
        }
    }
    return L[m][n];
}

string trace(string X, string Y, int m, int n) {
    string s;
    
    if (m == 0 || n == 0) {
        s = "";
    } else {
    	if (X[m - 1] == Y[n - 1]) {
        	s = trace(X, Y, m - 1, n - 1) + X[m - 1];
    	} else {
        	if (L[m - 1][n] >= L[m][n - 1]) {
        		s = trace(X, Y, m - 1, n);
			} else {
            	s = trace(X, Y, m, n - 1);
        	}
    	}
	}
	return s;
}
  
int main() {
    string X = "ABCDE";
    string Y = "GABRCDFE";
    int m = X.length();
    int n = Y.length();
  
    cout << LCS(X, Y, m, n) << endl;
    cout << trace(X, Y, m, n);
    
    return 0;
}

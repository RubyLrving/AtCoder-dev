#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, vector<int> a, int M) {

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<n; i++){
        for(int j=1; j<=m; j++){
            if(j - 1 - a[i] >= 0){
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] + dp[i][j-1-a[i]] + M) % M;
            }else{
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % M;
            }
        }
    }

    return dp[n][m];
} 
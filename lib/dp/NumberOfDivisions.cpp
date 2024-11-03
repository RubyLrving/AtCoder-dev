#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int M) {

    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=1; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(j-i>=0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[m][n];
} 
#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> a) {

    int INF = 1e9;
    vector<int> dp(N, INF);
    for(int i=0; i<N; i++){
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }

    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
} 
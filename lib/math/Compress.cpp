#include <bits/stdc++.h>

using namespace std;

template<typename T>
vector<T> compless(vector<T> &X){
    vector<T> valus = X;
    sort(valus.begin(), valus.end());
    valus.erase(unique(valus.begin(), valus.end()), valus.end());
    for(int i=0; i < X.size(); i++){
        X[i] = lower_bound(valus.begin(), valus.end(), X[i]) - valus.begin();
    }
    return X;
}
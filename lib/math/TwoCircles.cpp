#include <bits/stdc++.h>

using namespace std;

int solve(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2) {

    long long x = x2 - x1;
    long long y = y2 - y1;
    long long rd = r2 - r1;
    long long rs = r2 + r1;

    // [1] 一方の円が他方の円を完全に含み、2つの円は接していない
    if(x * x + y * y < rd * rd){
        return 1;
    }

    // [2] 一方の円が他方の円を完全に含み、2つの円は接している
    if(x * x + y * y == rd * rd){
        return 2;
    }

    // [3] 2つの円が互いに交差する
    if(rd * rd < (x * x + y * y) && (x * x + y * y) < rs * rs){
        return 3;
    }
    // [4] 2つの円の内部に共通部分は存在しないが、2つの円は接している
    if((x * x + y * y) == rs * rs){
        return 4;
    }
    
    // [5]　2つの円の内部に共通部分は存在せず、2つの円は接していない
    return 5;
} 
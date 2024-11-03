#include <bits/stdc++.h>

using namespace std;

/* 
name: modPow
proc: 高速なべき乗
*/
long long modPow(long long a, long long n, long long mod){
    long long res = 1;
    while(n>0){
        if(n&1) res = res * a % mod;
        a = a * a % mod;
        n = n>>1;
    }
    return res;
}

/* 
name: gcd
proc: ユークリッドの互除法
*/
template <class T>
T gcd(T x, T y){
    if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}

/* 
name: vlcm
proc: 可変引数で最小公倍数を求める関数
*/
template <class T>
T vlcm(T m, T n) {
  return m / gcd(m, n) * n;
}

/*
name: extGCD
proc: 拡張ユークリッドの互除法
*/
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

/*
name: EulerPhi
proc: オイラーのφ関数
*/
int EulerPhi(int n) {
  if (n == 0) return 0;
  int ans = n;
  for (int x = 2; x*x <= n; ++x) {
    if (n % x == 0) {
      ans -= ans / x;
      while (n % x == 0) n /= x;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}

// nCr を定義通りに求める関数
long long nCr(long long n, long long r) {
	long long nPr = 1;
	for(long long i = 0; i < r; ++i) {
		nPr *= (n - i);
	}

	long long fact_r = 1;
	for(long long i = 1; i <= r; ++i) {
		fact_r *= i;
	}

	long long ret = nPr / fact_r;
	return ret;
}

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
/***********************************************
* Author LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 100000
#define C 2000000000
#define base 1000000000
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 n, p, n0;
int64 t[N], res[N], pos;
int64 f1[N], f2[N];
void preprocess(int64 n, int64 p) {
    int64 nn = n, po = n * n;
    if (po <= C && p >= 2) {
        if ( p % 2 == 0) preprocess(po, p / 2);
        else {
            n0++;
            f1[n0] = nn;
            f2[n0] = 1;
            preprocess(po, p / 2);
        }
    }
    else {
        n0++;
        f1[n0] = n;
        f2[n0] = p;
    }
}
void mutiple() {
    int64 temp, carry, a;
    int64 m = 15000;
    a = n;
    while ( a ) {
        t[m--] = a % base;
        a/=base;
    }
    pos = m;
    p--;
    while ( p ) {
        carry = 0;
        for (int i = 15000; i >= pos + 1;i--) {
            temp = t[i] * n + carry;
            t[i] = temp % base;
            carry = temp / base;
        }
        temp = carry;
        while ( temp ) {
            t[pos--] = temp % base;
            temp/=base;
        }
        p--;
    }
        
    for (int i = n0 - 1;i >= 0;i--) {
        
        while ( f2[i] ) {
            
            carry = 0;
            for (int j = 15000;j >= pos + 1;j--) {
                temp = t[j] * f1[i] + carry;
                t[j] = temp % base;
                carry = temp / base;
            }
            temp = carry;
            while ( temp ) {
                t[pos--] = temp % base;
                temp/=base;
            }
            f2[i]--;
        }
    }
}

void output() {
    int cnt, k = 15000;
    for (int i = 15000;i >= pos - 1;i--) {
        cnt = 0;
        while ( t[i] ) {
            cnt++;
            res[k--] = t[i] % 10;
            t[i]/=10;
        }
        while (cnt < 9) {
            res[k--] = 0;
            cnt++;
        }
    }
    while (!res[k]) k++;
    for (int i = k;i <= 15000;i++) {
        if ((i - k) % 70 == 0 && i - k > 0) puts("");
        printf("%d", res[i]);
    }
    puts("");
}

int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    scanf("%lld %lld", &n, &p);
    if (n == 1) puts("1");
    else {
        n0 = 0;
        preprocess(n, p);
        n = f1[n0]; p = f2[n0];
        if ( p ) {
            mutiple();
            output();
        }
        else printf("%lld\n", n);
    }
}

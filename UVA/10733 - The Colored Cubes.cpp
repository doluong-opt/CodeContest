/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10733 - The Colored Cubes ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
string conver(uint64 N){
    string x = "";
    while ( N ){
        x = char(N % 10 + 48) + x;
        N/=10;
    }
    return x;
}
string Add(string x, string y){
    string rs = "";
    uint64 sum, nho;
    sum = nho = 0;
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    for (int i=x.size()-1;i>=0;i--) {
        sum = (x[i] - '0') + (y[i] - '0') + nho;
        rs = char(sum % 10 + 48) + rs;
        nho = sum / 10;
    }
    if (nho > 0) rs = "1" + rs;
    return rs;
}
string result(string x, uint64 N){
    uint64 d = 0, nho;
    string rs = "";
    for (int i=0;i<x.size();i++) {
        d = d * 10 + (x[i] - '0');
        rs = rs + char(d / N + 48);
        d = d % N;
    }
    while (rs.size() > 0 && rs[0] == '0') rs.replace(0,1,"");
    return rs;
}
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    uint64 a, b, c, d, n;
    string Ans;
    while ( scanf("%lld",&n) && n){
        a = (n * n * n * n * n * n);
        b = (3 * n * n * n * n);
        c = (12 * n * n * n);
        d = (8 * n * n);
        Ans = Add(Add(conver(a), conver(b)), Add(conver(c), conver(d)));
        cout << result(Ans, 24LL) <<endl;
    }
}

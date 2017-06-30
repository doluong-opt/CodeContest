/***********************************************
* Author - LUONG VAN DO                        *
* Problem 290 - Palindroms <---> smordnilaP
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
char s[M + 1];
int n;
bool isPalin(string x){
    int l, r;
    l = 0; r = x.size()-1;
    while (l<=r && x[l] == x[r]) {
        ++l;
        --r;
    }
    return l > r;
}
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
void cal(uint64 base) {
    int64 a[M + 1], b[M + 1];
    int64 x, Ans = 0;
    uint64 t1, t2, nm, D;
    nm = n;
    REP(i, nm) {
        if (isdigit(s[i])) x = s[i] - '0';
        else x = s[i] - 'A' + 10;
        a[i] = x;
        b[nm-i-1] = x;
    }
    string A, B, C;
    while ( true ) {
        A = B = "0";
        t1 = t2 = 1LL;
        for (int i=nm-1;i>=0;i--) {
            A = Add(A, conver(a[i] * t1));
            B = Add(B, conver(b[i] * t2));
            t1*=base; t2*=base;
        }
        C = Add(A, B);
        D = 0;
        
        REP(i, C.size()) D = D * 10 + (C[i] - '0');
        
        C = "";
        while ( D ) {
            C = char(D % base + 48) + C;
            D/=base;
        }
        
        Ans++;
        if (isPalin(C)) break;
        nm = C.size();
        REP(i, nm)
            a[i] = b[nm-i-1] = C[i] - '0';
    }
    if (base == 15) printf("%d",Ans);
    else printf(" %d",Ans);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, basemax;
    while ( gets(s) ) {
        n = strlen(s); basemax = 0;
        REP(i, n) {
            if (isdigit(s[i])) x = s[i] - '0';
            else x = s[i] - 'A' + 10;
            basemax = max(basemax, x);
        }
        if (basemax >= 15) printf("?");
        else cal(15);
        FORD(base, 14, 2)
            if (basemax>=base) printf(" ?");
            else cal(base);
        printf("\n");
    }
}

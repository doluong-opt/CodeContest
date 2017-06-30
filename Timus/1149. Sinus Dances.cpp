/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1149. Sinus Dances ->AC
* Algorithm adhoc
* Time Limit 0.046s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 210

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
void solve(int n) {
    if (n == 1) {
        cout<<"sin(1)";
        return;
    }
    cout<<"sin(1";
    for (int i=2;i<=n;i++) {
        if (i % 2 == 0) cout<<"-";
        else
        if (i % 2 == 1) cout<<"+";
        cout<<"sin("<<i;
    }
    for (int i=1;i<=n;i++) cout<<")";
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n;
    while ( scanf("%d",&n) != EOF) {
        for (int i=1;i<n;i++) cout<<"(";
        for (int i=1;i<n;i++) {
            solve(i);
            cout<<"+";
            cout<<n-i+1;
            cout<<")";
        }
        solve(n); cout<<"+1"<<endl;
    }
}

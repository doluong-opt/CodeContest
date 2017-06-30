/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1091. Tmutarakan Exams ->AC
* Algorithm number theory
* Time Limit 0.031s
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
#define N 55

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
int64 c[N][N];
vector <int> p;
void init() {
    c[0][0] = 1;
    for (int i=0;i<=50;i++) c[i][0] = 1;
    for (int i=1;i<=50;i++)
        for (int j=0;j<=i;j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
}
bool isPrime(int x) {
    for (int i=2;i*i<=x;i++)
        if (x % i == 0) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int k, s, ans, m, x, S;
    init(); ans = 0;
    scanf("%d %d",&k,&s);
    for (int i=2;ans <= 10000;i++) {
        if (isPrime(i)) {
            if (s / i < k) break;
            if (s / i >= k) ans+=c[s/i][k];
            for (int j=0;j<p.size();j++) {
                if (s / (p[j] * i) >= k) ans-=c[s/(p[j] * i)][k];
            }
            p.pb(i);
        }
    }
    if (ans <= 10000) printf("%d\n",ans);
    else printf("10000\n");
}

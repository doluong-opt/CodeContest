/***********************************************
* Author LUONG VAN DO                        *
* Problem 12406 - Help Dexter
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
#define INF 111222333444555666LL
#define N 20

using namespace std;

inline uint64 max(uint64 a, uint64 b) { return a > b ? a : b; }
inline uint64 min(uint64 a, uint64 b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int p, q;
uint64 Pow[N], C, ansMin, ansMax;
void run(int cur, uint64 sum) {
    if (cur == p) {
        if (sum % C == 0) {
            ansMin = min(ansMin, sum);
            ansMax = max(ansMax, sum);
        }
        return;
    }
    run(cur + 1, sum * 10 + 1);
    run(cur + 1, sum * 10 + 2);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Pow[0] = 1;
    for (int i = 1;i <= 17;i++)
        Pow[i] = Pow[i - 1] * 2;
    int cases, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d", &p, &q);
        C = Pow[q];
        ansMin = INF;
        ansMax = 0;
        run(0, 0);
        if (ansMin == INF) printf("Case %d: impossible\n", ++caseno);
        else
        if (ansMin == ansMax) printf("Case %d: %llu\n", ++caseno, ansMin);
        else printf("Case %d: %llu %llu\n", ++caseno, ansMin, ansMax);
    }
}

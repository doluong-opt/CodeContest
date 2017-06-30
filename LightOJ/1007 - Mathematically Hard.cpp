/***********************************************
* Author LUONG VAN DO                        *
* Problem 1007 - Mathematically Hard 
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
#define N 5000010

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
uint64 ans[N];
void init() {
    fr(i, 1, 5000000) ans[i] = i;
    ans[1] = 0;
    fr(i, 2, 5000000)
        if (ans[i] == i)
            for (int j = 2 * i; j <= 5000000; j+=i) ans[j]-=(ans[j] / i);
    fr(i, 2, 5000000) {
        if (ans[i] == i) ans[i]--;
        ans[i]*=ans[i];
    }
    fr(i, 2, 5000000)
        ans[i]+=ans[i-1];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, a, b, caseno = 0;
    init();
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&a,&b);
        printf("Case %d: ",++caseno);
        cout << ans[b] - ans[a - 1] << endl;
    }
}

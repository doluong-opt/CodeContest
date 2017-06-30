/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1372 - Hexagonal Bamboo Fort ->AC
* Algorithm BIT
* Time Limit 0.283s
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
#define N 100010

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
int n;
int a[110];
int64 tree[3 * N];
void update(int i) {
    while ( i <= 3 * N ){
        tree[i]++;
        i+=(i&-i);
    }
}
int64 get(int i) {
    int64 r = 0;
    while ( i ) {
        r+=tree[i];
        i-=(i&-i);
    }
    return r;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, m, caseno = 0;
    int64 ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        memset(tree, 0, sizeof(tree));
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a, a + n);
        ans = 0;
        for (int i=n-3;i>=0;i--) {
            
            for (int j=i+1;j<n;j++)
                for (int k=j+1;k<n;k++) {
                    m = a[k] - a[j] - a[i];
                    update(max(m, 1));
                }
            
            for (int j=0;j<i-1;j++)
                for (int k=j+1;k<i-1;k++)
                    ans+=get(a[i-1] + a[j] + a[k] - 1);
            
        }
        printf("Case %d: %lld\n",++caseno, ans);
    }
}

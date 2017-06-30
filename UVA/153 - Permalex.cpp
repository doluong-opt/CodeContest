/***********************************************
* Author LUONG VAN DO                        *
* Problem 153 - Permalex 
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
#define N 35

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y;
    node(){}
    node(int xx, int yy){
        x = xx; y = yy;
    }
}a[N];
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
char s[N];
int f[N][N], q[N], r[N], m;
int b[N];
void init(){
    fill(f, 0);
    for (int i = 1;i < N;i++)
        for (int j = 0;j < 10;j++)
            for (int k = p[j];k <= i;k*=p[j])
                f[i][j]+=(i / k);
}
int power(int x, int y) {
    int res = 1;
    while ( y ) {
        if (y & 1) res = res * x;
        x = x * x;
        y>>=1;
    }
    return res;
}
int cal(int n, int j) {
    int x = r[j] - 1;
    int result[11], ans = 1;
    fill(result, 0);
    for (int i = 0;i < 10;i++) {
        result[i]+=f[n][i];
        result[i]+=f[r[j]][i];
        result[i]-=f[x][i];
        result[i]-=q[i];
    }
    for (int i = 0;i < 10;i++)
        ans *= power(p[i], result[i]);
    return ans;
}
void setQ() {
    fill(q, 0);
    for (int i = 1;i <= 26;i++)
        for (int j = 0;j < 10;j++)
            q[j]+=f[r[i]][j];
}
bool cmp(node a, node b) {
    return (a.x < b.x);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    init();
    int ans, n, m;
    while ( gets(s) && strcmp(s, "#") ) {
        n = strlen(s);
        fill(r, 0);
        for (int i = 0;i < n;i++) {
            a[i + 1].x = s[i] - 'a' + 1;
            a[i + 1].y = i + 1;
        }
        sort(a + 1, a + n + 1, cmp);
        a[0].x = a[1].x - 1; m = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i].x > a[i - 1].x) m++;
            b[a[i].y] = m;
            r[m]++;
        }
        ans = 0;
        setQ();
        for (int i = 1;i <= n;i++) {
            
            for (int j = 1;j <= b[i] - 1;j++)
                ans+=cal(n - i, j);
            r[b[i]]--;
            setQ();
            if (r[b[i]] == 0) {
                for (int j = i + 1;j <= n;j++)
                    if (b[j] > b[i]) b[j]--;
                for (int j = b[i] + 1;j <= m;j++)
                    r[j - 1] = r[j];
            }
        }
        printf("%10d\n", ans + 1);
    }
}

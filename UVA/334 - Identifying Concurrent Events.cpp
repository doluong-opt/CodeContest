/***********************************************
* Author LUONG VAN DO                        *
* Problem 334 - Identifying Concurrent Events
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
#define N 300

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
int a[N][N];
char s[N], s1[N], s2[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, m, cnt, caseno = 0;
    while ( scanf("%d", &n) && n) {
        map <string, int> h;
        vector <string> S;
        cnt = 0;
        fill(a, 0);
        for (int i = 0;i < n;i++) {
            scanf(" %d ", &m);
            int f = cnt;
            for (int j = 0;j < m;j++) {
                scanf(" %s ", s);
                if (!h[s]) h[s] = cnt++;
                S.pb(s);
            }
            for (int j = f;j < cnt - 1;j++)
                a[j][j + 1] = 1;
        }
        scanf(" %d ", &m);
        for (int i = 0;i < m;i++) {
            scanf(" %s %s ", s1, s2);
            a[h[s1]][h[s2]] = 1;
        }
        
        for (int k = 0;k < cnt;k++)
            for (int i = 0;i < cnt;i++)
                for (int j = 0;j < cnt;j++)
                    a[i][j] |= (a[i][k] & a[k][j]);
        string out = "";
        int x = 0;
        for (int i = 0;i < cnt;i++)
            for (int j = i + 1;j < cnt;j++)
                if (i != j && !a[i][j] && !a[j][i]) {
                    x++;
                    if (x <= 2)
                        out += "(" + S[i] + "," + S[j] + ") ";
                }
        if (x) {
            printf("Case %d, %d concurrent events:\n", ++caseno, x);
            cout << out << endl;
        }
        else printf("Case %d, no concurrent events.\n", ++caseno);
    }
}

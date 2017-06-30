/***********************************************
* Author - LUONG VAN DO                        *
* Problem B. The least round way ->AC
* Algorithm adhoc
* Time Limit 480ms
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
#define M 1010

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
int d2[M][M];
int d5[M][M];
int g5[M][M], g2[M][M], a[M][M];
int n, res, flag, p1, p2;
void trace2() {
    int x = n;
    int y = n;
    int zero = 0;
    string ans = "";
    while (x !=1 || y !=1 ) {
        if (d2[x][y] - g2[x][y] == d2[x-1][y]) {
            x--;
            ans+="D";
        }
        else {
            y--;
            ans+="R";
        }
    }
    if (flag == 0) {
        printf("%d\n",res);
        for (int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
            cout<<endl;
    }
    else {
        if (res == 0) {
            printf("%d\n",res);
            for (int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
            cout<<endl;
        }
        else {
            printf("1\n");
            ans = "";
            for (int i=1;i<n;i++)
                ans+="R";
            for (int i=1;i<p1;i++)
                ans = "D" + ans;
            for (int i=p1;i<n;i++)
                ans+="D";
            cout<<ans<<endl;
        }
    }
}
void trace5() {
    int x = n;
    int y = n;
    int zero = 0;
    string ans = "";
    while ( x !=1 || y !=1 ) {
        if (d5[x][y] - g5[x][y] == d5[x-1][y]) {
            x--;
            ans+="D";
        }
        else {
            if (!a[x][y]) zero++;
            y--;
            ans+="R";
        }
    }
    if (flag == 0) {
        printf("%d\n",res);
        for (int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
            cout<<endl;
    }
    else {
        if (res == 0) {
            printf("%d\n",res);
            for (int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
            cout<<endl;
        }
        else {
            printf("1\n");
            ans = "";
            for (int i=1;i<n;i++)
                ans+="R";
            for (int i=1;i<p1;i++)
                ans = "D" + ans;
            for (int i=p1;i<n;i++)
                ans+="D";
            cout<<ans<<endl;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int val; flag = 0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            scanf("%d",&val);
            a[i][j] = val;
            d2[i][j] = d5[i][j] = 0;
            g2[i][j] = g5[i][j] = 0;
            if (!val) {
                flag = 1;
                p1 = i;
                p2 = j;
                d2[i][j] = d5[i][j] = 1;
                g2[i][j] = g5[i][j] = 1;
                continue;
            }
            while (!(val & 1 ) ) {
                val>>=1;
                d2[i][j]++;
            }
            while (!(val % 5) ) {
                val/=5;
                d5[i][j]++;
            }
            g5[i][j] = d5[i][j];
            g2[i][j] = d2[i][j];
        }
        d2[i][0] = INF;
        d2[0][i] = INF;
        d5[i][0] = INF;
        d5[0][i] = INF;
        g2[i][0] = INF;
        g2[0][i] = INF;
        g5[i][0] = INF;
        g5[0][i] = INF;
    }
    
    for (int i=2;i<=n;i++) {
        d2[1][i]+=d2[1][i-1];
        d5[1][i]+=d5[1][i-1];
        d2[i][1]+=d2[i-1][1];
        d5[i][1]+=d5[i-1][1];
    }
    
    for (int i=2;i<=n;i++)
        for (int j=2;j<=n;j++) {
            d2[i][j] = min(d2[i][j] + d2[i - 1][j], d2[i][j] + d2[i][j - 1]);
            d5[i][j] = min(d5[i][j] + d5[i - 1][j], d5[i][j] + d5[i][j - 1]);
        }
    res = min(d2[n][n], d5[n][n]);
    if (d5[n][n] < d2[n][n]) trace5();
    else trace2();
}

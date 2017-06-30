/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1165 - Digit Dancing ->AC
* Algorithm bfs
* Time Limit 2.112s
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
#define N 100000
#define des 12345678
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
map <int, bool> m;
int sign[10], a[10];
bool isPrime(int x) {
    for (int i=2;i*i<=x;i++)
        if (x % i == 0) return false;
    return true;
}
int c1(int x, int y) {
    int temp[10];
    for (int i=1;i<=8;i++) temp[i] = a[i];
    for (int i=y;i>=x+2;i--)
        swap(temp[i], temp[i-1]);
    int s = 0;
    for (int i=1;i<=8;i++)
        s = s * 10 + abs(temp[i]);
    return s;
}
int c2(int x, int y) {
    int temp[10];
    for (int i=1;i<=8;i++) temp[i] = a[i];
    for (int i=y;i>=x+1;i--)
        swap(temp[i], temp[i-1]);
    int s = 0;
    for (int i=1;i<=8;i++)
        s = s * 10 + abs(temp[i]);
    return s;
}
int c3(int x, int y) {
    int temp[10];
    for (int i=1;i<=8;i++) temp[i] = a[i];
    for (int i=x;i<=y-2;i++)
        swap(temp[i], temp[i+1]);
    int s = 0;
    for (int i=1;i<=8;i++)
        s = s * 10 + abs(temp[i]);
    return s;
}
int c4(int x, int y) {
    int temp[10];
    for (int i=1;i<=8;i++) temp[i] = a[i];
    for (int i=x;i<=y-1;i++)
        swap(temp[i], temp[i+1]);
    int s = 0;
    for (int i=1;i<=8;i++)
        s = s * 10 + abs(temp[i]);
    return s;
}
int bfs(int s) {
    ii p; int n, s1, s2, s3, s4;
    queue <ii> Q;
    Q.push(ii(s, 0)); m[s] = true;
    while (!Q.empty()) {
        p = Q.front(); Q.pop();
        if (p.ff == des) return p.ss;
        s = p.ff; n = 8;
        while ( s ) {
            a[n] = s % 10;
            if (sign[a[n]] < 0) a[n]*=-1;
            n--;
            s/=10;
        }
        for (int i=1;i<=8;i++)
            for (int j=i + 1;j<=8;j++)
                if (a[i] * a[j] < 0 && isPrime( abs(a[i]) + abs(a[j]) )) {
                    s1 = c1(i, j); s3 = c3(i, j);
                    s2 = c2(i, j); s4 = c4(i, j);
                    /*if (i == 3 && j == 7) {
                        for (int k=1;k<=8;k++) cout<<a[k]<<" ";
                        cout<<endl;
                        /*cout<<s1<<endl;
                        cout<<s2<<endl;
                        cout<<s3<<endl;
                        cout<<s4<<endl;
                    }*/
                    if ( !m[s1] ) {
                        m[s1] = true;
                        Q.push(ii(s1, p.ss + 1));
                    }
                    if ( !m[s2] ) {
                        m[s2] = true;
                        Q.push(ii(s2, p.ss + 1));
                    }
                    if ( !m[s3] ) {
                        m[s3] = true;
                        Q.push(ii(s3, p.ss + 1));
                    }
                    if ( !m[s4] ) {
                        m[s4] = true;
                        Q.push(ii(s4, p.ss + 1));
                    }
                }
    }
    return -1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, s, f1, f2, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        s = f1 = f2 = 0; m.clear();
        for (int i=1;i<=8;i++) sign[i] = 1;
        for (int i=1;i<=8;i++) {
            scanf("%d",&a[i]);
            if (a[i] > 0) f1++;
            if (a[i] < 0) {
                f2++;
                sign[abs(a[i])] = -1;
            }
            s = s * 10 + abs(a[i]);
        }
        if (s == des) printf("Case %d: 0\n",++caseno);
        else
        if (f1 == 8 || f2 == 8) printf("Case %d: -1\n",++caseno);
        else printf("Case %d: %d\n",++caseno, bfs(s));
    }
}

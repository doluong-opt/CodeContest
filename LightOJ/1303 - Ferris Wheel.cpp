/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1303 - Ferris Wheel ->AC 
* Algorithm queue
* Time Limit 0.001s
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
#define N 25

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
int n, m;
int mark[N][N], seat[N], inc[N];
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    int cases, ans, index, cnt, per, flag;
    int caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        ans = cnt = 0;
        scanf("%d %d",&n,&m);
        queue <int> q1, q2;
        for (int i=1;i<=n;i++) {
            q1.push(i);
            inc[i] = 0;
            for (int j=0;j<m;j++) mark[i][j] = 0;
        }
        for (int i=0;i<m;i++) seat[i] = 0;
        index = -1;
        while ( cnt != n * m ) {
            ans+=5;
            index = (index + 1) % m;
            if ( seat[index] ) {
                if ( inc[ seat[index] ] < m) q1.push( seat[index] );
                seat[index] = 0;
            }
            flag = 0;
            while ( !q1.empty() ) {
                per = q1.front(); q1.pop();
                if ( mark[per][index] ) {
                    q2.push( per );
                    flag = 1;
                    continue;
                }
                else {
                    mark[per][index] = 1;
                    seat[index] = per;
                    inc[per]++;
                    cnt++;
                    break;
                }
            }
            if ( flag ) {
                while ( !q1.empty() ) {
                    q2.push(q1.front());
                    q1.pop();
                }
                while ( !q2.empty() ) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
        flag = 0;
        for (int i=0;i<m;i++)
            if (seat[i]) flag++;
        index = (index + 1) % m;
        while (flag) {
            ans+=5;
            if (seat[index]) {
                seat[index] = 0;
                flag--;
            }
            index = (index + 1) % m;
        }
        printf("Case %d: %d\n",++caseno, ans);
    }
}

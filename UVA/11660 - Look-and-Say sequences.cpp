/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11660 - Look-and-Say sequences ->AC
* Algorithm adhoc, simulation
* Time Limit 1.244s
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
string x;
void build(int x1, int i, int j) {
    char t[N]; sprintf(t,"%d",x1);
    x = t;
    string y = "";
    int cnt;
    while ( i > 1) {
        cnt = 1;
        for (int k=1;k<x.size();k++) {
            if (x[k-1] == x[k]) cnt++;
            else {
                sprintf(t,"%d",cnt);
                y+=t;
                y+=x[k-1];
                cnt = 1;
            }
            if (y.size() >= 1000) break;
        }
        sprintf(t,"%d",cnt);
        y+=t;
        y+=x[x.size()-1];
        i--;
        x = y; y = "";
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int a, b, c;
    while ( scanf("%d %d %d",&a,&b,&c) && (a | b | c) ) { 
        build(a, b, c);
        printf("%c\n",x[c - 1]);
    }
}

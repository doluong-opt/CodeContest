/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10719 - Quotient Polynomial ->AC
* Algorithm Adhoc
* Time Limit 0.524s
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
#define M 10005

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
int d[M + 1];
int q[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int k, n, nm, ind, sign;
    char s[100 * M + 1];
    while (gets(s) && strlen(s)){
        sscanf(s,"%d",&k);
        gets(s); n = strlen(s);
        ind = nm = 0;
        while (ind < n) {
            sign = 0;
            while (ind < n && s[ind] == ' ') ++ind;
            if (!isdigit(s[ind])) {
                sign = 1;
                ++ind;
            }
            sscanf(s + ind,"%d",&d[nm++]);
            if (sign) d[nm - 1]*=-1;
            while (ind < n && s[ind] !=' ') ++ind;
        }
        q[0] = d[0]; d[1] +=(d[0] * k);
        d[nm] = 0;
        for (int i=1;i<nm;i++) {
            q[i] = d[i];
            d[i+1]+=d[i] * k;
        }
        printf("q(x):");
        for (int i=0;i<nm-1;i++)
            printf(" %d",q[i]);
        printf("\n");
        printf("r = %d\n\n",d[nm-1]);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 392 - Polynomial Showdown ->AC
* Algorithm Adhoc
* Time Limit 0.096s
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
#define M 100000

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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int a, sign, ind;
    while ( scanf("%d",&a) != EOF) {
        if (a!=0) {
            if (abs(a)!=1) printf("%dx^8",a);
            else
            if (a < 0) printf("-x^8");
            else printf("x^8");
            ind = 8;
        }
        else {
            ind = 7;
            while (ind >= 0) {
                scanf("%d",&a);
                if (!a && ind >= 1) {
                    ind--;
                    continue;
                }
                if (ind > 1) {
                    if (abs(a)!=1) printf("%dx^%d",a,ind);
                    else
                    if (a < 0) printf("-x^%d",ind);
                    else printf("x^%d",ind);
                }
                else 
                if (ind == 1) {
                    if (abs(a)!=1) printf("%dx",a);
                    else
                    if (a < 0) printf("-x");
                    else printf("x");
                }
                else
                if (ind == 0) {
                    printf("%d",a);
                }
                break;
            }
        }
        sign = 0;
        for (int i=ind-1;i>=1;i--) {
            scanf("%d",&a);
            sign = 0;
            if (!a) continue;
            if (a < 0) sign = 1;
            a = abs(a);
            if (sign) printf(" -");
            else printf(" +");
            if (i != 1) {
                if (a!=1) printf(" %dx^%d",a,i);
                else printf(" x^%d",i);
            }
            else {
                if (a!=1) printf(" %dx",a);
                else printf(" x");
            }
        }
        if (ind > 0) {
            scanf("%d",&a);
            if (!a) {
                printf("\n");
                continue;
            }
            if (a < 0) printf(" -");
            else printf(" +");
            a = abs(a);
            printf(" %d\n",a);
        }
        else printf("\n");
    }
}

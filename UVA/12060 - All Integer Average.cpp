/***********************************************
* Author - LUONG VAN DO                        *
* 12060 - All Integer Average ->AC
* Algorithm Adhoc
* Time Limit 0.016s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int digit(int n){
    int cnt = 0;
    while (n) {
        n/=10;
        ++cnt;
    }
    return cnt;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, tu, Case = 0;
    int x, d, y, a, b, z;
    while ( scanf("%d",&n) && n){
        tu = 0;
        REP(i, n) {
            scanf("%d",&x);
            tu+=x;
        }
        d = gcd(tu, n);
        tu/=d;
        n/=d;
        if (n == 1) {
            if (tu >= 0) printf("Case %d:\n%d\n",++Case,tu);
            else printf("Case %d:\n- %d\n",++Case,abs(tu));
        }
        else {
            if ( fabs( double(tu) / double(n) ) < 1 ) {
                printf("Case %d:\n",++Case);
                x = digit(tu);
                y = digit(n);
                if ( double(tu) / double(n) > 0 ) {
                    REP(i, y - x) printf(" ");
                    printf("%d\n",abs(tu));
                    REP(i, y - x + 1) printf("-");
                    printf("\n");
                    printf("%d\n",abs(n));
                }
                else {
                    REP(i, y - x + 2) printf(" ");
                    printf("%d\n",abs(tu));
                    printf("- ");
                    REP(i, y - x + 1) printf("-");
                    printf("\n");
                    REP(i, y - x + 2) printf(" ");
                    printf("%d\n",abs(n));
                }
            }
            else {
                a = tu / n;
                b = tu % n;
                x = digit(b);
                y = digit(n);
                z = digit(a);
                printf("Case %d:\n",++Case);
                if ( double(tu) / double(n) > 0 ) {
                    REP(i, y + z - x) printf(" ");
                    printf("%d\n",abs(b));
                    printf("%d",abs(a));
                    REP(i, y) printf("-");
                    printf("\n");
                    REP(i, z) printf(" ");
                    printf("%d\n",abs(n));
                }
                else {
                    REP(i, y + z - x + 2) printf(" ");
                    printf("%d\n",abs(b));
                    printf("- ");
                    printf("%d",abs(a));
                    REP(i, y) printf("-");
                    printf("\n");
                    REP(i, z + 2) printf(" ");
                    printf("%d\n",abs(n));
                }
            }
        }
    }
    return 0;
}

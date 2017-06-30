/***********************************************
* Author - LUONG VAN DO                        *
* 725 - Division ->AC
* Algorithm Adhoc
* Time Limit 0.104s
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
int digit(int x){
    int cnt = 0;
    while ( x ){
        cnt++;
        x/=10;
    }
    return cnt;
}
bool check(int x, int y) {
    int inc[10];
    REP(i, 10) inc[i] = 0;
    int xx = digit(x);
    if (xx == 1) inc[0]+=4;
    if (xx == 2) inc[0]+=3;
    if (xx == 3) inc[0]+=2;
    if (xx == 4) inc[0]+=1;
    while ( x ) {
        inc[x % 10]++;
        x/=10;
    }
    xx = digit(y);
    if (xx == 1) inc[0]+=4;
    if (xx == 2) inc[0]+=3;
    if (xx == 3) inc[0]+=2;
    if (xx == 4) inc[0]+=1;
    while ( y ) {
        inc[y % 10]++;
        y/=10;
    }
    REP(i, 10)
        if (inc[i] > 1) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int blank = 0;
    int n, x, y;
    bool found;
    while ( scanf("%d",&n) && n){
        if (blank) puts("");
        blank = 1; x = 1;
        found = false;
        while ( true ) {
            y = x * n;
            if ( digit(y) == 5 && check(x, y)) {
                printf("%d / %05d = %d\n",y, x, n);
                found = true;
            }
            if ( digit(y) > 5 ) break;
            ++x;
        }
        if (!found) printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

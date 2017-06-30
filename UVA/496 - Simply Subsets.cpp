/***********************************************
* Author - LUONG VAN DO                        *
* 496 - Simply Subsets ->AC
* Algorithm Adhoc
* Time Limit 0.012s
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
int a[maxN], b[maxN];
int n, m;
bool check(){
    REP(i, n)
        REP(j, m)
            if (a[i] == b[j]) return true;
    return false;
}
bool bs(int x, int l, int r, int a[]){
    while ( l<=r ) {
        int mid = (l + r) >> 1;
        if ( x == a[mid] ) return true;
        if ( x > a[mid] ) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[maxN];
    int l, i, cnt;
    while ( gets(s) ){
        m = n = 0;
        l = strlen(s); i = 0;
        while (i < l) {
            while (i < l && s[i] == ' ') ++i;
            sscanf(s+i,"%d",&a[n++]);
            while (i < l && s[i]!=' ') ++i;
        }
        gets(s); l = strlen(s); i = 0;
        while (i < l) {
            while (i < l && s[i] == ' ') ++i;
            sscanf(s+i,"%d",&b[m++]);
            while (i < l && s[i]!=' ') ++i;
        }
        sort(a, a + n);
        sort(b, b + m);
        cnt = 0;
        if (m == n) {
            REP(i, n)
                if ( bs(a[i], 0, m-1, b) ) cnt++;
                if (cnt == n) puts("A equals B");
            else
                if ( check() ) puts("I'm confused!");
            else puts("A and B are disjoint");
        }
        else {
            if (n > m) {
                REP(i, m)
                    if ( bs(b[i], 0, n-1, a) ) cnt++;
                if ( cnt == m ) puts("B is a proper subset of A");
                else
                    if (cnt > 0) puts("I'm confused!");
                else puts("A and B are disjoint");
            }
            else {
                REP(i, n)
                    if ( bs(a[i], 0, m-1, b) ) cnt++;
                if ( cnt == n ) puts("A is a proper subset of B");
                else
                    if (cnt > 0) puts("I'm confused!");
                else puts("A and B are disjoint");
            }
        }
    }
    return 0;
}

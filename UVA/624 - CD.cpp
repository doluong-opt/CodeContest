/***********************************************
* Author - LUONG VAN DO                        *
* 624 - CD ->AC
* Algorithm recur
* Time Limit 0.208s
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
int S, n, best, nm, Count;
int a[maxN], xx[maxN], ans[maxN];
void Recur(int ind, int cnt, int sum) {
    
    if (cnt == n ) {
        if (sum > best && sum <= S) {
            nm = ind;
            REP(i, ind)
                ans[i] = xx[i];
            best = sum;
        }
        return;
    }
    xx[ind] = a[cnt];
    Recur(ind + 1, cnt + 1, sum + a[cnt]);
    Recur(ind, cnt + 1, sum);
    
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    while ( scanf("%d",&S) != EOF){
        scanf("%d",&n);
        REP(i, n) scanf("%d",&a[i]);
        best = nm = Count = 0;
        Recur(0, 0, 0);
        REP(i, nm)
            printf("%d ",ans[i]);
        printf("sum:%d\n",best);
    }
    return 0;
}

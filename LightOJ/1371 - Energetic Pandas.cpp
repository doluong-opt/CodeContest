/***********************************************
* Author - LUONG VAN DO                        *
* 1371 - Energetic Pandas ->AC
* Algorithm math
* Time Limit 0.077s
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
#define INF 1000000007
#define maxN 1001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int bamboo[maxN], panda[maxN], n;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, cnt, pivot, idx;
    int64 ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) scanf("%d",&bamboo[i]);
        FOR(i, 1, n) scanf("%d",&panda[i]);
        sort(bamboo + 1, bamboo + n + 1);
        cnt = pivot = idx = 0;
        FOR(i, 1, n)
            if ( panda[i] >= bamboo[n]) pivot++;
        ans = pivot;
        FORD(i, n - 1, 1) {
            cnt = 0;
            FOR(j, 1, n)
                if (panda[j] >= bamboo[i]) cnt++;
            
            if (cnt < pivot) {
                ans = 0;
                break;
            }
            else {
                idx++;
                ans = ((ans % INF) * (cnt - idx) % INF) % INF;
            }
            if (ans == 0) break;
        }
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}

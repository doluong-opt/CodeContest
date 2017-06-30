/***********************************************
* Author - LUONG VAN DO                        *
* 1341 - Aladdin and the Flying Carpet ->AC
* Algorithm math
* Time Limit 0.401s
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
#define maxN 1000000

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int64> prime;
int color[maxN], Size;
void sieve() {
    FOR(i, 1, maxN - 1) color[i] = 1;
    color[1] = 0;
    for (int i=4;i<maxN;i+=2) color[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (color[i])
            for (int j=i*i;j<maxN;j+=2*i) color[j] = 0;
    prime.pb( 2 );
    for (int i=3;i<maxN;i+=2)
        if (color[i])
            prime.pb( i );
    Size = prime.size();
}
int64 Cal(int64 xx){
    int i = 0, cnt;
    int64 ans = 1;
    while (i < Size && (int64)prime[i] * (int64)prime[i]<=xx) {
        cnt = 0;
        while ( xx % prime[i] == 0) {
            xx/=prime[i];
            cnt++;
        }
        ans*=(cnt + 1);
        ++i;
    }
    if (xx > 1) ans*=2;
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, y;
    sieve();
    int64 a, b;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&a,&b);
        if ( a <= b * b ) printf("Case %d: 0\n",t);
        else {
            y = Cal( a ) / 2;
            FOR(i, 1, b - 1)
                if (!(a % i)) y--;
            printf("Case %d: %d\n",t,y);
        }
    }
    return 0;
}

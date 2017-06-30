/***********************************************
* Author - LUONG VAN DO                        *
* 1140 - How Many Zeroes ->AC
* Algorithm dp
* Time Limit 0.011s
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

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 f(int64 m){
    if (m < 0) return 0;
    char s[20];
    sprintf(s, "%lld", m);
    int n = strlen(s);
    
    int64 Pow[20] = {1};
    FOR(i, 1, 19) Pow[i] = Pow[i-1] * 10;
    
    int64 suf[20];
    suf[n] = 0;
    FORD(i, n - 1, 0)
        suf[i] = suf[i+1] + (s[i] - '0') * Pow[n-i-1];
        
    int64 res = 1, pref = 0;
    FOR(i, 1, n - 1) {
        pref = pref * 10 + (s[i-1] - '0');
        
        if (s[i] != '0')
            res+=pref * Pow[n-i-1];
        else
            res+=(pref - 1) * Pow[n-i-1] + suf[i+1] + 1;
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 a, b, x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&a,&b);
        y = f(b);
        x = f(a - 1);
        printf("Case %d: %lld\n",t,y - x);
    }
    return 0;
}

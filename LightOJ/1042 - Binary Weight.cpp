/***********************************************
* Author - LUONG VAN DO                        *
* 1042 - Binary Weight ->AC
* Algorithm Adhoc
* Time Limit 0.001s
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
int x[35], m;
int64 pow2[40];
void init(){
    pow2[0] = 1;
    for (int i=1;i<=35;i++)
        pow2[i] = pow2[i-1] * 2;
}
int weight(int n){
    int b = 0;
    m = 0;
    while ( n ) {
        x[++m] = (n % 2);
        b+=(n % 2);
        n/=2;
    }
    return b;
}
int64 solve(int w){
    int64 ans = 0;
    int cnt = 0;
    if ( w == m ) {
        ans+=pow2[w];
        for (int i=0;i<w-1;i++) ans+=pow2[i];
    }
    else {
        int pos;
        x[m+1] = 0;
        for (int i=1;i<=m;i++)
            if (x[i] == 1 && x[i+1] == 0) {
                pos = i;
                swap(x[i], x[i+1]);
                if (i+1 > m) ++m;
                break;
            }
            else if (x[i] == 1 && x[i+1] == 1) cnt++;
        for (int i=1;i<=pos;i++) x[i] = 0;
        for (int i=1;i<=cnt;i++) x[i] = 1;
        for (int i=1;i<=m;i++)
            ans+=(x[i] * pow2[i-1]);
        
    }
    return ans;
}
void Read(){
    int test,w;
    init();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        w = weight( n );
        printf("Case %d: ",t);
        cout << solve( w ) <<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

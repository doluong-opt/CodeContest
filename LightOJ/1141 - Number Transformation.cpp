/***********************************************
* Author - LUONG VAN DO                        *
* 1141 - Number Transformation ->AC
* Algorithm bfs
* Time Limit 0.007s
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

vi prime;
vi factor[1000 + 10];
int color[1000 + 10];
int sum[1000 + 10];
int n, Size;
void sieve() {
    REP(i, 1010) color[i] = 1; color[1] = 0;
    for (int i=4;i<1010;i+=2) color[i] = 0;
    for (int i=3;i*i<1010;i+=2)
        if (color[i])
            for (int j=i*i;j<1010;j+=2*i) color[j] = 0;
    prime.pb( 2 );
    for (int i=3;i<1010;i+=2)
        if (color[i]) prime.pb( i );
    Size = prime.size();
}
void init() {
    int nn;
    FOR(i, 1, 1000) factor[i].clear();
    
    FOR(i, 1, 1000) {
        int ind = 0;
        nn = i;
        while ( prime[ind] * prime[ind] <= nn ) {
            if ( nn % prime[ind] == 0) factor[i].pb( prime[ind] );
            
            while ( nn % prime[ind] == 0) nn/=prime[ind];
            
            ind++;
        }
        if ( nn > 1 && nn!=i ) factor[i].pb( nn );
    }
}
void reset() {
    REP(i, 1010) sum[i] = 0;
}
int bfs(int s, int e){
    ii tt = ii(s,0);
    ii d;
    queue <ii> Q;
    Q.push( tt );
    reset(); sum[s] = 1;
    while ( !Q.empty() ) {
        d = Q.front(); Q.pop();
        if (d.A == e) return d.B;
        REP(i, factor[d.A].size() ) {
            tt.A = d.A + factor[d.A][i];
            if (tt.A > e || sum[tt.A] ) continue;
            sum[tt.A] = 1;
            tt.B = d.B + 1;
            Q.push( tt );
        }
    }
    return -1;
}
void Read(){
    sieve();
    init();
    int test, s, e;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&s,&e);
        printf("Case %d: %d\n",t,bfs(s,e));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1024 - Eid ->AC
* Algorithm Bignum
* Time Limit 0.657s
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
#define maxN 1005
#define N 10005
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[maxN];
int a[maxN], n, nm;
int color[N];
int f[N];
int64 x, l1, l2;
vector <int> prime;
string ans;
int numa[N], numb[N], Tich[2 * N];
void sieve() {
    FOR(i, 1, N - 1) color[i] = 1;
    color[1] = 0;
    for (int i=4;i<N;i+=2) color[i] = 0;
    for (int i=3;i*i<N;i+=2)
        if (color[i])
            for (int j=i*i;j<N;j+=2*i) color[j] = 0;
    prime.pb(2);
    for (int i=3;i<N;i+=2)
        if (color[i]) prime.pb(i);
}
void init(string x, int64 y){
    l1 = x.length(); l2 = 0;
    REP(i, l1)
        numa[l1-i-1] = (x[i] - '0');
    while ( y ) {
        numb[l2++] = (y % 10);
        y/=10;
    }
}
void ChuanHoa(){
    for (int i=0;i<=nm;i++)
    {
        if ( Tich[i] > 9){
            Tich[i+1]+=(Tich[i] / 10);
            Tich[i] = Tich[i] % 10;
        }
    }
    if ( Tich[nm + 1] ) nm++;
}
string product(string x, int64 y){
    string tmp = "";
    init(x, y);
    memset(Tich, 0, sizeof(Tich));
    REP(i, l1)
        REP(j, l2)
        Tich[i+j]+=numa[i] * numb[j];
    nm = l1 + l2 - 2;
    ChuanHoa();
    for (int i=nm;i>=0;i--) tmp+=char(Tich[i] + 48);
    return tmp;
}
void solve(int xx) {
    int ind = 0, cnt;
    while ( prime[ind] * prime[ind]<=xx ) {
        cnt = 0;
        while ( xx % prime[ind] == 0) {
            xx/=prime[ind];
            cnt++;
        }
        if ( cnt > f[ prime[ind] ] ) {
            FOR(i, 1, cnt - f[prime[ind]])
                ans = product(ans, prime[ind]);
            f[prime[ind]] = cnt;
        }
        ++ind;
    }
    if (xx > 1) {
        if ( f[xx] < 1) {
            ans = product(ans, xx);
            f[xx] = 1;
        }
    }
}
void Read() {
    int test, NN;
    sieve();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n); ans = "1";
        NN = 0;
        FOR(i, 1, N - 1) f[i] = 0;
        FOR(i, 1, n) {
            scanf("%d",&a[i]);
            solve(a[i]);
        }
        printf("Case %d: ",t);
        cout << ans <<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

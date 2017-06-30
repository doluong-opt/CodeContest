/***********************************************
* Author - LUONG VAN DO                        *
* 1375 - LCM Extreme ->AC
* Algorithm math
* Time Limit 0.998s
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
#define EM 0.5772156649015328606065120900824

#define maxN 200010
#define MAX 3000010
#define LMT 3000000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
uint64 phi[MAX], f[MAX];
void initial() {
    FOR(i, 1, LMT) {
        phi[i] = i;
        f[i] = 0;
    }
    FOR(i, 2, LMT)
        if (phi[i] == i)
            for (int j = 2 * i;j<=LMT;j+=i) phi[j]-=(phi[j] / i);
    FOR(i, 2, LMT)
        if (phi[i] == i) phi[i]--;
    FOR(i, 1, LMT)
        for (int j=i;j<=LMT;j+=i) f[j] += (uint64)i * (uint64)phi[i];
    FOR(i, 1, LMT) {
        f[i] = (f[i] + 1) >> 1;
        f[i] = f[i] * i;
        f[i] += f[i-1];
        f[i] -= i;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    initial();
    int test, n;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        cout <<"Case "<<t<<": "<<f[n]<<endl;
    }
    return 0;
}

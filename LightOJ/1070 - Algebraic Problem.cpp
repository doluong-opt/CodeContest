/***********************************************
* Author - LUONG VAN DO                        *
* 1070 - Algebraic Problem ->AC
* Algorithm mutiple matrix
* Time Limit 0.009s
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
uint64 ans, s, q, n;
uint64 matrix[4][4];
uint64 ss[4];
void mutiple_base(){
    uint64 temp[4];
    temp[0] = ss[0]; temp[1] = ss[1];
    ss[0] = matrix[0][0] * temp[0] + matrix[0][1] * temp[1];
    ss[1] = matrix[1][0] * temp[0] + matrix[1][1] * temp[1];
}
void mutiple(){
    uint64 tmp[4][4];
    REP(i, 2)
        REP(j, 2) tmp[i][j] = matrix[i][j];
        
    matrix[0][0] = tmp[0][0] * tmp[0][0] + tmp[0][1] * tmp[1][0];
    matrix[0][1] = tmp[0][0] * tmp[0][1] + tmp[0][1] * tmp[1][1];
    matrix[1][0] = tmp[1][0] * tmp[0][0] + tmp[1][1] * tmp[1][0];
    matrix[1][1] = tmp[1][0] * tmp[0][1] + tmp[1][1] * tmp[1][1];
}
void power(uint64 n){
    while ( n ){
        if (n & 1) mutiple_base();
        mutiple();
        n>>=1;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld %lld",&s,&q,&n);
        if (n == 0) printf("Case %d: 2\n",t);
        else {
            matrix[0][0] = s;
            matrix[0][1] = -q;
            matrix[1][0] = 1;
            matrix[1][1] = 0;
            ss[0] = s; ss[1] = 2;
            power( n - 1 );
            printf("Case %d: ",t);
            cout<<ss[0]<<endl;
        }
    }
    return 0;
}

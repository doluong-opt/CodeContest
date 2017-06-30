/***********************************************
* Author - LUONG VAN DO                        *
* 10655 - Contemplation - Algebra ->AC
* Algorithm mutiple matrix
* Time Limit 0.008s
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
int s, q, n;
int64 matrix[4][4];
int64 ss[4], ans;
void mutiple_base(){
    int64 temp[4];
    temp[0] = ss[0]; temp[1] = ss[1];
    ss[0] = matrix[0][0] * temp[0] + matrix[0][1] * temp[1];
    ss[1] = matrix[1][0] * temp[0] + matrix[1][1] * temp[1];
}
void mutiple(){
    int64 tmp[4][4];
    REP(i, 2)
        REP(j, 2) tmp[i][j] = matrix[i][j];
        
    matrix[0][0] = tmp[0][0] * tmp[0][0] + tmp[0][1] * tmp[1][0];
    matrix[0][1] = tmp[0][0] * tmp[0][1] + tmp[0][1] * tmp[1][1];
    matrix[1][0] = tmp[1][0] * tmp[0][0] + tmp[1][1] * tmp[1][0];
    matrix[1][1] = tmp[1][0] * tmp[0][1] + tmp[1][1] * tmp[1][1];
}
void power(int64 n){
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
    int test, m, ind, l;
    int xx[4];
    char sq[1001];
    while ( gets(sq) ){
        l = strlen(sq); ind = 0;
        m = 0;
        while (ind < l) {
            while (ind < l && sq[ind]==' ') ++ind;
            sscanf(sq + ind,"%d",&xx[++m]);
            while (ind < l && sq[ind]!=' ') ++ind;
        }
        if (m == 2 && xx[1] == 0 && xx[2] == 0) break;
        s = xx[1];
        q = xx[2];
        n = xx[3];
        if (n == 0) printf("2\n");
        else {
            matrix[0][0] = s;
            matrix[0][1] = -q;
            matrix[1][0] = 1;
            matrix[1][1] = 0;
            ss[0] = s; ss[1] = 2;
            power( n - 1 );
            cout<<ss[0]<<endl;
        }
    }
    return 0;
}

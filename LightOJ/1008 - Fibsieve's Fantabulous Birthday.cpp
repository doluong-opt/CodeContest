/***********************************************
* Author - LUONG VAN DO                        *
* 1008 - Fibsieve's Fantabulous Birthday ->AC
* Algorithm Adhoc
* Time Limit 0.003s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
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
uint64 s;
uint64 col,row;
void solve() {
    uint64 m = (uint64)ceil(sqrt(s));
    uint64 temp = (m - 1) * (m - 1);
    s-=temp;
    if ( ( m - 1) % 2 == 0 ) {
        col = m - 1;
        row = 1;
        if (s <= m) {
            col++;
            row+=(s - 1);
        }
        else {
            row = m;
            s-=(m + 1);
            col-=s;
        }
    }
    else {
        col = 1;
        row = m - 1;
        if ( s <= m ) {
            row++;
            col+=(s - 1);
        }
        else {
            col = m;
            s-=(m + 1);
            row-=s;
        }
    }
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld",&s);
        solve();
        printf("Case %d: ",t);
        cout << col <<" "<< row <<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

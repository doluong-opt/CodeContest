/***********************************************
* Author - LUONG VAN DO                        *
* 1053 - Higher Math ->AC
* Algorithm Adhoc
* Time Limit 0.000 
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
int64 x[4];
bool check() {
    sort(x,x+3);
    return (x[0] * x[0] + x[1] * x[1] == x[2] * x[2]);
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++){
        scanf("%lld %lld %lld",&x[0],&x[1],&x[2]);
        if ( check() ) printf("Case %d: yes\n",t);
        else printf("Case %d: no\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

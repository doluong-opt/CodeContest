/***********************************************
* Author - LUONG VAN DO                        *
* 1275 - Internet Service Providers ->AC
* Algorithm math
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
#define INF 10000000000000LL
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
void Read() {
    int test;
    int64 N,C, ans,rs1,rs2;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld %lld",&N,&C);
        printf("Case %d: ",t);
        if (!N || !C) printf("0\n");
        else {
            if ( C % ( 2 * N ) == 0) ans = C / (2 * N);
            else {
                rs1 = C / (2 * N);
                rs2 = rs1 + 1;
                if ( rs1 * (C - rs1 * N) >= rs2 * (C - rs2 * N) ) ans = rs1;
                else ans = rs2;
            }
            printf("%lld\n",ans);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

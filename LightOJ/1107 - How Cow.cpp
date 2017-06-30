/***********************************************
* Author - LUONG VAN DO                        *
* 1107 - How Cow ->AC
* Algorithm Adhoc
* Time Limit 0.000s
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
int a1,a2,b1,b2;
bool inSide(int a, int b){
    return ( a >= a1 && a <= a2 && b >= b1 && b <= b2);
}
void Read(){
    int test,q,a,b;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
        printf("Case %d:\n",t);
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&a,&b);
            if ( inSide(a,b) ) printf("Yes\n");
            else printf("No\n");
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

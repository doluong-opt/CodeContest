/***********************************************
* Author - LUONG VAN DO                        *
* 1015 - Brush (I) ->AC
* Algorithm Adhoc
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
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
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        int sum = 0,v,n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&v);
            if (v > 0) sum+=v;
        }
        printf("Case %d: %d\n",t,sum);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

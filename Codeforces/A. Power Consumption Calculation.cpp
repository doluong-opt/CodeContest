/***********************************************
* Author - LUONG VAN DO                        *
* A. Power Consumption Calculation ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
#define maxN 101
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,p1,p2,p3,t1,t2;
int l[maxN], r[maxN];
void Read_Input(){
    scanf("%d %d %d %d %d %d",&n,&p1,&p2,&p3,&t1,&t2);
    For(i,1,n) scanf("%d %d",&l[i],&r[i]);
    int ans = (r[1] - l[1]) * p1;
    for (int i=2;i<=n;i++) {
        int d = l[i] - r[i-1];
        ans+=min(d,t1) * p1;
        d = max(0, d-t1);
        ans+=min(d,t2) * p2;
        d = max(0, d-t2);
        ans+=d * p3;
        ans+=(r[i] - l[i]) * p1;
    }
    printf("%d\n",ans);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
    return 0;
}

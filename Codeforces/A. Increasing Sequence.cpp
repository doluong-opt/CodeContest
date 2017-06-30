/***********************************************
* Author - LUONG VAN DO                        *
* A. Increasing Sequence ->AC
* Algorithm Adhoc
* Time Limit 10ms
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
#define maxN 2001
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN];
int n,d;
void Read_Input(){
    scanf("%d %d",&n,&d);
    For(i,1,n) scanf("%d",&a[i]);
    int ans = 0;
    for (int i=2;i<=n;i++) {
        if (a[i] > a[i-1]) continue;
        int x = (a[i-1] - a[i]) / d + 1;
        ans+=x;
        a[i]+=x * d;
    }
    cout << ans <<endl;
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

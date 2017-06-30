/***********************************************
* Author - LUONG VAN DO                        *
* 10656 - Maximum Sum (II) ->AC
* Algorithm Greedy
* Time Limit 0.052s
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
int a[maxN], n;
int sum[maxN];
void process(){
    int p1,p2, Max;
    Max = -1;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++)
        if (sum[j] - sum[i-1] > Max) {
            Max = sum[j] - sum[i-1];
            p1 = i;
            p2 = j;
        }
        else
        if (sum[j] - sum[i-1]==Max && j-i<p2-p1) {
            p1 = i;
            p2 = j;
        }
    }
    printf("%d",a[p1]);
    for (int i=p1+1;i<=p2;i++)
        if (a[i]) printf(" %d",a[i]);
    puts("");
}
void Read_Input(){
    while ( scanf("%d",&n) && n) {
        sum[0] = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        process();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

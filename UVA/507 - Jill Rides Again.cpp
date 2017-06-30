/***********************************************
* Author - LUONG VAN DO                        *
* 507 - Jill Rides Again ->AC
* Algorithm dp
* Time Limit 0.144s
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
void Read_Input(){
    int test,p1,p2,Max;
    scanf("%d",&test);
    for (int k=1;k<=test;k++) {
        scanf("%d",&n);
        sum[0] = 0; Max = -1;
        for (int i=1;i<=n-1;i++) {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        int pos = 1;
        for (int i=1;i<=n-1;i++) {
            if ( sum[i] - sum[pos-1] > Max) {
                Max = sum[i] - sum[pos-1];
                p1 = pos;
                p2 = i;
            }
            else
            if ( sum[i] - sum[pos-1] == Max && i - pos> p2 - p1) {
                p1 = pos;
                p2 = i;
            }
            else
            if ( sum[i] - sum[pos-1] < 0) pos = i + 1;
        }
        if (Max < 0)
            printf("Route %d has no nice parts\n",k);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",k,p1,p2+1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

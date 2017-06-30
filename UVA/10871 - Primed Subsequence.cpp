/***********************************************
* Author - LUONG VAN DO                        *
* 10871 - Primed Subsequence ->AC
* Algorithm Adhoc
* Time Limit 0.012s
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
int n,l,r;
int sum[maxN];
int a[maxN];
bool Check(int m){
    for (int i=2;i*i<=m;i++)
        if (m % i==0) return false;
    return true;
}
void Read_Input(){
    int t;
    for (scanf("%d",&t); t--;) {
        scanf("%d",&n);
        sum[0] = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        l = 0;
        r = 10005;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n && j-i < r-l;j++) {
                if ( Check(sum[j]-sum[i-1]) ) {
                    l = i;
                    r = j;
                }
            }
        if (l!=0) {
            printf("Shortest primed subsequence is length %d:",r-l+1);
            for (int i=l;i<=r;i++)
                printf(" %d",a[i]);
            puts("");
        }
        else puts("This sequence is anti-primed.");
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

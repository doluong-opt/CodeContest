/***********************************************
* Author - LUONG VAN DO                        *
* 11413 - Fill the Containers ->AC
* Algorithm b_search
* Time Limit 0.008s
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
int a[maxN], n, k;
int R,L,res,best;
bool Check(int M){
    int sum = 0;
    int j = 0;
    best = -INF;
    for (int i=1;i<=n;i++) {
        if ( sum + a[i] <=M ) sum+=a[i];
        else {
            if (sum == 0) best = max(best, a[i]);
            else best = max(best, sum);
            sum = a[i];
            j++;
        }
    }
    best = max(best, sum);
    j++;
    return (j<=k);
}
int bs(){
    res = INF;
    while (L<=R) {
        int mid = ( L + R ) >> 1;
        if ( Check( mid ) ) {
            res = min(res, best);
            R = mid - 1;
        }
        else L = mid + 1;
    }
    return res;
}
void Read_Input(){
    while (scanf("%d %d",&n,&k)!=EOF){
        R = 0; L = INF;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            R+=a[i];
            L = min(L,a[i]);
        }
        printf("%d\n",bs());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1307 - Counting Triangles ->AC
* Algorithm chat nhi phan
* Time Limit 0.448s
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
#define maxN 2001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN], n;
int bs(int x, int L, int R){
    while (L<=R) {
        int mid = (L + R) >> 1;
        if ( a[mid] < x) L = mid + 1;
        else R = mid - 1;
    }
    return R;
}
int64 solve(){
    int64 res = 0;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++) {
            int pos = bs(a[i]+a[j], j+1, n-1);
            res+=(pos - j);
        }
    return res;
}
void Read(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for (int i=0;i<n;i++) cout<<a[i]<<endl;
        printf("Case %d: ",t);
        printf("%lld\n",solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

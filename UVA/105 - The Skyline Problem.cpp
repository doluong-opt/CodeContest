/***********************************************
* Author - LUONG VAN DO                        *
* 105 - The Skyline Problem ->AC
* Algorithm Adhoc
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
#define maxN 10005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int w[maxN];
int l,r,h;
void Read_Input() {
    while ( scanf("%d %d %d",&l,&h,&r)!=EOF ){
        for (int i=l;i<r;i++)
            w[i] = max(w[i], h);
    }
    l = r = -1; h = 0;
    for (int i=0;i<=10000;i++) {
        if (h!=w[i]) {
            if (l > 0) printf("%d %d ",l,r);
            h = w[i];
            l = i;
            r = h;
        }
    }
    printf("%d %d\n",l,r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

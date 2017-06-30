/***********************************************
* Author - LUONG VAN DO                        *
* 1098 - A New Function ->AC
* Algorithm math
* Time Limit 0.445s
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
int n;
int64 cal(int64 a, int64 b){
    if ( a > b) return 0;
    return ( (a + b) * (b - a + 1) ) / 2;
}
int64 solve(){
    int64 cnt, res, a, b,p1,p2, len;
    int64 m = (int64)sqrt(n);
    cnt = 1; res = len = 0; b = n / 2;
    if (n<=3) return 0;
    if (n<=5) return 2;
    
    p1 = (n / 2) - 1;
    res+=(p1 * 2);
    len++;
    for (int i=3;i<=m;i++) {
        p2 = (n / i) - 1;
        res+=(p2 * i);
        len++;
        a = b - (p1 - p2) + 1;
        res+=(cnt * cal(a,b));
        cnt++;
        len+=(p1 - p2);
        p1 = p2;
        b = a - 1;
    }
    while ( len < n / 2 - 1 ) {
        m++;
        res+=((n / m) - 1) * m;
        len++;
    }
    return res;
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int i=1;i<=test;i++) {
        scanf("%d",&n);
        printf("Case %d: %lld\n",i,solve());
    }
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    return 0;
}

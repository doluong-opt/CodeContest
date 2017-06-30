/***********************************************
* Author - LUONG VAN DO                        *
* 719 - Glass Beads
* Algorithm Minmove
* Time Limit 0.02s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 10001
using namespace std;
char s[maxN];
int l;
void Solve(){
    int a,m,b,tt;
    a = m = 0; b = 1;
    while (b < l && a + m + 1 < l) {
        tt = s[(a + m) % l] - s[(a + b) % l];
            if (!tt) ++a;
        else
            if (tt < 0) b = b + a + 1, a = 0;
        else {
            m = max(a + m + 1, b);
            b = m + 1;
            a = 0;
        }
    }
    printf("%d\n",m + 1);
}
void Read_Input(){
    int t;
    scanf("%d ",&t);
    while (t--){
        gets(s);
        l = strlen(s);
        Solve();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

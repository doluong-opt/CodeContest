/***********************************************
* Author - LUONG VAN DO                        *
* MINMOVE ->AC
* Algorithm Adhoc
* Time Limit 0.14s
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
#define maxN 100010
using namespace std;
char s[maxN];
int n,a,b,steps;
void Read_Input(){
    gets( s );
    n = strlen( s );
}
void Solve(){
    steps = a = 0; b = 1;
    while (b < n && steps + a + 1 < n) {
        int t = s[(steps + a) % n] - s[(a + b) % n];
        if ( !t ) a++;
        else
            if ( t < 0 ) b = b + a + 1, a = 0;
        else {
            steps = max(steps + a + 1,b);
            b = steps + 1;
            a = 0;
        }
    }
}
void Write_Output(){
    printf("%d\n",steps);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

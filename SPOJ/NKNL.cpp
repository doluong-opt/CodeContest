/***********************************************
* Author - LUONG VAN DO                        *
* NKNL ->AC
* Algorithm MinMove
* Time Limit 1.84s
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
#define maxN 255
using namespace std;
char s[maxN];
int64 cnt;
int l;
void Read_Input(){
    gets( s );
    l = strlen(s);
}
bool Check(int u, int v){
    char ss[maxN];
    int n = 0;
    for (int i=u;i<=v;i++)
        ss[n++] = s[i];
        ss[n] = '\0';
    int m,a;
    a = m = 0;
    int b = 1;
    while (b < n && m + a + 1 < n) {
        if ( ss[(m + a) % n] == ss[(a + b) % n] ) a++;
        else
            if ( ss[(m + a) % n] < ss[(a + b) % n] ) b = b + a + 1, a = 0;
        else
        {
            m = max(m + a + 1,b);
            b = m + 1;
            a = 0;
        }
    }
    if (!m) return true;
    return false;
}
void Solve(){
    cnt = 0;
    for (int i=0;i<l;i++)
        for (int j=i+4;j<l;j++) {
            if ( Check(i,j) )
                cnt++;
        }
}
void Write_Output(){
    printf("%lld\n",cnt);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

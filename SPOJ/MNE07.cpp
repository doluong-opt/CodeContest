/***********************************************
* Author - LUONG VAN DO                        *
* MNE07 ->AC
* Algorithm KMP
* Time Limit 0.23s
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
#define maxN 5001
using namespace std;
char s[maxN], t[maxN];
int Next[3*maxN];
int ck[3*maxN];
int n,m,Run;
void Read_Input(){
    scanf("%s",&t);
    scanf("%s",&s);
    n = strlen(t);
    Run = 2 * n - 2;
}
void PreKmp(){
    int i,j;
    i = 0;
    j = Next[0] = -1;
    while (i < n)
    {
        while ( j > -1 && t[i]!=t[j] ) j = Next[j];
        ++i; ++j;
        if ( t[i]==t[j] )
            Next[i] = Next[j];
        else
            Next[i] = j;
    }
}
bool KMP(char w[], int m){    
    int i,j;
    i = j = 0;
    while ( j < m )
    {
        while ( i > -1 && t[i]!=w[j]) i = Next[i];
        ++i; ++j;
        if (i>=n)
        {
            return true;
            i = Next[i];
        }
    }
    return false;
}
void Solve(){
    int u,v,m,found,u1,v1;    
    char w[maxN];
    found = 0;
    PreKmp();
    For(k,1,n-1)
    {
        m = u = 0; v = k;
        for (int j=1;j<=Run;j++)
        {
            w[m++] = max(s[(u + 1) % n] - '0',s[( v + 1) % n] - '0') + 48;
            u = (u + 1) % n;
            v = (v + 1) % n;
        }
        w[m] = '\0';
        Run--;
        if ( KMP(w,m) )
        {
            found = 1;
            break;
        }
    }
    if  (found) puts("Yes");
    else puts("No");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}

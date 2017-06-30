/***********************************************
* Author - LUONG VAN DO                        *
* NKH ->AC
* Algorithm Backtraking
* Time Limit 0.01s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define maxN 105
using namespace std;
string s1,s2,s;
int found;
int res[maxN*5];
void Read_Input(){
    cin >> s1 >> s2 >> s;
    found = 0;
}
void Solve(int vt, int x, int y){
    if ( found ) return;
    if (x == s1.length() && y==s2.length() )
    {
        found = 1;
        return;
    }
    if ( x < s1.length() && s[vt]==s1[x])
    {
        res[vt] = 1;
        Solve(vt+1,x+1,y);
    }
    if ( found ) return;
    if ( y < s2.length() && s[vt]==s2[y])
    {
        Solve(vt+1,x,y+1);
        res[vt] = 2;
    }
}
void Write_Output(){
    Rep(i,s.length())
        printf("%d",res[i]);
    printf("\n");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve(0,0,0);
    Write_Output();
}

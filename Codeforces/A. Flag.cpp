/***********************************************
* Author - LUONG VAN DO                        *
* A. Flag ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
int r,c;
char s[101][101];
void Read_Input(){
    bool ok = 1;
    scanf("%d %d ",&r,&c);
    Rep(i,r) gets(s[i]);
    for (int i=0;i<r && ok;i++)
        for (int j=0;j<c && ok;j++) {
            if (j+1<c && s[i][j]!=s[i][j+1]) ok = 0;
            if (i-1>=0 && s[i-1][j]==s[i][j]) ok = 0;
            if (i+1<r && s[i+1][j]==s[i][j]) ok = 0;
        }
    if (ok) puts("YES");
    else puts("NO");
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
    return 0;
}

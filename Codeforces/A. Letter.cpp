/***********************************************
* Author - LUONG VAN DO                        *
* A. Letter ->AC
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
char s[51][51];
int r,c;
void Read_Input(){
    scanf("%d %d ",&r,&c);
    Rep(i,r) gets(s[i]);
    int r1,r2,c1,c2;
    r1 = c1 = 101;
    r2 = c2 = -1;
    Rep(i,r) {
        Rep(j,c)
            if (s[i][j]=='*') {
                r1 = min(r1,i);
                c1 = min(c1,j);
                r2 = max(r2,i);
                c2 = max(c2,j);
            }
    }
    for (int i=min(r1,r2);i<=max(r1,r2);i++) {
        for (int j=min(c1,c2);j<=max(c1,c2);j++)
        cout <<s[i][j];
        cout<<endl;
    }
            
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

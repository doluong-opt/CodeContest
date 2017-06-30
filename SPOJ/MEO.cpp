/***********************************************
* Author - LUONG VAN DO                        *
* MEO 50
* Algorithm Adhoc
* Time Limit 0.64s
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
#define maxN 50001
using namespace std;
int n,k;
char s[10001];
void Read_Input(){
    scanf("%d %d ",&n,&k);
    gets(s);
}
void Solve(){
    for (int i=1;i<=k;i++)
    {
        for (int j=0;j<n;j++)
            if ( (s[j]=='G' && s[(j + 1) % n]=='R') || (s[j]=='R' && s[(j + 1) % n]=='G') )
            {
                s[j] = s[(j + 1) % n] = 'W';
                //cout<<s<<endl;
            }
            else
            if ( (s[j]=='G' && s[(j + 1) % n]=='W') || (s[j]=='W' && s[(j + 1) % n]=='G') )
            {
                s[j] = s[(j + 1) % n] = 'R';
                //cout<<s<<endl;
            }
            else
            if ( (s[j]=='R' && s[(j + 1) % n]=='W') || (s[j]=='W' && s[(j + 1) % n]=='R') )
            {
                s[j] = s[(j + 1) % n] = 'G';
                //cout<<s<<endl;
            }
    }
}
void Write_Output(){
    puts( s );
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

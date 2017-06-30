/***********************************************
* Author - LUONG VAN DO                        *
* A. Shortest path of the king ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
char s[3], e[3];
int rs;
void Read_Input(){
    gets(s);
    gets(e);
    rs = max(abs(s[0]-e[0]), abs(s[1]-e[1]));
    printf("%d\n",rs);
    while ( strcmp(s,e) ) {
        if (s[0] < e[0]) {
            printf("R");
            s[0]++;
        }
        if (s[0] > e[0]) {
            printf("L");
            s[0]--;
        }
        if (s[1] > e[1]) {
            printf("D");
            s[1]--;
        }
        if (s[1] < e[1]) {
            printf("U");
            s[1]++;
        }
        puts("");
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

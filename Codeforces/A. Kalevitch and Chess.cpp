/***********************************************
* Author - LUONG VAN DO                        *
* A. Kalevitch and Chess ->AC
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
char s[9][9];
void Read_Input(){
    int rs = 0;
    Rep(i,8) gets(s[i]);
    Rep(i,8)
        if (strcmp(s[i],"BBBBBBBB")==0) {
            rs++;
            strcpy(s[i],"WWWWWWWW");
        }
    Rep(i,8)
        Rep(j,8)
            if (s[j][i]=='B') {
                rs++;
                break;
            }
    cout << rs <<endl;
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

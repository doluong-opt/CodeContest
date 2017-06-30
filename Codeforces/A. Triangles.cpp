/***********************************************
* Author - LUONG VAN DO                        *
* A. Triangles ->AC
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
int x[3], y[3];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool check(){
    int a,b,c;
    a = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
    b = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
    c = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);
    return (a && b && c) && ( (a + b==c) || (a + c == b) || (c + b == a) );
}
void Read_Input(){
    Rep(i,3) scanf("%d %d",&x[i],&y[i]);
    if ( check() ){
        puts("RIGHT");
        return;
    }
    Rep(i,3) {
        Rep(k,4) {
            x[i]+=dx[k];
            y[i]+=dy[k];
            if (check()) {
                puts("ALMOST");
                return;
            }
            x[i]-=dx[k];
            y[i]-=dy[k];
        }            
    }
    puts("NEITHER");
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

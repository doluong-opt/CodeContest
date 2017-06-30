/***********************************************
* Author - LUONG VAN DO                        *
* C. Beaver Game ->AC
* Algorithm Game
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
int n,m,k;
void Read_Input(){
    cin >> n >> m >> k;    
}
bool Solve(){
    int found = false;
    for (int i=1;i*i<=m;i++) {
        if (m%i==0) {
            if (i>1 && m/i>=k) {
                found = true;
                break;
            }
            if (i>=k && m/i>1) {
                found = true;
                break;
            }
        }
    }
    if (!found) return false;
    else
    if (n%2==1) return true;
    else return false;
}
void Write_Output(){
    if (Solve()) puts("Timur");
    else puts("Marsel");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

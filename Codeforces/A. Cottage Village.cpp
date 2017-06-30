/***********************************************
* Author - LUONG VAN DO                        *
* A. Cottage Village ->AC
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
pair<int, int> ii[1001];
//typedef vector<ii> vii;
//typedef vector<int> vi;
int n,t;
void Read_Input(){
    int rs = 2;
    scanf("%d %d",&n,&t);
    Rep(i,n) scanf("%d %d",&ii[i].A,&ii[i].B);
    sort(ii,ii+n);
    for (int i=0;i<n-1;i++) {
        int r = 2 * (ii[i+1].A - ii[i].A) - ii[i].B - ii[i+1].B - 2 * t;
        rs+=(r>=0) + (r>0);
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

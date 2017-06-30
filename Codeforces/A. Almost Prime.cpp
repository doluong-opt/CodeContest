/***********************************************
* Author - LUONG VAN DO                        *
* A. Almost Prime ->AC
* Algorithm Adhoc
* Time Limit 50ms
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
int f[maxN],n;
bool Check(int m) {
    for (int i=2;i*i<=m;i++)
        if ( m % i == 0) return false;
    return true;
}
void Init(){
    int cnt;
    f[0] = f[1] = 0;
    for (int i=2;i<=3000;i++) {
        cnt = 0;
        for (int j=2;j<=i-1;j++)
            if (i % j ==0 && Check(j) ) cnt++;
        if (cnt==2) f[i] = f[i-1] + 1;
        else f[i] = f[i-1];
    }
    //for (int i=1;i<=3000;i++) cout<<f[i]<<endl;
}
void Read_Input() {
    Init();
    scanf("%d",&n);
    printf("%d\n",f[n]);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1010 - Knights in Chessboard ->AC
* Algorithm Adhoc
* Time Limit 0.027s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
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
int m,n;
void Read_Input(){
    int test,ans,x;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&m);
        if (n > m) swap(n,m);
            if (n == 1) ans = m;
        else
            if (n==2 && m<=4) ans = 4;
            else
            if (n == 2) {
                if ((m % 4) == 0) {
                    x = m / 4;
                    ans = 4 * x;
                }
                else {
                    x = (m / 4);
                    ans = 4 * x;
                    if ( (m - 1) % 4 == 0) ans+=2;
                    else ans+=4;
                }
            }
            else
            if (n % 2 == 0 || m % 2 == 0) {
                ans = ( n * m ) >> 1;
            }
            else
            if (n % 2!=0 && m % 2!=0) {
                ans = (n * m) >> 1;
                ans++;
            }
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    Read_Input();
    return 0;
}

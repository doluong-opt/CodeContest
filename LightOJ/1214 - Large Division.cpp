/***********************************************
* Author - LUONG VAN DO                        *
* 1214 - Large Division ->AC
* Algorithm adhoc
* Time Limit 0.002s
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

bool divisible(string x, int64 b){
    int64 hold = 0;
    int j;
    if (x[0] == '-') j = 1;
    else j = 0;
    for (int i=j;i<x.length();i++)
        hold = (hold * 10 + (x[i] - '0')) % b;
    if (hold) return false;
    return true;
}
void Read_Input(){
    int test;
    string x;
    int64 b;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        cin >> x >> b;
        if ( divisible(x, abs(b)) ) printf("Case %d: divisible\n",t);
        else printf("Case %d: not divisible\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

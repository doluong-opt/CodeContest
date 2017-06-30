/***********************************************
* Author - LUONG VAN DO                        *
* 1225 - Palindromic Numbers (II) ->AC
* Algorithm Adhoc
* Time Limit 0.011s
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
string s;
bool check(int x, int y){
    while ( x < y) {
        if (s[x]!=s[y]) return false;
        ++x; --y;
    }
    return true;
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int i=1;i<=test;i++) {
        cin >> s;
        printf("Case %d: ",i);
        if ( check(0,s.length()-1) ) puts("Yes");
        else puts("No");
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

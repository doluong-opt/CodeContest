/***********************************************
* Author - LUONG VAN DO                        *
* A. Chat room ->AC
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
char s[1001];
int l;
void Read_Input(){
    gets(s);
    l = strlen(s);
    int i,ok,cnt;
    i = cnt = 0;
    while (i < l && s[i]!='h' ) ++i;
        if (s[i]=='h') cnt++;
        ++i;
    while (i < l && s[i]!='e' ) ++i;
        if (s[i]=='e') cnt++;
        ++i;
    while (i < l && s[i]!='l' ) ++i;
        if (s[i]=='l') cnt++;
        ++i;
    while (i < l && s[i]!='l' ) ++i;
        if (s[i]=='l') cnt++;
        ++i;
    while (i < l && s[i]!='o' ) ++i;
        if (s[i]=='o') cnt++;
        ++i;
    if (cnt==5) puts("YES");
    else puts("NO");
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

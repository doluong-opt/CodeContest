/***********************************************
* Author - LUONG VAN DO                        *
* A. Lucky Division ->AC
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
char s[6];
int n;
bool Ok(int m){
    sprintf(s,"%d",m);
    for (int i=0;i<strlen(s);i++)
        if (s[i]!='4' && s[i]!='7') return false;
    return true;
}
bool check(){
    for (int i=4;i<=n;i++)
        if (n % i==0 && Ok( i ) ) return true;    
    return false;
}
void Read_Input(){
    scanf("%d",&n);
    if ( check() ) puts("YES");
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

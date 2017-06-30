/***********************************************
* Author - LUONG VAN DO                        *
* 10646 - What is the Card? ->AC
* Algorithm Adhoc
* Time Limit 0.012s
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
char type[55][5];
int val[maxN];
int cal(char c){
    for (char i='2';i<='9';i++)
        if ( i == c ) return (i - '0');
    return 10;
}
void Read_Input(){
    int test, value, y ,t;
    scanf("%d ",&test);
    for (int k=1;k<=test;k++) {
        for (int i=0;i<52;i++) {
            scanf("%s",type[i]);
            val[i] = cal(type[i][0]);
        }
        y = 0; t = 27;
        for (int i=1;i<=3;i++) {
            value = val[--t];
            y+=value;
            t-=(10-value);
        }
        printf("%d",y);
        if (y>=t) y = y - t + 26;
        printf("Case %d: %s\n",k,type[y]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

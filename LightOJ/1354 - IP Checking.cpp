/***********************************************
* Author - LUONG VAN DO                        *
* 1354 - IP Checking ->AC
* Algorithm Adhoc
* Time Limit 0.000s
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
char a[maxN], b[maxN];
int Pow[35];
int l1,l2;
void init(){
    Pow[0] = 1;
    for (int i=1;i<=8;i++)
        Pow[i] = Pow[i-1] * 2;
}
bool check(){
    int num1, num2, i,j, cnt;
    num1 = num2 = i = j = cnt = 0;
    while (i < l1 || j < l2) {
        num1 = num2 = cnt = 0;
        while ( i < l1 && a[i]!='.' ) num1 = num1 * 10 + (a[i++] - '0');
        i++;
        while ( j < l2 && b[j]!='.' ) {
            ++cnt;
            num2+=(b[j++] - '0') * Pow[8-cnt];
        }
        j++;
        if (num1!=num2) return false;
    }
    return true;
}
void Read(){
    int test;
    init();
    scanf("%d ",&test);
    for (int t=1;t<=test;t++) {
        gets(a); l1 = strlen(a);
        gets(b); l2 = strlen(b);
        if ( check() ) printf("Case %d: Yes\n",t);
        else printf("Case %d: No\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

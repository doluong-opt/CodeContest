/***********************************************
* Author - LUONG VAN DO                        *
* 1338 - Hidden Secret! ->AC
* Algorithm Adhoc
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
#define maxN 1001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char a[maxN], b[maxN];
int l1,l2;
int f[27];
bool check(){
    for (int i=0;i<26;i++) f[i] = 0;
    for (int i=0;i<l1;i++) {
        a[i] = tolower(a[i]);
        f[ a[i]-'a']++;
    }
    for (int i=0;i<l2;i++) {
        b[i] = tolower(b[i]);
        f[ b[i]-'a']++;
    }
    for (int i=0;i<26;i++)
        if ( f[i] && f[i] % 2) return false;
    return true;
}
void Read(){
    int test;
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

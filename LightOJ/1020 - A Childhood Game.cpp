/***********************************************
* Author - LUONG VAN DO                        *
* 1020 - A Childhood Game ->AC
* Algorithm game
* Time Limit 0.006s
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
int n;
char s[10];
void Read(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %s",&n,&s);
        printf("Case %d: ",t);
        if ( s[0] == 'A' && (n - 1) % 3 == 0) printf("Bob\n");
        if ( s[0] == 'A' && (n - 1) % 3 != 0) printf("Alice\n");
        if ( s[0] == 'B' && (n % 3) == 0) printf("Alice\n");
        if ( s[0] == 'B' && (n % 3) != 0) printf("Bob\n");
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

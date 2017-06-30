/***********************************************
* Author - LUONG VAN DO                        *
* 1261 - K-SAT Problem ->AC
* Algorithm Adhoc
* Time Limit 0.007s
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
#define maxN 35

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,m,k;
int Solution[maxN];
int Persons[maxN][maxN];
int Negative[maxN][maxN];
int Positive[maxN][maxN];
void reset(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            Persons[i][j] = 0;
            Negative[i][j] = 0;
            Positive[i][j] = 0;
        }
}
bool check(){
    int ok;
    for (int i=1;i<=n;i++) {
        ok = 0;
        for (int j=1;j<=m;j++)
            if ( (Negative[i][j] > 0 && Positive[i][j] > 0) || Persons[i][j] == Solution[j] ) {
                ok = 1;
                break;
            }
        if (!ok) return false;
    }
    return true;
}
void Read() {
    int test, object, p;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d %d",&n,&m,&k);
        reset();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++) {
                scanf("%d",&object);
                    if (object < 0) {
                        Persons[i][abs(object)] = -1;
                        Negative[i][abs(object)]++;
                    }
                    else {
                        Persons[i][object] = 1;
                        Positive[i][object]++;
                    }
            }
            
        for (int i=1;i<=m;i++) Solution[i] = -1;
        
        scanf("%d",&p);
        for (int i=1;i<=p;i++) {
            scanf("%d",&object);
            Solution[object] = 1;
        }
        if ( check() )
            printf("Case %d: Yes\n",t);
        else 
            printf("Case %d: No\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

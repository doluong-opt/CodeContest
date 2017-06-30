/***********************************************
* Author - LUONG VAN DO                        *
* 1133 - Array Simulation ->AC
* Algorithm Adhoc
* Time Limit 0.005s
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
#define maxN 105

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,m;
int64 a[maxN];
char s[15];
void Read() {
    int test;
    int64 D,M,N;
    char ch;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++) scanf("%lld",&a[i]);
        while (m--) {
            scanf(" %c",&ch);
            if (ch == 'S') {
                scanf("%lld ",&D);
                for (int i=0;i<n;i++) a[i]+=D;
            }
            else
            if (ch == 'M') {
                scanf("%lld ",&D);
                for (int i=0;i<n;i++) a[i]*=D;
            }
            else
            if (ch == 'D') {
                scanf("%lld ",&D);
                for (int i=0;i<n;i++) a[i]/=D;
            }
            else
            if (ch == 'R') {
                for (int i=0;i<n/2;i++)
                    swap(a[i], a[n-i-1]);
            }
            else
            if (ch == 'P') {
                scanf("%d %d ",&M,&N);
                swap(a[M], a[N]);
            }
        }
        printf("Case %d:\n",t);
        for (int i=0;i<n;i++) {
            if (i > 0) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

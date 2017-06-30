/***********************************************
* Author - LUONG VAN DO                        *
* 1023 - Discovering Permutations ->AC
* Algorithm adhoc
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
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,k;
int ans[100];
void Read_Input() {
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&k);
        for (int i=1;i<=n;i++) ans[i] = i;
        printf("Case %d:\n",t);
        do {
            for (int i=1;i<=n;i++) printf("%c",ans[i]+64);
            printf("\n");
            if (--k == 0) break;
        }while (next_permutation(ans+1,ans+n+1));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

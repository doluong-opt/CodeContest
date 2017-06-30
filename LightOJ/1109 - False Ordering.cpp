/***********************************************
* Author - LUONG VAN DO                        *
* 1109 - False Ordering  ->AC
* Algorithm Adhoc
* Time Limit 0.003s
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
#define maxN 1005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int numdiv, ind, val;
    node(){}
    node(int div, int id, int value){
        numdiv = div; ind = id; val = value;
    }
};
node ans[maxN];
bool cmp(node x, node y){
    if (x.numdiv!=y.numdiv) return x.numdiv < y.numdiv;
    return x.val > y.val;
}
void init(){
    int cnt;
    for (int i=1;i<=1000;i++) {
        cnt = 0;
        for (int j=1;j<=i;j++)
            if (i % j == 0) cnt++;
        ans[i] = node(cnt, i, i);
    }
    sort(ans+1,ans+1001,cmp);
}
void Read(){
    int test,n;
    init();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        printf("Case %d: %d\n",t,ans[n].val);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1425 - The Monkey and the Oiled Bamboo ->AC
* Algorithm Adhoc
* Time Limit 0.246s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define M 100000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[M + 1], n;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, Ans, maxi, diff;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        a[0] = maxi = 0;
        FOR(i, 1, n) {
            scanf("%d",&a[i]);
            diff = a[i] - a[i-1];
            if (diff > maxi) maxi = diff;
        }
        Ans = maxi;
        FOR(i, 1, n) {
            diff = a[i] - a[i-1];
            if (diff == maxi) maxi--;
            else
            if (diff > maxi) {
                Ans++;
                break;
            }
        }
        printf("Case %d: %d\n",t,Ans);
    }
}

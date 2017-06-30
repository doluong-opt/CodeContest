/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1389 - Scarecrow ->AC
* Algorithm Greedy
* Time Limit 0.002s
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
#define M 100

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
char s[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, cnt, Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf(" %d ",&n);
        gets(s); cnt = Ans = 0;
        REP(i, n) {
            if (s[i] == '.') {
                cnt++;
                if (cnt == 3) {
                    Ans++;
                    cnt = 0;
                }
            }
            else {
                if (cnt == 2) {
                    Ans++;
                    cnt = 0;
                }
                if (cnt == 1 && (s[i+1]=='.' || s[i+1] =='#')) {
                    Ans++;
                    cnt = 0;
                    i++;
                }
            }
        }
        if (cnt) Ans++;
        printf("Case %d: %d\n",t,Ans);
    }
}

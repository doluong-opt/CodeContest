/***********************************************
* Author - LUONG VAN DO                        *
* 10660 - Citizen attention offices ->AC
* Algorithm Recur
* Time Limit 0.106s
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
#define maxN 101
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int data[maxN][5];
int x[maxN], y[maxN];
int n, res[maxN], best;

int dist(int x1, int y1, int x2, int y2){
    return (abs(x1 - x2) + abs(y1 - y2));
}
void Recur(int xx, int cnt) {
    if (cnt == 5) {
        int sum = 0;
        REP(i, n) {            
            int MIN = INF;
            REP(j, 5)
                MIN = min(MIN, dist(x[j], y[j], data[i][0], data[i][1]));
            sum += MIN * data[i][2];
        }
        if (sum < best) {
            best = sum;
            REP(i, 5)
                res[i] = x[i] * 5 + y[i];
        }
        return;
    }
    FOR(i, xx, 25) {
        x[cnt] = i / 5;
        y[cnt] = i % 5;
        Recur(i + 1,cnt + 1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, x, y, c;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        REP(i, maxN)
            REP(j, 3)
                data[i][j] = 0;
        REP(i, n) {
            scanf("%d %d %d",&x,&y,&c);
            data[i][0] = x; data[i][1] = y; data[i][2] = c;
        }
        best = INF;
        Recur(0, 0);
        REP(i, 5) {
            if (i > 0) printf(" ");
            printf("%d",res[i]);
        }
        printf("\n");
    }
    return 0;
}

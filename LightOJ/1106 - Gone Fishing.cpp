/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1111

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[26][N], f[N], d[N], t[N], numberOfMinute[N];
int n, h, allTime, res;
int run(int curLake, int curTime) {
    if (curTime >= allTime) return 0;
    if (curLake >= n + 1) return 0;
    int &res = dp[curLake][curTime];
    if (res != -1) return res;
    res = 0;
    int k = (allTime - curTime) / 5;
    int numberFish, nextTime;
    for (int i = k;i > 0;i--) {
        numberFish = f[curLake];
        for (int j = 1;j < i;j++)
            numberFish += max(0, f[curLake] - d[curLake] * j);
        nextTime = curTime + (5 * i) + t[curLake] * 5;
        res = max(res, numberFish + run(curLake + 1, nextTime));
    }
    res = max(res, run(curLake + 1, curTime + t[curLake] * 5));
    return res;
}
void findSolve(int curLake, int curTime, int maxFish) {
    if (curTime >= allTime) return;
    if (curLake >= n + 1) return;
    int k = (allTime - curTime) / 5;
    int tempFish, nextTime, numberFish;
    for (int i = k;i > 0;i--) {
        numberFish = f[curLake];
        for (int j = 1;j < i;j++)
            numberFish += max(0, f[curLake] - d[curLake] * j);
        nextTime = curTime + (5 * i) + t[curLake] * 5;
        tempFish = numberFish + run(curLake + 1, nextTime);
        if (tempFish == maxFish) {
            numberOfMinute[curLake] = 5 * i;
            findSolve(curLake + 1, nextTime, maxFish - numberFish);
            return;
        }
    }
    tempFish = run(curLake + 1, curTime + t[curLake] * 5);
    if (tempFish == maxFish) findSolve(curLake + 1, curTime + t[curLake] * 5, maxFish);
    return;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &n, &h);
	    allTime = h * 60;
	    fr(i, 1, n) {
            scanf("%d", &f[i]);
            numberOfMinute[i] = 0;
	    }
	    fr(i, 1, n) scanf("%d", &d[i]);
	    fr(i, 1, n - 1) scanf("%d", &t[i]);
	    fill(dp, -1);
	    res = run(1, 0);
	    findSolve(1, 0, res);
	    printf("Case %d:\n", ++caseno);
	    fr(i, 1, n) {
            if (i > 1) printf(", ");
            printf("%d", numberOfMinute[i]);
	    }
	    puts("");
	    printf("Number of fish expected: %d\n", res);
	}
	return 0;
}

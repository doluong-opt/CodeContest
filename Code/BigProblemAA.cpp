/***********************************************
* Author - Group ???                           *
* Problem - Scheduling Fast Food Problem
* Algorithm - Brute force, Greedy....
* Time Limit - 60 seconds.
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
#define N 111
#define M 111
#define LMT 1000
#define MAX_LOG 20

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
int s, m, n, ind[M], bestTime;
int quantity[M], q[M], p[M], a[M];
int amount[N][M], finishTime[M], diff[M];
/* read input */
void setInput() {
    scanf("%d %d %d",&s, &m, &n);
    for (int i = 1;i <= m;i++) quantity[i] = 0;
    for (int i = 1;i <= m;i++) scanf("%d %d %d", &p[i], &q[i], &a[i]);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            scanf("%d", &amount[i][j]);
            quantity[j] += amount[i][j];
        }
}
/* process each permutaion for m machine */
bool notFinish() {
    for (int i = 1;i <= m;i++)
        if ( quantity[i] > 0 ) return false;
    return true;
}
/* find next machine which longest wait or .... */
int findNextPos(int startTime) {
    int maxDiff = -INF, posMachine = -1, remainItem = 0;
    for (int i = 1;i <= m;i++)
        diff[i] = startTime - finishTime[i];
    for (int i = 1;i <= m;i++) {
        if ( quantity[i] <= 0 ) continue;
        if ( maxDiff < diff[i] ) maxDiff = diff[i];
    }
    if (maxDiff < 0) return -1;
    for (int i = 1;i <= m;i++)
        if (maxDiff == diff[i] && remainItem < quantity[i] && quantity[i] > 0) {
            remainItem = quantity[i];
            posMachine = i;
        }
    return posMachine;
}/* main */
void process() {
    int startTime = 1, curMachine, tempBest = 0;
    while ( true ) {
        curMachine = findNextPos(startTime);
        //cout<<curMachine<<endl;
        if (1 <= curMachine && curMachine <= m) {
            finishTime[ curMachine ] = startTime + p[ curMachine ];
            quantity[ curMachine ] -= q[ curMachine ];
            cout<<curMachine<<" "<<startTime<<" "<<finishTime[curMachine]<<endl;
            startTime++;
        }
        else startTime++;
        if ( notFinish() ) break;
    }
    for (int i = 1;i <= m;i++) 
        if (bestTime < finishTime[i]) bestTime = finishTime[i];
    //for (int i = 1;i <= m;i++) cout<<finishTime[i]<<" ";
    //cout<<endl;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	setInput();
	bestTime = 0;
    for (int i = 1;i <= m;i++) finishTime[i] = 0;
    process();
	cout << bestTime << endl;
	return 0;
}


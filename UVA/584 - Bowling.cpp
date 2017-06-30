/***********************************************
* Author - LUONG VAN DO                        *
* 584 - Bowling ->AC
* Algorithm Adhoc
* Time Limit 0.088s
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
#define maxN 30

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct frame{
    int re;
    int x, y;
    frame(){}
    frame(int rre, int xx, int yy){
        re = rre; x = xx; y = yy;
    }
};
frame m[maxN];
char input[100 + 5];
int n;
void Reset() {
    REP(i, 20)
        m[i].re = m[i].x = m[i].y = 0;
}
void Call() {
    int i, x;
    n = 0;
    for (i=0;input[i];) {
        if (input[i] == 'X') {
            m[n].re = 2;
            m[n].x = 10;
            ++n;
            i+=2;
        }
        else {
            x = input[i] - '0';
            m[n].x = x;
            if ( isdigit(input[i+2]) )
                m[n].y = input[i+2] - '0';
            else {
                m[n].y = 10 - (input[i] - '0');
                m[n].re = 1;
            }
            ++n;
            i+=4;
        }
    }
}
int Count(int x) {
    int rr = 0;
    if (m[x].re == 0) return m[x].x + m[x].y;
    if (m[x].re == 1)
        rr = m[x+1].x + 10;
    else {
        rr = 10 + m[x+1].x;
        if ( m[x+1].re == 2 ) rr+=m[x+2].x;
        else rr+=m[x+1].y;
    }
    return rr;
}
void Solve() {
    int res;
    res = 0;
    REP(i, 10)
        res+=Count( i );
    printf("%d\n",res);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    while ( gets(input) ) {
        if ( strcmp(input, "Game Over") == 0) break;
        Reset();
        Call();
        Solve();
    }
    return 0;
}

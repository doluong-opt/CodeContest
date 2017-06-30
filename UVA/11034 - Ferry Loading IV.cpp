/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11034 - Ferry Loading IV ->AC
* Algorithm queue
* Time Limit 0.016s
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
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, l, m, c;
    int Ans, x;
    char s[10];
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf(" %d %d ",&l,&m);
        l*=100; Ans = 0;
        queue <int> left, right;
        for (int i=0;i<m;i++) {
            scanf(" %d %s ",&c,&s);
            if (strcmp(s,"left") == 0) left.push(c);
            else right.push(c);
        }
        string bank = "left";
        while ( !left.empty() || !right.empty() ) {
            if (bank == "left") {
                x = 0;
                while ( !left.empty() && x + left.front() <= l) {
                    x+=left.front();
                    left.pop();
                }
                Ans++;
                bank = "right";
            }
            else {
                x = 0;
                while ( !right.empty() && x + right.front() <= l) {
                    x+=right.front();
                    right.pop();
                }
                Ans++;
                bank = "left";
            }
        }
        printf("%d\n",Ans);
    }
}

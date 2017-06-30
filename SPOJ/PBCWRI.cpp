/***********************************************
* Author LUONG VAN DO                        *
* Problem PBCWRI
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 100000
#define M 3000010
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int mark[N];
char s[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int i, ans, x, y, l1, l2;
    char c;
    ans = x = y = 0;
    scanf(" %d %d ", &l1, &l2);
    for (int i = 0;i < N;i++) mark[i] = 0;
    scanf("%s", s);
    for(i = 0;i < l1;i++)
        if ( ++mark[ s[i] ] == 1) x++;
    scanf("%s", s);
    for (i = 0;i < l1;i++) {
        mark[s[i]]--;
        if (mark[s[i]] == 0) x--;
        else if ( mark[s[i]] == -1) y++;
    }
    if (!x && !y) ans++;
    for (;i < l2;i++) {
        c = s[i - l1];
        mark[c]++;
        if (mark[c] == 0) y--;
        else if (mark[c] == 1) x++;
        c = s[i];
        mark[c]--;
        if (mark[c] == 0) x--;
        else if (mark[c] == -1) y++;
        if (!x && !y) ans++;
    }
    printf("%d\n", ans);
}

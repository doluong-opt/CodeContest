/***********************************************
* Author - LUONG VAN DO                        *
* 1293 - Document Analyzer ->AC
* Algorithm O(n)
* Time Limit 1.085s
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
#define maxN 100001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
map <string, int> M;
int m, a[maxN], n;
int inc[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, sz, ind, x, y, p, q;
    char s[10001];
    string ch;
    scanf(" %d ",&test);
    FOR(t, 1, test) {
        M.clear();
        sz = m = 0; ch = "";
        while ( gets(s) ) {
            if (strcmp(s, "END") == 0) break;
            n = strlen(s); ind = 0;
            while ( ind < n ) {
                while ( ind < n && (s[ind]<'a' || s[ind] > 'z')) ++ind;
                while ( ind < n && s[ind]>='a' && s[ind]<='z') {
                    ch+=s[ind];
                    ++ind;
                }
                
                if (ch.size() > 0 && !M[ch] ) M[ch] = ++sz;
                if (ch.size() > 0) a[++m] = M[ch];
                ch = "";
            }
        }
        int Count = 0;
        p = 1;
        q = INF;
        x = 1;
        y = 0;
        FOR(i, 1, sz) inc[i] = 0;
        FOR(i, 1, m) {
            if ( !inc[ a[i] ] ) {
                inc[ a[i] ]++;
                y++;
                Count++;
            }
            else
            if ( inc[a[x]] >= 1) {
                if (Count == sz && y - x < q - p) {
                    p = x;
                    q = y;
                }
                    while ( inc[a[x]] > 1) {
                        inc[a[x]]--;
                        ++x;
                    }
                if (Count == sz && y - x < q - p) {
                    p = x;
                    q = y;
                }
                inc[a[i]]++;
                y++;
            }
            if (Count == sz && y - x < q - p) {
                p = x;
                q = y;
            }
        }
        while (inc[a[x]] > 1) {
            inc[a[x]]--;
            ++x;
        }
        if (y - x < q - p) {
            p = x;
            q = y;
        }
        printf("Case %d: %d %d\n",t,p,q);
    }
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1396 - Palindromic Numbers (III) ->AC
* Algorithm adhoc
* Time Limit 0.118s
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
#define N 100010

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
char s[N], ans[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n, p;
    int l, r, x, y;
    scanf(" %d ",&cases);
    while (cases--) {
        gets(s); n = strlen(s);
        p = n / 2; l = 0; r = n - 1;
        memset(ans, 0, sizeof(ans));
        while ( l<=r ) {
            ans[l] = ans[r] = s[l];
            r--;
            l++;
        }
        printf("Case %d: ",++caseno);
        if (strcmp(ans, s) > 0) {
            for (int i=0;i<n;i++) cout<<ans[i];
            cout<<endl;
            continue;
        }
        if (n & 1) {
            l = 0;
            if (ans[p] == '9') {
                ans[p] = '0';
                l = p - 1; r = p + 1;
                while (l>=0) {
                    if (ans[l] == '9') {
                        ans[l] = '0';
                        ans[r] = '0';
                        r++;
                        l--;
                    }
                    else {
                        ans[l] = char(ans[l]-'0' + 49);
                        ans[r] = char(ans[r]-'0' + 49);
                        break;
                    }
                }
            }
            else ans[p] = char(ans[p]-'0' + 49);
            if (l < 0) {
                printf("1");
                for (int i=0;i<n-1;i++) cout<<ans[i];
                printf("1\n");
            }
            else {
                for (int i=0;i<n;i++) cout<<ans[i];
                cout<<endl;
            }
        }
        else {
            p--;
            x = p; y = p + 1;
            if (ans[x] == '9') {
                ans[x] = ans[y] = '0';
                x--; y++;
                while (x >= 0) {
                    if (ans[x] == '9') {
                        ans[x] = ans[y] = '0';
                        x--;
                        y++;
                    }
                    else {
                        ans[x] = char(ans[x]-'0' + 49);
                        ans[y] = char(ans[y]-'0' + 49);
                        break;
                    }
                }
            }
            else {
                ans[x] = char(ans[x]-'0' + 49);
                ans[y] = char(ans[y]-'0' + 49);
            }
            if (x < 0) {
                printf("1");
                for (int i=0;i<n-1;i++) cout<<ans[i];
                printf("1\n");
            }
            else {
                for (int i=0;i<n;i++) cout<<ans[i];
                cout<<endl;
            }
        }
    }
}

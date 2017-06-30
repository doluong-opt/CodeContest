/***********************************************
* Author - LUONG VAN DO                        *
* 1114 - Easily Readable ->AC
* Algorithm Map
* Time Limit 0.272s
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
#define maxN 50001
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
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, l, n, q, ind, nm;
    int64 ans;
    char s[100005], sss[100005];
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf(" %d ",&n);
        M.clear();
        REP(i, n) {
            gets(s); l = strlen(s);
            if (l > 2) sort(s + 1, s + l - 1);
            M[s]++;
        }
        printf("Case %d:\n",t);
        scanf(" %d ",&q);
        while (q--) {
            gets(s); l = strlen(s); ind = 0;
            ans = 1;
            while (ind < l) {
                while (ind < l && s[ind] == ' ') ++ind;
                nm = 0;
                while (ind < l && s[ind]!=' ') sss[nm++] = s[ind++];
                sss[nm] = '\0';
                
                if (nm > 2) sort(sss + 1, sss + nm - 1);
                ans*=M[sss];
                ++ind;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

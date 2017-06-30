/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11308 - Bankrupt Baker ->AC
* Algorithm Adhoc
* Time Limit 0.144s
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

typedef pair<string, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
string upper(string x) {
    for (int i=0;i<x.size();i++)
        x[i] = toupper(x[i]);
    return x;
}
bool cmp(ii a, ii b) {
    if (a.B != b.B) return a.B < b.B;
    return a.A < b.A;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, k, m, n, b, c;
    string s;
    char ch[100];
    scanf(" %d ",&cases);
    while ( cases-- ) {
        getline(cin, s);
        s = upper(s);
        cout<<s<<endl;
        map <string, int> types;
        vector <ii> res;
        scanf(" %d %d %d ",&m,&n,&b);
        for (int i=0;i<m;i++) {
            scanf(" %s %d ",ch,&c);
            types[ch] = c;
        }
        for (int i=0;i<n;i++) {
            getline(cin, s); int64 sum = 0;
            scanf(" %d ",&k);
            while (k--) {
                scanf(" %s %d ",ch,&c);
                sum+=(types[ch] * c);
            }
            if (sum<=b) res.pb(ii(s, sum));
        }
        if ( !res.size() ) {
            puts("Too expensive!");
            cout<<endl;
        }
        else {
            sort(res.begin(), res.end(), cmp);
            for (int i=0;i<res.size();i++)
                cout<<res[i].A<<endl;
                cout<<endl;
        }
    }
}

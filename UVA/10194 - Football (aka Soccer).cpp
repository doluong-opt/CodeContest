/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10194 - Football (aka Soccer) ->AC
* Algorithm adhoc
* Time Limit 0.012s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
struct football {
    string name;
    int p, lp, md;
    int ti[3], mx[2];
    football(){}
    football(string nn, int pp, int lpp, int mdd){
        name = nn; p = pp; lp = lpp; md = mdd;
    }
};
char s[N], title[N];
football data[N];
map <string, int> team;
int n;
void reset() {
    for (int i=0;i<n;i++) {
        data[i].p = data[i].lp = data[i].md = 0;
        data[i].ti[0] = data[i].ti[1] = data[i].ti[2] = 0;
        data[i].mx[0] = data[i].mx[1] = 0;
    }
}
string toUpper(string x) {
    for (int i=0;i<x.size();i++)
        x[i] = toupper(x[i]);
    return x;
}
void process(string s) {
    int m = s.length(), index = 0;
    int i1, i2, s1, s2;
    string ch;
    ch = ""; s1 = s2 = 0;
    while (index < m && s[index] != '#') ch+=s[index++];
    ++index;
    i1 = team[ch];
    while (index < m && s[index]!='@') s1 = s1 * 10 + (s[index++] - '0');
    ++index;
    while (index < m && s[index]!='#') s2 = s2 * 10 + (s[index++] - '0');
    ++index;
    ch = "";
    while (index < m) ch+=s[index++];
    i2 = team[ch];
    data[i1].lp++; data[i2].lp++;
    data[i1].mx[0]+=s1;
    data[i1].mx[1]+=s2;
    data[i2].mx[0]+=s2;
    data[i2].mx[1]+=s1;
    data[i1].md+=(s1 - s2);
    data[i2].md+=(s2 - s1);
    if (s1 > s2) {
        data[i1].p+=3;
        data[i1].ti[0]++;
        data[i2].ti[2]++;
    }
    else
    if (s1 < s2) {
        data[i2].p+=3;
        data[i1].ti[2]++;
        data[i2].ti[0]++;
    }
    else {
        data[i1].p++;
        data[i2].p++;
        data[i1].ti[1]++;
        data[i2].ti[1]++;
    }
}
bool cmp(football a, football b) {
    if (a.p != b.p) return a.p > b.p;
    if (a.ti[0] != b.ti[0]) return a.ti[0] > b.ti[0];
    if (a.md != b.md) return a.md > b.md;
    if (a.mx[0] != b.mx[0]) return a.mx[0] > b.mx[0];
    if (a.lp != b.lp) return a.lp < b.lp;
    return toUpper(a.name) < toUpper(b.name);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, m, blank = 0;
    scanf("%d ",&cases);
    while (cases--) {
        gets(title);
        scanf("%d ",&n); team.clear();
        for (int i=0;i<n;i++) {
            gets(s); data[i].name = s;
            team[data[i].name] = i;
        }
        reset();
        scanf("%d ",&m);
        while (m--) {
            gets(s);
            process( s );
        }
        sort(data, data + n, cmp);
        if ( blank ) puts("");
        blank = 1;
        cout<<title<<endl;
        for (int i=0;i<n;i++) {
            printf("%d) ",i + 1);
            cout<<data[i].name<<" ";
            printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",data[i].p,data[i].lp,data[i].ti[0],data[i].ti[1],data[i].ti[2],data[i].md,data[i].mx[0],data[i].mx[1]);
        }
    }
}

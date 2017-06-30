/***********************************************
* Author - LUONG VAN DO                        *
* Problem 755 - 487--3279 ->AC
* Algorithm Adhoc
* Time Limit 1.352s
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
char get(char c){
    if (c == 'A' || c == 'B' || c == 'C') return '2';
    if (c == 'D' || c == 'E' || c == 'F') return '3';
    if (c == 'G' || c == 'H' || c == 'I') return '4';
    if (c == 'J' || c == 'K' || c == 'L') return '5';
    if (c == 'M' || c == 'N' || c == 'O') return '6';
    if (c == 'P' || c == 'R' || c == 'S') return '7';
    if (c == 'T' || c == 'U' || c == 'V') return '8';
    if (c == 'W' || c == 'X' || c == 'Y') return '9';
}
bool cmp(ii a, ii b) {
    return (a.A < b.A);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, flag, n, l, ind;
    int blank = 0;
    char s[M];
    scanf("%d",&cases);
    while ( cases--) {
        scanf(" %d ",&n);
        map <string, int> phones;
        map <string, int> :: iterator id;
        flag = 0;
        while (n--) {
            gets(s);
            l = strlen(s); ind = 0;
            string num = "";
            while (ind < l) {
                while (ind < l && !isdigit(s[ind]) && !isalpha(s[ind])) ++ind;
                if (ind < l && s[ind] >='A' && s[ind]<='Z') num+=get(s[ind++]);
                else
                if (ind < l) num+=s[ind++];
                if (num.size() == 3) num+="-";
            }
            phones[num]++;
            if (phones[num] > 1) flag = 1;
        }
        if ( blank ) puts("");
        blank = 1;
        if ( !flag ) puts("No duplicates.");
        else {
            vector <ii> res;
            vector <ii> :: iterator it;
            for (id = phones.begin(); id!=phones.end(); id++)
                res.pb(ii(id->first, id->second));
            sort(res.begin(), res.end(), cmp);
            for (it=res.begin(); it!=res.end(); it++) {
                if (it->B > 1)
                    cout<<it->A<<" "<<it->B<<endl;
            }
        }
    }
}   

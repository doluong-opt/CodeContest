/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1309 - Children`s Math -->AC
* Algorithm 
* Time Limit 0.000s
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
#define N 100000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int64 gcd(int64 a, int64 b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Number{
    int64 a, b, op;
    char c;
    Number(){
        a = b = 0;
        op = -1;
    }
    Number(int64 oo, char cc){
        op = oo; c = cc;
    }
    Number(int64 aa, int64 bb, bool adas = true){
        a = aa; b = bb;
        op = -1;
    }
    Number computer(Number num, Number opr){
        if (opr.c == '+') {
            num.a = a + num.a;
            num.b = b + num.b;
        }
        else
        if (opr.c == '-') {
            num.a = a - num.a;
            num.b = b - num.b;
        }
        else
        if (opr.c == '*') {
            num.a = a * num.b + b * num.a;
            num.b = b * num.b;
        }
        return num;
    }
};
char str[110];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0;
    int64 x, y, d;
    string s;
    scanf(" %d ",&cases);
    while ( cases--) {
        s = "";
        gets(str); n = strlen(str);
        for (int i=0;i<n;i++)
            if (str[i] == '=' ) {
                for (int j=0;j<i;j++) s+=str[j];
                s+="-(";
                for (int j=i + 1;j<n;j++) s+=str[j];
                s+=")";
            }
        vector <Number> a;
        int i = 0, n = s.length();
        while (i < n) {
            while (i < n && s[i] == ' ') ++i;
            if ( i>=n )  break;
            if ( s[i] == 'x' ) {
                a.pb(Number(1, 0, true));
                ++i;
            }
            else
            if ( s[i] == '(' || s[i] == ')' ) {
                a.pb(Number(0, s[i]));
                ++i;
            }
            else
            if ( s[i] == '+' || s[i] == '-' ) {
                a.pb(Number(1, s[i]));
                ++i;
            }
            else
            if ( s[i] == '*' ) {
                a.pb(Number(2, s[i]));
                ++i;
            }
            else
            if (isdigit(s[i])) {
                int v = 0;
                while (i < n && isdigit(s[i])) v = v * 10 + s[i++] - '0';
                a.pb(Number(0, v, true));
            }
            else ++i;
        }
        vector <Number> post;
        stack <Number> st;
        for (int i=0;i<a.size();i++) {
            if (a[i].op == -1) post.pb( a[i] );
            else if (a[i].c == '(') st.push(a[i]);
            else if (a[i].c == ')') {
                while ( !st.empty() && st.top().c != '(' ) {
                    post.pb(st.top());
                    st.pop();
                }
                if (st.size()) st.pop();
            }
            else {
                while ( !st.empty() && a[i].op <= st.top().op ) {
                    post.pb(st.top());
                    st.pop();
                }
                st.push(a[i]);
            }
        }
        while ( !st.empty() ) {
            post.pb(st.top());
            st.pop();
        }
        st = stack <Number> ();
        for (int i=0;i<post.size();i++) {
            if (post[i].op == -1) st.push( post[i] );
            else {
                Number b = st.top(); st.pop();
                Number a = st.top(); st.pop();
                st.push(a.computer(b, post[i]));
            }
        }
        x = st.top().a;
        y = st.top().b;
        printf("Case %d: ",++caseno);
        if (x == 0 && y != 0) printf("no solution\n");
        else
        if (x == 0 && y == 0) printf("infinitely many solutions\n");
        else
        if ( y == 0 ) printf("0\n");
        else {
            d = gcd(abs(x), abs(y));
            x/=d; y/=d;
            y = -y;
            if ( y % x == 0 ) printf("%lld\n", y / x);
            else {
                if (x < 0) x = -x, y = -y;
                printf("%lld/%lld\n", y, x);
            }
        }
    }
}

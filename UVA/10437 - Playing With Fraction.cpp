/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10437 - Playing With Fraction
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
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

bool invalid;

struct Number{
    int64 a, b, op;
    char ch;
    Number(){
        a = b = 1LL;
        op = -1;
    }
    Number(int64 oo, char cc) {
        op = oo; ch = cc;
    }
    Number(int64 aa, int64 bb = 1LL, bool dad = true){
        a = aa; b = bb;
        op = -1;
    }
};

Number computer(Number x, Number y, Number opr) {
        if (y.b == 0) {
            invalid = true;
            return Number();
        }
        
        int64 f = gcd( abs(x.b), abs(y.b) );
        int64 f1 = gcd( abs(x.a), abs(x.b) );
        int64 f2 = gcd( abs(y.a), abs(y.b) );
        x.a/=f1; y.a/=f2;
        x.b/=f1; y.b/=f2;
        Number num;
        if (opr.ch == '-') {
            num.a = x.a * (y.b / f) - (x.b / f) * y.a;
            num.b = (y.b / f) * x.b;
        }
        else
        if (opr.ch == '+') {
            num.a = x.a * (y.b / f) + (x.b / f) * y.a;
            num.b = (y.b / f) * x.b;
        }
        else
        if (opr.ch == '*') {
            num.a = x.a * y.a;
            num.b = x.b * y.b;
        }
        else
        if (opr.ch == '|' || opr.ch == '/') {
            int64 xx = x.a * (y.b / f);
            int64 yy = (x.b / f) * y.a;
            num.a = xx; num.b = yy;
        }
    
    if (num.b == 0) {
        invalid = true;
        return Number();
    }
    f = gcd(abs(num.a), abs(num.b));
    num.a/=f;
    num.b/=f;
    return num;
}
char str[600];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string s;
    int64 x, y, d;
    while ( gets(str)) {
        s = str; invalid = false;
        int i = 0, n = s.length();
        vector <Number> a;
        while (i < n) {
            while (i < n && s[i] == ' ') ++i;
            if (i >= n) break;
            if (s[i] == '(' || s[i] == ')') {
                a.pb(Number(0, s[i]));
                ++i;
            }
            else
            if (s[i] == '+' || s[i] == '-') {
                a.pb(Number(1, s[i]));
                ++i;
            }
            else
            if (s[i] == '*' || s[i] == '/' || s[i] == '|') {
                a.pb(Number(2, s[i]));
                ++i;
            }
            else
            if (isdigit(s[i])) {
                int64 v = 0;
                while (i < n && isdigit(s[i])) v = v * 10 + s[i++] - '0';
                a.pb(Number(v, 1LL, true));
            }
            else ++i;
        }
        vector <Number> post;
        stack <Number> st;
        for (int i=0;i<a.size();i++) {
            if (a[i].op == -1) post.pb( a[i] );
            else if (a[i].ch == '(') st.push( a[i] );
            else if (a[i].ch == ')') {
                while ( !st.empty() && st.top().ch !='(') {
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
                st.push( a[i] );
            }
        }
        while ( !st.empty()) {
            post.pb(st.top());
            st.pop();
        }
        st = stack<Number>();
        if ( !invalid ) {
            for (int i=0;i<post.size();i++)
                if (post[i].op == -1) st.push( post[i] );
                else {
                    Number y = st.top(); st.pop();
                    Number x = st.top(); st.pop();
                    st.push(computer(x, y, post[i]));
                    if ( invalid ) break;
                }
        }
        if ( invalid ) puts("INVALID");
        else {
            x = st.top().a; y = st.top().b;
            d = gcd(abs(x), abs(y));
            x /= d; y /= d;
            if (y == 1 || y == -1 ) cout << x / y << endl;
            else cout << x <<"|" << y <<endl;
        }
    }
}

/***********************************************
* Author LUONG VAN DO                        *
* Problem 1209 - Wordfish
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
char s[N], ss[N];
vector <string> str;
int f(string s) {
    int x = INF;
    for (int i = 0;i < s.size();i++)
        if (i) x = min(x, abs(s[i] - s[i - 1]));
    return x;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string ans;
    int best, cnt, n, x;
    while (gets(s)) {
        n = strlen(s);
        rep(i, n) ss[i] = s[i];
        ss[n] = '\0';
        cnt = 0;
        x = INF;
        str.clear();
        do{
            for (int i = 0;i < n;i++)
                if (i) x = min(x, abs(ss[i] - ss[i - 1]));
            str.pb(ss);
            ++cnt;
            if (cnt > 10) break;
//            cout<<ss<<" "<<x<<endl;
        }while ( prev_permutation(ss, ss + n) );
        cnt = 0;
        reverse(str.begin(), str.end());
        do{
            for (int i = 0;i < n;i++)
                if (i) x = min(x, abs(s[i] - s[i - 1]));
            str.pb(s);
            /*if (best < x) {
                best = x;
                ans = s;
            }*/
            ++cnt;
            if (cnt > 10) break;
            //cout<<s<<" "<<x<<endl;
        }while ( next_permutation(s, s + n) );
        best = 0;
        for (int i = 0;i < str.size();i++) {
            cnt = f(str[i]);
            if (cnt > best) {
                best = cnt;
                ans = str[i];
            }
        }
        //for (int i = 0;i < str.size();i++)
            //cout<<str[i]<<endl;
        cout << ans << best << endl;
    }
}

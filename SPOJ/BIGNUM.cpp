/***********************************************
* Author LUONG VAN DO                        *
* Problem BIGNUM
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
#define N 1005

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
string s1, s2;
int n, m, a[N], b[N], res[N * N];
string add(string x, string y) {
    int nho, sum;
    string res = "";
    nho = 0;
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    repr(i, x.size()) {
        sum = x[i] - '0' + y[i] - '0' + nho;
        res = char(sum % 10 + 48) + res;
        nho = sum / 10;
    }
    if (nho > 0) res = "1" + res;
    return res;
}
bool nho(string x, string y) {
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    return x < y;
}
string sub(string x, string y) {
    string res = "";
    int nho, sum;
    nho = 0;
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    repr(i, x.size()) {
        sum = (x[i] - '0') - (y[i] - '0') - nho;
        if (sum < 0) {
            sum+=10;
            nho = 1;
        }
        else nho = 0;
        res = char(sum % 10 + 48) + res;
    }
    while (res.size() > 1 && res[0] == '0') res.replace(0,1,"");
    return res;
}
void mutiple(string s1, string s2) {
    int nm;
    rep(i, n)
        a[n-i-1] = s1[i] - '0';
    rep(i, m)
        b[m-i-1] = s2[i] - '0';
    nm = n + m - 2;
    fr(i, 0, nm) res[i] = 0;
    rep(i, n)
        rep(j, m)
            res[i + j] += a[i] * b[j];
    fr(i, 0, nm)
        if (res[i] > 9) {
            res[i + 1] += res[i] / 10;
            res[i]%=10;
        }
    if (res[nm + 1] > 0) nm++;
    frr(i, 0, nm)
        printf("%d",res[i]);
    puts("");
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    cin >> s1; n = s1.length();
    cin >> s2; m = s2.length();
    cout << add(s1, s2) << endl;
    if ( nho(s1, s2) ) cout <<"-"<<sub(s2, s1) << endl;
    else cout << sub(s1, s2) <<endl;
    mutiple(s1, s2);
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 619 - Numerically Speaking ->AC
* Algorithm adhoc
* Time Limit 0.304s
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
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[N];
string add(string x, string y) {
    while (x.size() < y.size()) x = "0" + x;
    while (x.size() > y.size()) y = "0" + y;
    int sum, nho;
    sum = nho = 0;
    string c = "";
    for (int i=x.size()-1;i>=0;i--) {
        sum = (x[i] - '0') + (y[i] - '0') + nho;
        nho = sum / 10;
        c = char(sum % 10 + 48) + c;
    }
    if (nho > 0) c = char(nho + 48) + c;
    return c;
}
string power(string x, int m) {
    int sum, nho;
    char tmp[100];
    string c = "";
    sum = nho = 0; 
    for (int i=x.size()-1;i>=0;i--) {
        sum = (x[i] - '0') * m + nho;
        c = char(sum % 10 + 48) + c;
        nho = sum / 10;
    }
    if (nho > 0) sprintf(tmp,"%d",nho);
    if (nho > 0) return tmp + c;
    else return c;
}
void sub(string &x) {
    int i = x.size()-1;
    if (x[i] > '0') {
        x[i] = char(x[i] - '0' + 47);
        return;
    }
    while (i>=0 && x[i] == '0') {
        x[i] = '9';
        i--;
    }
    x[i] = char(x[i] - '0' + 47);
    if (i == 0 && x[i] == '0') x.replace(0,1,"");
}
string div(string x, int m) {
    int sum;
    sum = 0;
    string c = "";
    for (int i=0;i<x.size();i++) {
        sum = sum * 10 + (x[i] - '0');
        c += char(sum / m + 48);
        sum = sum % m;
    }
    while (c.size() > 1 && c[0] =='0') c.replace(0,1,"");
    return c;
}

int mod(string x, int m) {
    int d = 0;
    for (int i=0;i<x.size();i++)
        d = (d * 10 + x[i] - '0') % m;
    return d;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string ans, base, res;
    int n, x;
    while ( gets(s) && strcmp(s, "*")) {
        ans = "0"; n = strlen(s); res = "";
        if (s[0]>='a' && s[0]<='z') {
            for (int i=0;i<n;i++) {
                x = (s[i] - 'a' + 1); base = "1";
                for (int j=0;j<=n-i-2;j++) base = power(base, 26);
                ans = add(ans, power(base, x));
                //cout<<ans<<endl;
            }
            printf("%-22s",s); x = 0;
            for (int i=ans.size()-1;i>=0;i--) {
                x++;
                res = ans[i] + res;
                if (x % 3 == 0 && i != 0) res = "," + res;
            }
            cout<<res<<endl;
        }
        else {
            base = s; ans = "";
            while ( base != "0" ) {
                x = mod(base, 26);
                base = div(base, 26);
                if (x == 0) sub(base);
                if (x != 0) ans = char('a' + (x + 25) % 26) + ans;
                else ans = 'z' + ans;
            }
            base = s;
            for (int i=0;i<ans.size();i++) s[i] = ans[i];
            s[ans.size()] = '\0';
            printf("%-22s",s); x = 0;
            for (int i=base.size()-1;i>=0;i--) {
                x++;
                res = base[i] + res;
                if (x % 3 == 0 && i != 0) res = "," + res;
            }
            cout<<res<<endl;
        }
    }
}

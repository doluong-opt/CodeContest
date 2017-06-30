/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11475 - Extend to Palindrome ->AC
* Algorithm KMP
* Time Limit 0.048s
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
char s[N], ss[N];
int next[N], n;
void preKmp() {
    int i, j;
    i = 0; j = next[0] = -1;
    while (i < n) {
        while (j>=0 && ss[i] != ss[j]) j = next[j];
        ++i; ++j;
        next[i] = j;
    }
}
int kmp() {
    int i, j;
    i = j = 0;
    while (i < n) {
        while (j>=0 && s[i] != ss[j]) j = next[j];
        ++i; ++j;
        if (j == n)
            j = next[j];
    }
    return abs(i - j);
}
int isPalin(int l, int r) {
    while (l<=r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int pivot;
    while ( gets(s) ) {
        n = strlen(s);
        if (isPalin(0, n - 1)) {
            cout<< s << endl;
            continue;
        }
        for (int i=0;i<n;i++) ss[i] = s[n - i - 1];
        preKmp(); n = n + kmp();
        pivot = (n / 2) + 1;
        pivot = 2 * pivot - strlen(s);
        cout<<s;
        if (n % 2 == 1) {
            for (int j=pivot-2;j>=0;j--) cout<<s[j];
        }
        else {
            for (int j=pivot-3;j>=0;j--) cout<<s[j];
        }
        cout<<endl;
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem
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
string ans;
double sum;
bool isDigit(char s[]) {
    int n = strlen(s), id = 0;
    int sign;
    double v = 0.0, dec;
    while (id < n) {
        while (id < n && s[id] == ' ') ++id;
        v = 0.0; sign = 0;
        
        if (id == n) break;
        if (s[id] == '-') {
            sign = 1;
            id++;
        }
        
        if ( !isdigit(s[id]) ) return false;
        
        while (id < n && s[id] >='0' && s[id] <='9') v = v * 10 + s[id++] - '0';
        dec = 1.0;
        if (s[id] == '.' ) {
            ++id;
            while (id < n && s[id] >='0' && s[id] <= '9' ) {
                dec*=10.0;
                v+=(double(s[id++] - '0') / dec);
            }
            if (id < n && s[id] != ' ') return false;
        }
        if (sign) v*=-1;
        sum+=v;
    }
    return true;
}
bool isAlpha(char s[]) {
    ans = "";
    int n = strlen(s), id = 0;
    while (id < n) {
        while (id < n && s[id] == ' ') ++id;
        
        if ( !isalpha(s[id]) ) return false;
        
        while (id < n && isalpha(s[id])) ans+=s[id++];
        
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[N];
    while (gets(s) && strcmp(s, "?")) {
        sum = 0.0;
        if ( isDigit(s) ) printf("%.6lf\n",sum);
        else
        if ( isAlpha(s) ) cout<< ans <<endl;
        else puts("Error!");
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem - B. Spreadsheets
* Algorithm adhoc
* Time Limit 310ms
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
long long len[15];
int type(char s[]) {
    int i, j;
    for (i=0;i<strlen(s);i++)
        if (isalpha(s[i])) continue;
        else break;
    for (j=i;j<strlen(s);j++)
        if (isdigit(s[j])) continue;
        else break;
    return (j == strlen(s));
}
void work1(char s[]) {
    int col = 0;
    string x, row;
    x = row = "";
    int i, j;
    for (i=0;i<strlen(s);i++)
        if (isalpha(s[i])) x+=s[i];
        else break;
    for (j=i;j<strlen(s);j++)
        row+=s[j];
    for (int i=0;i<x.size();i++) {
        int d = x[i] - 'A' + 1;
        col+=d * len[x.size() - i - 1];
    }
    cout<<"R"<<row<<"C"<<col<<endl;
}
void work2(char s[]) {
    int row = 0, d = 0, x;
    int i, j;
    string col = "";
    for (i=1;i<strlen(s);i++)
        if (isdigit(s[i])) row = (row * 10) + s[i] - '0';
        else break;
    for (j=i+1;j<strlen(s);j++)
        d = (d * 10) + s[j] - '0';
    int pivot = 26;
    while (d != 0 ) {
        int mod = d % pivot;
        d /= pivot;
        if (mod == 0) d--;
        if (mod != 0) col = char('A' + (mod - 1 + 26) % 26) + col;
        else col = 'Z' + col;
    }
    cout<<col<<row<<endl;
}
void init() {
    long long x = 1;
    len[0] = 1;
    for (int i=1;i<=10;i++) {
        x*=26;
        len[i] = x;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, k;
    char s[100];
    scanf(" %d ",&cases);
    init();
    while ( cases-- ) {
        gets(s);
        k = type(s);
        if (k == 1) work1(s);
        else work2(s);
    }
}

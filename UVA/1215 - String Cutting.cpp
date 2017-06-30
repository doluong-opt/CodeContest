/***********************************************
* Author LUONG VAN DO                        *
* Problem 1215 - String Cutting
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
#define M 10100
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
struct node {
    int x, y;
    node(){}
    node(int xx, int yy){
        x = xx; y = yy;
    }
}box[N];
char s[N];
int n, m, a[N], mark[N], nm, f1[N], f2[N];
string S;
int f(int k) {
    string s1, s2;
    int res = 0, l, r;
    for (int i = 0;i < nm;i++)
        if (!mark[i]) {
            if (k >= box[i].x && k <= box[i].y) {
                l = box[i].x;
                r = box[i].y;
                mark[i] = 1;
                break;
            }
        }
    s1 = s2 = "";
    for (int i = l;i <= r;i++) {
        s1+=S[i];
        if (i == k) break;
    }
    box[nm++] = node(l, k);
    for (int i = k + 1;i <=r;i++)
        s2+=S[i];
    box[nm++] = node(k + 1, r);
//    cout<<s1<<" "<<s2<<endl;
//    cout<<l<<" "<<j<<" "<<j + 1<<" "<<r<<endl;
    fill(f1, 0); fill(f2, 0);
    for (int i = 0;i < s1.size();i++)
        f1[s1[i] - 'a'] = 1;
    for (int i = 0;i < s2.size();i++)
        f2[s2[i] - 'a'] = 1;
    for (int i = 0;i < 26;i++)
        if ((f1[i] && !f2[i]) || (!f1[i] && f2[i])) res++;
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, ans;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        fill(mark, 0);
        rep(i, n) scanf(" %d ", &a[i]);
        gets(s); m = strlen(s);
        S = " ";
        S += s; ans = 0;
        nm = 0; box[nm++] = node(1, m);
        rep(i, n)
            ans+=f(a[i]);
        printf("%d\n", ans);
    }
}

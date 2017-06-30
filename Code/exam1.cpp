/***********************************************
* Author LUONG VAN DO                        *
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
inline long long min(long long a, long long b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
long long l, w;
long long p2[50];
long long x, y, r1, r2, best;
int main(){
	ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    	freopen("exam.inp","r", stdin);
    	freopen("exam.out","w", stdout);
    #endif
    scanf("%I64d %I64d", &l, &w);
    p2[0] = 1; x = 0; y = 0; r1 = r2 = -1;
    best = 0;
    for (int i = 1;i <= 31;i++) p2[i] = p2[i - 1] * 2;
    for (int i = 31;i >= 0;i--) {
        if (p2[i] > l) continue;
        x = p2[i]; y = -1;
        long long low = (long long)ceil(x / 1.25);
        long long hight = (long long)floor(x / 0.8);
        if (low <= hight) {
            y = min(hight, w);
        }
        else y = -1;
        //cout<<low<<" "<<hight<<" "<<x<<" "<<y<<endl;
        if (y != -1 && low <= y && y <= w && x * y > best) {
            best = x * y;
            r1 = x;
            r2 = y;
        }
        else
        if (x * y == best) {
            if (x > r1) {
                r1 = x;
                r2 = y;
            }
        }
    }
    //cout<<r1<<" "<<r2<<endl;
    for (int i = 31;i >= 0;i--) {
        if (p2[i] > w) continue;
        y = p2[i]; x = -1;
        long long low = (long long)ceil(y * 0.8);
        long long hight = (long long)floor(y * 1.25);
        if (low <= hight) {
            x = min(hight, l);
        }
        else x = -1;
        //cout<<low<<" "<<hight<<" "<<x<<" "<<y<<endl;
        if (y != -1 && low <= x && x <= l && x * y > best) {
            best = x * y;
            r1 = x;
            r2 = y;
        }
        else
        if (x * y == best) {
            if (x > r1) {
                r1 = x;
                r2 = y;
            }
        }
    }
    //if (r1 < r2) swap(r1, r2);
    printf("%I64d %I64d", r1, r2);
    return 0;
}

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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 511

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int type;
    int64 x, y, z;
    node(){}
    node(int _type, int64 _x, int64 _y, int64 _z){
        type = _type; x = _x; y = _y; z = _z;
    }
};
int n, m, k;
int64 x[N], y[N], z[N];
int64 r[N], h[N];
int64 dp[N], ans;
node data[N];
bool cmp(node a, node b) {
    double area1, area2;
    if (a.type == 1) area1 = a.x * a.y;
    else area1 = PI * a.y * a.y;
    
    if (b.type == 1) area2 = b.x * b.y;
    else area2 = PI * b.y * b.y;
    
    return (area1 < area2);
}
int main() {
	freopen("XH.INP","r", stdin); freopen("XH.OUT","w", stdout);
	scanf("%d %d", &n, &m);
	k = 0;
	fr(i, 1, n) {
	    scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
	    data[++k] = node(1, x[i], y[i], z[i]);
	    data[++k] = node(1, z[i], y[i], x[i]);
	    data[++k] = node(1, x[i], z[i], y[i]);
	}
	fr(i, 1, m) {
	    scanf("%lld %lld", &r[i], &h[i]);
	    data[++k] = node(2, 0, r[i], h[i]);
	}
	sort(data + 1, data + k + 1, cmp);
	fr(i, 1, k) {
        if (data[i].type == 1)
            if ( data[i].x > data[i].y ) swap(data[i].x, data[i].y);
        //printf("%lld %lld %lld\n", data[i].x, data[i].y, data[i].z);
	}
	fill(dp, 0); ans = 0;
	for (int i = 1;i <= k;i++) {
	    dp[i] = data[i].z;
        for (int j = i - 1;j >= 1;j--) {
            int t1 = data[i].type;
            int t2 = data[j].type;
            if (t1 == 1 && t2 == 1) {
                //cout<<i<<" "<<j<<" "<<data[j].x<<" "<<data[i].x<<" "<<data[j].y<<" "<<data[i].y<<endl;
                if (data[j].x < data[i].x && data[j].y < data[i].y) {
                    dp[i] = max(dp[i], dp[j] + data[i].z);
                    //cout <<dp[i] <<" "<<dp[j] + data[i].z<<endl;
                    ans = max(ans, dp[i]);
                }
            }
            if (t1 == 1 && t2 == 2) {
                if ( 2 * data[j].y < min(data[i].x, data[i].y) )
                    dp[i] = max(dp[i], dp[j] + data[i].z);
                    //cout <<"2"<<endl;
                    ans = max(ans, dp[i]);
            }
            if (t1 == 2 && t2 == 1) {
                if ( data[j].x * data[j].x + data[j].y * data[j].y < 4 * data[i].y * data[i].y )
                    dp[i] = max(dp[i], dp[j] + data[i].z);
                    //cout <<"3"<<endl;
                    ans = max(ans, dp[i]);
            }
            if (t1 == 2 && t2 == 2) {
                if ( data[j].y < data[i].y )
                    dp[i] = max(dp[i], dp[j] + data[i].z);
                    ans = max(ans, dp[i]);
                    //cout <<"4"<<endl;
            }
        }
	}
    printf("%lld\n", ans);
	return 0;
}

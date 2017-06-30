//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name :
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 111
#define N 10010
struct point{
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
};
point p[N];
vector <double> res;
bool inter(point a, point b, int64 x) {
    int64 a1 = b.x - a.x;
    int64 b1 = b.y - a.y;
    if (a1 == 0) return false;
    int64 c = a1 * a.y - b1 * a.x;
    double y = (double)(c + b1 * x) / (double)(a1);
    
    if ( min(a.y, b.y) < y && y < max(a.y, b.y) ) res.pb( y );
}
double solve() {
    double sum = 0;
    sort(res.begin(), res.end());
    for (int i=0;i<res.size();i+=2)
        sum+=(res[i + 1] - res[i]);
    return sum;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("exam.inp", "r", stdin);
	freopen("exam.out", "w", stdout);
	#endif
	int cases, n;
	int64 k, x;
	scanf("%d",&cases);
	while (cases--) {
        scanf("%d",&n);
        res.clear();
        for (int i=0;i<n;i++) scanf("%lld %lld",&p[i].x,&p[i].y);
        scanf("%lld %lld",&k,&x);
//        cnt = 0;
        for (int i=0;i<n;i++)
            inter(p[i], p[(i + 1) % n], x);
            
        //cout<<cnt<<" "<<2 * k<<endl;
//        solve();
        if (solve() >= k) puts("YES");
        else puts("NO");
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet

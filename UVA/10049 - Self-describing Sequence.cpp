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
#define maxN 2000000000
#define N 1000000
int64 f[N];
queue <ii> q;
int64 fl(int64 x, int64 l, int64 r) {
    while (l <= r) {
        int64 mid = (l + r) >> 1;
        if (f[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	int64 n, sum, r;
	ii u;
	fill(f, -1);
	f[1] = 1;
	f[2] = 2; q.push(ii(2, 1)); sum = 3;
	r = 2;
	
	while ( sum <= maxN) {
        if (f[r] == -1) {
            u = q.front(); q.pop();
            while ( u.ss ) {
                f[r] = u.ff;
                u.ss--;
                sum+=u.ff;
                q.push(ii(r, u.ff));
                r++;
            }
        }
        else r++;
    }
    //for (int i=1;i<=9999;i++) cout<<i<<" "<<f[i]<<endl;
    f[0] = 0;
    for (int i=1;i<=673467;i++)
        f[i]+=f[i-1];
        //cout<<f[673467]<<endl;
	while ( scanf("%lld",&n) && n) {
        printf("%lld\n", fl(n, 1, 673467));
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet

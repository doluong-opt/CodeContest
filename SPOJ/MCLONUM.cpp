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
#define N 66

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
char a[N], b[N];
int cnt[N], ans[N], f[N];
int n, m, id;
bool found, isOk;
bool findEqual(int x, int y) {
    return (x == y && cnt[x] > 0);
}
bool findLarge(int x, int y) {
    return (x > y && cnt[x] > 0);
}
bool findSmall(int x, int y) {
    return (x < y && cnt[x] > 0);
}
void findX() {
    m = 0; isOk = false;
	rep(i, n) {
	    found = false;
	    rep(j, 10)
            if (findEqual(j, f[i])) {
                ans[m++] = j;
                cnt[j]--;
                found = true;
                break;
            }
        if (!found) {
            rep(j, 10)
                if (findLarge(j, f[i])) {
                    ans[m++] = j;
                    cnt[j]--;
                    isOk = true;
                    break;
                }
            if (isOk) {
                rep(k, m) printf("%d", ans[k]);
                rep(k, 10)
                    rep(j, cnt[k]) printf("%d", k);
                puts("");
                return;
            }
            else {
                while (m >= 1) {
                    cnt[ans[m - 1]]++;
                    rep(j, 10)
                        if (j > ans[m - 1] && cnt[j] > 0) {
                            ans[m - 1] = j;
                            cnt[j]--;
                            isOk = true;
                            break;
                        }
                    if (isOk) break;
                    m--;
                }
                if (isOk) {
                    rep(k, m) printf("%d", ans[k]);
                    rep(k, 10)
                        rep(j, cnt[k]) printf("%d", k);
                    puts("");
                    return;
                }
                else {
                    puts("0");
                    return;
                }
            }
        }
	}
	rep(i, m) printf("%d", ans[i]);
	puts("");
}
void findY() {
    m = 0; isOk = false;
	rep(i, n) {
	    found = false;
	    for (int j = 9;j >= 0;j--)
            if (findEqual(j, f[i])) {
                ans[m++] = j;
                cnt[j]--;
                found = true;
                break;
            }
        if (!found) {
            for (int j = 9;j >= 0;j--) {
                if (m == 0 && j == 0) continue;
                if (findSmall(j, f[i])) {
                    //cout<<j<<" "<<a[i] - '0'<<endl;
                    ans[m++] = j;
                    cnt[j]--;
                    isOk = true;
                    break;
                }
            }
            
            if (isOk) {
                rep(k, m) printf("%d", ans[k]);
                for (int k = 9;k >= 0;k--)
                    rep(j, cnt[k]) printf("%d", k);
                puts("");
                return;
            }
            else {
                while (m >= 1) {
                    cnt[ans[m - 1]]++;
                    for (int j = 9;j >= 0;j--) {
                        if (j == 0 && m == 1) continue;
                        if (j < ans[m - 1] && cnt[j] > 0) {
                            ans[m - 1] = j;
                            cnt[j]--;
                            isOk = true;
                            break;
                        }
                    }
                    if (isOk) break;
                    m--;
                }
                if (isOk) {
                    rep(k, m) printf("%d", ans[k]);
                    for (int k = 9;k >= 0;k--)
                        rep(j, cnt[k]) printf("%d", k);
                    puts("");
                    return;
                }
                else {
                    puts("0");
                    return;
                }
            }
        }
	}
	puts("0");
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(a); gets(b); n = strlen(a);
	rep(i, n) f[i] = a[i] - '0';
	rep(i, 10) cnt[i] = 0;
	rep(i, n) cnt[b[i] - '0']++;
	findX();
	rep(i, 10) cnt[i] = 0;
	rep(i, n) cnt[b[i] - '0']++;
	id = n - 1;
	while (id >= 0 && f[id] == 0) f[id--] = 9;
	f[id]--;
	findY();
	return 0;
}

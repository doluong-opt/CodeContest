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
#define N 100111

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
int goal[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int start[4][4];
stack <int> st;
bool check() {
    int a[10], n = 0;
    rep(i, 3) rep(j, 3) a[i * 3 + j] = start[i][j];
    for (int i = 0;i < 9;i++)
        for (int j = i + 1;j < 9;j++)
            if (a[i] > 0 && a[j] > 0 && a[i] > a[j]) n++;
    return (n % 2 == 0);
}
int f(int start[4][4]) {
    int total = 0;
    rep(i, 3)
        rep(j, 3)
            rep(k, 9) {
                if (start[i][j] != 0 && start[i][j] == goal[k]) {
                    int nx = k / 3;
                    int ny = k % 3;
                    total += abs(nx - i) + abs(ny - j);
                    break;
                }
            }
    return total;
}
bool isSame(int start[4][4]) {
    int temp[10];
    rep(i, 3) rep(j, 3) temp[i * 3 + j] = start[i][j];
    rep(i, 9)
        if (temp[i] != goal[i]) return false;
    return true;
}
bool dfs(int start[4][4], int g, int curH) {
    if (g + f(start) > curH) return false;
    if ( isSame(start) ) return true;
    int curRow, curCol, temp[4][4];
    rep(i, 3) rep(j, 3)
        if (start[i][j] == 0) {
            curRow = i; curCol = j;
            break;
        }
    if (curRow > 0 && (st.size() == 0 || st.top() != 0) ) {        
        st.push(1);
        rep(i, 3) rep(j, 3) temp[i][j] = start[i][j];
        swap(temp[curRow][curCol], temp[curRow - 1][curCol]);
        if ( dfs(temp, g + 1, curH) ) return true;
        st.pop();
    }
    
    if (curRow < 2 && (st.size() == 0 || st.top() != 1) ) {
        st.push(0);
        rep(i, 3) rep(j, 3) temp[i][j] = start[i][j];
        swap(temp[curRow][curCol], temp[curRow + 1][curCol]);
        if ( dfs(temp, g + 1, curH) ) return true;
        st.pop();
    }
    if (curCol > 0 && (st.size() == 0 || st.top() != 2) ) {
        st.push(3);
        rep(i, 3) rep(j, 3) temp[i][j] = start[i][j];
        swap(temp[curRow][curCol], temp[curRow][curCol - 1]);
        if ( dfs(temp, g + 1, curH) ) return true;
        st.pop();
    }
    if (curCol < 2 && (st.size() == 0 || st.top() != 3) ) {
        st.push(2);
        rep(i, 3) rep(j, 3) temp[i][j] = start[i][j];
        swap(temp[curRow][curCol], temp[curRow][curCol + 1]);
        if ( dfs(temp, g + 1, curH) ) return true;
        st.pop();
    }
    return false;
}
int ida_star() {
    int h = 0;
    while ( !dfs(start, 0, h) ) h++;
    return h;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while ( cases-- ) {
	    rep(i, 3) rep(j, 3) scanf("%d", &start[i][j]);
	    printf("Case %d: ",++caseno);
	    if ( !check() ) puts("impossible");
	    else printf("%d\n", ida_star());
	    while (st.size()) st.pop();
	}
	return 0;
}

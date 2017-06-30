/***********************************************
* Author - LUONG VAN DO                        *
*
* Algorithm
* Time
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <set>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0;i<n;i++)
#define uint64 unsigned long long
#define int64 long long

#define MOD 4294967296LL
#define MAX 100000000
#define LMT 500001
#define C 2000000
using namespace std;
int n, x, y, k, cnt;
typedef pair <int, int> ii;
ii a[LMT];
int p[C + 5];
void sieve() {
    for (int i = 1;i <= C;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 4;i <= C;i += 2) p[i] = 0;
    for (int i = 3;i * i <= C;i += 2)
        if (p[i])
            for (int j = i * i;j <= C;j += 2 * i) p[j] = 0;
}
int main() {
//	freopen("exam.inp","r", stdin);
//	freopen("exam.out","w",stdout);
	sieve();
	a[0] = ii(1, 2);
    scanf("%d", &n);
    if (n <= 2) printf("1\n%d %d\n", a[0].first, a[0].second);
    else {
        x = 3; y = 4;
        if (n % 2) n--;
        k = (n / 2) - 1;
        cnt = 1;
        int nx, ny;
        while ( k ) {
            nx = x, ny = y;
            if ( p[x + y] ) a[cnt++] = ii(x, y);
            else {
                int temp;
                for (int i = cnt - 1;i >= 0;i--)
                    if ( p[a[i].first + y] && p[a[i].second + x] ) {
                        temp = a[i].second;
                        a[i].second = y;
                        y = temp;
                        break;
                    }
                    else
                    if ( p[a[i].first + x] && p[a[i].second + y] ) {
                        temp = a[i].second;
                        a[i].second = x;
                        x = temp;
                        break;
                    }
                    20
                a[cnt++] = ii(x, y);
            }
            nx += 2; ny += 2; k--;
            x = nx; y = ny;
        }
        printf("%d\n", cnt);
        for (int i = 0;i < cnt;i++)
            printf("%d %d\n", a[i].first, a[i].second);
    }
	return 0;
}

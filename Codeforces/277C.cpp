/***********************************************
* Author - LUONG VAN DO
*
* Algorithm
* Time Limit 0.003s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define N 10001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int digit[N];
int main() {
        freopen("exam.inp","r", stdin);
        freopen("exam.out","w", stdout);
        int m, s, cnt;
        scanf("%d %d",&m, &s);
        cnt = 0;
        if (s == 0 && m == 1) {
                puts("0 0");
                return 0;
        }
        for (int i = 1;i <= m;i++) {
                for (int j = 9;j >= 0;j--)
                        if (s >= j) {
                                digit[cnt++] = j;
                                s -= j;
                                break;
                        }
        }
        if (s > 0) puts("-1 -1");
        else {
                int j = cnt - 1;
                while (j >= 0 && digit[j] == 0) j--;
                if (j < 0) {
                        puts("-1 -1");
                }
                else {
                                vector <int> res;
                        printf("%d", digit[j]);
                        for (int i = 0;i < cnt;i++)
                                if (i != j) res.push_back(digit[i]);
                        sort(res.begin(), res.end());
                        for (int i = 0;i < res.size();i++) printf("%d", res[i]);
                        printf(" ");
                        for (int i = 0;i < cnt;i++)
                                printf("%d", digit[i]);
                        puts("");
                }
        }
        return 0;
}

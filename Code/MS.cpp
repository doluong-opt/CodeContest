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
#define LMT 10000
#define N 4
struct Matrix{
    int a[2][N];
    int cost;
    Matrix();
    Matrix(int _a[2][N]){
        for (int i = 0;i < 2;i++)
            for (int j = 0;j < N;j++) a[i][j] = _a[i][j];
    }
}gold;
int main() {
	freopen("exam.inp",r, stdin);
	freopen("exam.out",w,stdout);
	Matrix start;
	for (int i = 0;i < N;i++) start.a[0][i] = i + 1;
	for (int i = 0;i < N;i++) start.a[1][i] = 2 * N - i;
	start.cost = 0;
	for (int i = 0;i < 2;i++)
        for (int j = 0;j < N;j++)
        scanf("%d", &gold.a[i][j]);
    queue <Matrix> q;
    q.push(start);
    while ( !q.empty() ) {
        Matrix st = q.front(); q.pop();

    }
	return 0;
}

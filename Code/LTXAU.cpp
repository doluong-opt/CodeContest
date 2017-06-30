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
#define LMT 1000005
char A[LMT], B[LMT];
int lo, hi, pos;
bool isOk(int len) {

}
int main() {
	freopen("exam.inp",r, stdin);
	freopen("exam.out",w,stdout);
    gets(A); gets(B);
    lo = 1; hi = min(strlen(A), strlen(B)); pos = -1;
    while ( lo <= hi ) {
        int mid = (lo + hi) >> 1;
        if ( isOk(mid) ) {
            pos = mid;
            lo = mid + 1;
        }
        else mid - 1;
    }
    if (pos == -1) puts("NO");
    else {
        for (int i = 0;i < pos;i++) printf("%c", A[i]);
        puts("");
    }
	return 0;
}

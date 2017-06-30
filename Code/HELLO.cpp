/***********************************************
* Author - LUONG VAN DO                        *
* HELLO
* Algorithm
* Time
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
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

using namespace std;
char s[LMT];
int pos, n;
int main() {
	//freopen("exam.inp","r", stdin);
	//freopen("exam.out","w",stdout);
	gets(s); n = strlen(s);
	while (pos < n && s[pos] != 'h') pos++;
	pos++;
	while (pos < n && s[pos] != 'e') pos++;
	pos++;
	while (pos < n && s[pos] != 'l') pos++;
	pos++;
	while (pos < n && s[pos] != 'l') pos++;
	pos++;
	while (pos < n && s[pos] != 'o') pos++;
	if (pos < n) puts("YES");
	else puts("NO");
	return 0;
}

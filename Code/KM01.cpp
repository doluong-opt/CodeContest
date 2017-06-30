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
#define N 100001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
long long get(long long x, long long y) {
        long long ans = 0LL;
        long long tempY = y;
        int cntY = 0;
        int cntX = 0;
        while (y > 0) y /= 10, cntY++;
        long long nine = 0LL;
        for (int i = 1;i <= cntY;i++) {
               nine = nine * 10 + 9;
               if (x <= nine && nine <= tempY) ans += (tempY - x + 1);
        }
        return ans;
}
//int f(int k) {
//        int p = 1;
//        while (k > 0) k /= 10, p *= 10;
//        return p;
//}
//bool check(int x, int y) {
//        if (x + y + x * y == x * f(y) + y) return true;
//}
int main() {
       // freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        int cases;
        long long cnt, a, b;
        scanf("%d", &cases);
        while (cases--) {
                cin >> a >> b;
                cout << get(a, b) <<endl;
//                cnt = 0;
//                for (int i = a;i <= b;i++)
//                        for (int j = a; j<= b;j++) {
//                                if (check(i, j)) {
//                                                        cnt++;
//                                                cout<<i<<" "<<j<<endl;
//                                }
//                        }
//                cout<<cnt<<endl;
        }
        return 0;
}

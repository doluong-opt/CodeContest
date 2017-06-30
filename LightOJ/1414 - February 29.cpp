/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1414 	February 29 -> AC
* Algorithm Adhoc
* Time Limit 0.002s
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
#define M 100000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool isLeap(int y){
    if ((y % 4 == 0 && y % 100) || (y % 400 == 0)) return true;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    string m1, m2, d1, d2;
    int y1, y2, Ans, day1, day2;
    int xx, yy, zz, n, idx;
    scanf("%d",&test);
    FOR(t, 1, test) {
        cin >> m1 >> d1 >> y1;
        cin >> m2 >> d2 >> y2;
        n = d1.length() - 1; idx = 0;
        day1 = day2 = 0;
        
        while (idx < n) {
            day1 = day1 * 10 + (d1[idx] - '0');
            ++idx;
        }
        n = d2.length() - 1; idx = 0;
        
        while (idx < n) {
            day2 = day2 * 10 + (d2[idx] - '0');
            ++idx;
        }
        y1++; y2--;
        Ans = 0; xx = yy = zz = 0;
        if (y1<=y2) {
            xx = (y2 / 4) - ((y1 - 1) / 4);
            yy = (y2 / 100) - ((y1 - 1) / 100);
            zz = (y2 / 400) - ((y1 - 1) / 400);
            xx = xx - yy + zz;
        }
        Ans = xx;
        y1--; y2++;
        if (y1!=y2) {
            if (isLeap(y1) && (m1 == "January" || m1 == "February") ) Ans++;
            if (isLeap(y2) && m2 == "February" && day2 == 29) Ans++;
            else
            if (isLeap(y2) && m2!="January" && m2!="February") Ans++;
        }
        else {
            bool ok1, ok2;
            ok1 = ok2 = false;
            if (isLeap(y1) && (m1 == "January" || m1 == "February") ) ok1 = true;
            if ((m2 == "February" && day2 == 29) || (m2!="January" && m2!="February")) ok2 = true;
            if (ok1 && ok2) Ans++;
        }
        printf("Case %d: %d\n",t,Ans);
    }
}

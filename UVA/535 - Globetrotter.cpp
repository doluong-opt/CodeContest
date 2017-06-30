/***********************************************
* Author - LUONG VAN DO                        *
* Problem 535 - Globetrotter ->AC
* Algorithm gcDistance
* Time Limit 0.1s
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
#define PI 3.141592653589793
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<double, double> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
double R;
double a[M], b[M];
string city[M];
double getDistance(double pLat, double pLong,
                   double qLat, double qLong) {
    pLat*=PI / 180.0; pLong*=PI / 180.0;
    qLat*=PI / 180.0; qLong*=PI / 180.0;
    double dlon = pLong - qLong;
    double dlat = pLat - qLat;
    double a = (sin(dlat / 2) * sin(dlat / 2) + cos(pLat) * cos(qLat) * sin(dlon / 2.0) * sin(dlon / 2.0));
    double angle = 2.0 * atan2(sqrt(a), sqrt(1 - a));
    return angle;
}
int64 Round(double x) {
    return (int64)floor(x + 0.5f);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string x, y;
    double pLat, pLong, Ans;
    int n = 0;
    R = 6378.0;
    while ( cin >> x ) {
        if (x == "#") break;
        cin >> pLat >> pLong;
        ++n;
        city[n] = x;
        a[n] = pLat;
        b[n] = pLong;
    }
    while ( cin >> x >> y ) {
        if (x == "#" && y == "#" ) break;
        int i, j;
        for (i=1;i<=n;i++)
            if ( city[i] == x )
                break;
        for (j=1;j<=n;j++)
            if ( city[j] == y )
                break;
        if (i > n || j > n) {
            cout << x <<" - "<< y <<endl;
            cout<<"Unknown"<<endl;
        }
        else {
            cout << x <<" - "<< y <<endl;
            Ans = getDistance(a[i], b[i], a[j], b[j]);
            Ans = Round(Ans * R);
            cout<<Ans<<" km"<<endl;
        }
    }
}

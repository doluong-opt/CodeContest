/***********************************************
* Author - LUONG VAN DO                        *
* Problem 184 - Laser Lines ->AC
* Algorithm Adhoc
* Time Limit 0.032s
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
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Point{
    int x, y;
    Point(){}
    Point(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator < (const Point &other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
}P[M + 1];
vector <Point> lines;
vector <Point> :: iterator it;
int cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool is_exist(Point A, Point B, vector <Point> pre){
    int x, y;
    for (int i=0;i<pre.size();i+=2) {
        x = cross(A, B, pre[i]);
        y = cross(A, B, pre[i + 1]);
        if (x == 0 && y == 0) return true;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, y, n, found, flag;
    while ( scanf("%d %d",&x,&y) && (x + y)){
        n = 0; P[n++] = Point(x, y);
        while ( scanf("%d %d",&x,&y) && (x + y)) P[n++] = Point(x, y);
        sort(P, P + n); found = flag = 0;
        vector <Point> pre;
        for (int i=0;i<n;i++)
            for (int j=i + 1;j<n;j++) {
                
                if ( is_exist(P[i], P[j], pre) ) continue;
                
                lines.pb(P[i]);
                lines.pb(P[j]);
                
                for (int k=j + 1;k<n;k++)
                    if (cross(P[i], P[j], P[k]) == 0) lines.pb(P[k]);
                
                if ( lines.size() > 2 ) {
                    found = 1;
                    flag++;
                    if (flag == 1) puts("The following lines were found:");
                    
                    for (it=lines.begin(); it!=lines.end(); ++it)
                        printf("(%4d,%4d)",it->x,it->y);
                        
                    puts("");
                    pre.pb(lines[0]);
                    pre.pb(lines[1]);
                }
                lines.clear();
            }
        if ( !found ) puts("No lines were found");
    }
}

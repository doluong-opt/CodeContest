/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10357 - Playball !!! ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
struct Person{
    int x, y, s;
    Person(){}
    Person(int xx, int yy, int ss){
        x = xx; y = yy; s = ss;
    }
}person[M];
struct Balls{
    int a, b, c, d, e, f ,g;
    Balls(){}
    Balls(int aa, int bb, int cc, int dd, int ee, int ff, int gg){
        a = aa; b = bb; c = cc; d = dd; e = ee; f = ff; g = gg;
    }
}balls[M];
char s[M];
int nm, nb;
int call_time(Balls q){
    int a = q.a;
    int b = q.b;
    int c = q.c;
    double delta, x1, x2, x;
    delta = sqrt(b * b - 4 * a * c);
    if (a > 0) {
        x1 = (-b - delta) / (2.0 * a);
        x2 = (-b + delta) / (2.0 * a);
        a = (int)ceil(x1);
        b = (int)floor(x2);
        if (a > 0) return a;
        else
        if (b > 0) return b;
        else return 0;
    }
    else
    if (a < 0) {
        x1 = (-b - delta) / (2.0 * a);
        x2 = (-b + delta) / (2.0 * a);
        a = (int)floor(x2);
        b = (int)ceil(x1);
        if (a > 0) return a;
        else
        if (b > 0) return b;
        else return 0;
    }
    else {
        if (b < 0) return (int)ceil((double)-c / (double)b);
        else
        if (b > 0) return (int)floor((double)-c / (double)b);
        else return 0;
    }
}
double dist(Person A, int x, int y){
    double dx = A.x - x;
    double dy = A.y - y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, id, t, x, y;
    double d;
    while ( gets(s) ){
        n = strlen(s); id = nm = 0;
        while (id < n && !isdigit(s[id])) ++id;
        while (id < n) nm = nm * 10 + (s[id++] - '0');
        for (int i=0;i<nm;i++) scanf(" %d %d %d ",&person[i].x,&person[i].y,&person[i].s);
        gets(s); id = nb = 0;
        n = strlen(s);
        while (id < n && !isdigit(s[id])) ++id;
        while (id < n) nb = nb * 10 + (s[id++] - '0');
        for (int i=0;i<nb;i++) scanf("%d %d %d %d %d %d %d",&balls[i].a,&balls[i].b,&balls[i].c,&balls[i].d,&balls[i].e,&balls[i].f,&balls[i].g);
        for (int i=0;i<nb;i++) {
            t = call_time(balls[i]);
            x = balls[i].d * t + balls[i].e;
            y = balls[i].f * t + balls[i].g;
            if (x < 0 || y < 0) printf("Ball %d was foul at (%d,%d)\n",i + 1, x, y);
            else {
                int j;
                for (j=0;j<nm;j++) {
                    d = dist(person[j], x, y);
                    if (d <= person[j].s * t) {
                        printf("Ball %d was caught at (%d,%d)\n",i + 1, x, y);
                        break;
                    }
                }
                if (j == nm) printf("Ball %d was safe at (%d,%d)\n",i + 1, x, y);
            }
        }
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10901 - Ferry Loading III ->AC
* Algorithm queue
* Time Limit 0.024s
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
#define M 10010

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
struct Node{
    int v, id;
    Node(){}
    Node(int vv, int idd){
        v = vv; id = idd;
    }
    bool operator <(const Node& other) const{
        return (id < other.id);
    }
};
Node res[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, t, m, val, x;
    int nm, blank = 0;
    char s[10];
    scanf("%d",&cases);
    while ( cases--) {
        scanf("%d %d %d",&n,&t,&m);
        queue <Node> left, right;
        nm = 0;
        for (int i=0;i<m;i++) {
            scanf("%d %s",&val,&s);
            if (strcmp(s, "left") == 0) left.push(Node(val, i));
            else right.push(Node(val, i));
        }
        string cur = "left";
        int time = 0;
        while ( !left.empty() || !right.empty() ) {
            if (!left.empty() && !right.empty()) {
                if (left.front().v > time && right.front().v > time) {
                    
                    if (left.front().v > right.front().v) {
                        time+=(right.front().v - time);
                        if (cur == "left") time+=t;
                            cur = "right";
                    }
                    else {
                        time+=(left.front().v - time);
                        if (cur == "right") time+=t;
                        cur = "left";
                    }
                    
                }
            }
            else
            if (left.empty() ) {
                if (right.front().v > time)  {
                    time+=(right.front().v - time);
                    if (cur == "left") time+=t;
                    cur = "right";
                }
            }
            else
            if (right.empty()) {
                if (left.front().v > time)  {
                    time+=(left.front().v - time);
                    if (cur == "right") time+=t;
                    cur = "left";
                }
            }
            if (cur == "left") {
                x = 0;
                while (x < n && !left.empty() && time >= left.front().v) {
                    x++;
                    res[nm++] = Node(time + t, left.front().id);
                    left.pop();
                }
                time+=t;
                cur = "right";
            }
            else {
                x = 0;
                while (x < n && !right.empty() && time >= right.front().v) {
                    ++x;
                    res[nm++] = Node(time + t, right.front().id);
                    right.pop();
                }
                time+=t;
                cur = "left";
            }
        }
        if ( blank ) puts("");
        blank = 1;
        sort(res, res + nm);
        for (int i=0;i<nm;i++)
            printf("%d\n",res[i].v);
    }
}

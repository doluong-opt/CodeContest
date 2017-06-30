// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 100010
struct node{
    int id;
    string x;
    node(){}
    node(int _id, string _x){
        id = _id;
        x = _x;
    }
    bool operator < (const node& other) const{
        return x > other.x;
    }
}a;
string s;
int k;
int64 x, n;
priority_queue <node> q;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    cin >> s; n = s.size();
    scanf(" %d ", &k);
    x = (n * (n + 1)) / 2;
    if (k > x) {
        puts("No such line.");
        return 0;
    }
    
    rep(i, n) {
        a.id = i + 1;
        a.x = s[i];
        q.push(a);
    }
    
    for(int i = 0;i < k - 1;i++) {
        a = q.top(); q.pop();
        if (a.id < n) {
            a.x += s[a.id++];
            q.push(a);
        }
    }
    cout << q.top().x << endl;
    return 0;
}

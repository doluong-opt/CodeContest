/***********************************************
* Author - LUONG VAN DO                        *
* Problem D. Least Cost Bracket Sequence ->AC
* Algorithm dp greedy
* Time Limit 50ms
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
#define M 50010

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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[M];
    int x, y, sign;
    int64 ans;
    gets(s);
    priority_queue <ii> Q;
    ans = sign = 0;
    for (int i=0;s[i];++i) {
        if (s[i] == '(') sign++;
        else
        if (s[i] == ')') sign--;
        else {
            sign--;
            scanf("%d %d",&x,&y);
            ans+=y;
            s[i] = ')';
            Q.push(ii(y - x, i));
        }
        ii temp;
        if (sign < 0) {
            if (Q.empty()) break;
            temp = Q.top(); Q.pop();
            s[temp.B] = '(';
            sign+=2;
            ans-=temp.A;
        }
    }
    if (sign != 0) cout<<-1<<endl;
    else {
        cout<<ans<<endl;
        cout<<s<<endl;
    }
}

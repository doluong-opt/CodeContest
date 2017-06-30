/***********************************************
* Author - LUONG VAN DO                        *
* 1322 - Worst Case Trie ->AC
* Algorithm math
* Time Limit 3.021s
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
#define maxN 10001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, ind;
    node(){}
    node(int xx, int indd){
        x = xx; ind = indd;
    }
    bool operator < (const node &other) const{
        return x < other.x;
    }
} Node[maxN];
string ans[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    char s[10];
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&Node[t].x);
        Node[t].ind = t;
    }
    sort(Node + 1, Node + test + 1);
    int64 res = 2;
    int64 cnt = 1;
    FOR(i, 1, test) {
        while ( cnt < Node[i].x ) {
            res = ((res % 10000) * (cnt + 1) % 10000 + 1) % 10000;
            ++cnt;
            res%=10000;
        }
        if(cnt < 6) {
            string tmp = "";
            int64 x = res;
            while ( x ) {
                tmp = char(x % 10 + 48) + tmp;
                x/=10;
            }
            ans[ Node[i].ind ] = tmp;
        }
        else {
            string tmp = "";
            int64 x = res;
            while ( x ) {
                tmp = char(x % 10 + 48) + tmp;
                x/=10;
            }
            while (tmp.size() < 4) tmp = "0"+tmp;
            ans[ Node[i].ind ] = tmp;
        }
    }
    FOR(i, 1, test) {
        printf("Case %d: ",i);
        cout << ans[i] << endl;
    }
    return 0;
}

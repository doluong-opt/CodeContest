/***********************************************
* Author - LUONG VAN DO                        *
* 101 - The Blocks Problem ->AC
* Algorithm Adhoc
* Time Limit 0.024s
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
int ss[26][26];
int top[26];
void Find(int *s, int a){
    REP(i, n)
        REP(j, top[i] + 1)
            if (ss[i][j] == a) {
                s[0] = i; s[1] = j;
                return;
            }
}
void Move(int *s){
    int temp;
    for (int i=s[1]+1;i<=top[s[0]];i++) {
        temp = ss[s[0]][i];
        ss[temp][++top[temp]] = ss[s[0]][i];
    }
    top[s[0]] = s[1];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string q, op;
    int a, b;
    int sa[4], sb[4];
    while ( scanf("%d",&n) !=EOF) {
        REP(i, n) {
            top[i] = 0;
            REP(j, n)
                ss[i][j] = 0;
        }
        REP(i, n)
            ss[i][0] = i;
        while ( cin >> q ) {
            if (q == "quit") break;
            cin >> a >> op >> b;
            Find(sa, a);
            Find(sb, b);
            if (sa[0] == sb[0]) continue;
            
            if ( q == "move" ) {
                Move(sa);
                if ( op == "onto") Move(sb);
                ss[sb[0]][++top[sb[0]]] = ss[sa[0]][top[sa[0]]--];
            }
            else {
                if ( op == "onto") Move(sb);
                for (int i=sa[1];i<=top[sa[0]];i++)
                    ss[sb[0]][++top[sb[0]]] = ss[sa[0]][i];
                top[sa[0]] = sa[1] - 1;
            }
        }
        REP(i, n) {
            printf("%d:",i);
            REP(j, top[i]+1)
                printf(" %d",ss[i][j]);
            printf("\n");
        }
    }
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 1039 - A Toy Company ->AC
* Algorithm bfs
* Time Limit 0.287s
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
string S, E;
map <string, bool> mm;
struct state{
    int pos,  cost;
    state(){}
    state(int pp, int cc){
        pos = pp; cost = cc;
    }
} a ;
int bfs_for_zero(char s, char e) {
    string tmp = "";
    int x = s - 'a';
    int y = e - 'a';
    map <string, bool> hh;
    queue <state> Q;
    Q.push(state(x, 0));
    while ( !Q.empty() ){
        a = Q.front(); Q.pop();
        if (a.pos == y) return a.cost;
        int nx = a.pos - 1;
        int ny = a.pos + 1;
        
        if (nx < 0) {
            tmp = 'z' + S[1] + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(25, a.cost + 1) );
            }
        }
        else {
            char ch = nx + 'a';
            tmp = ch + S[1] + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(ch - 'a', a.cost + 1) );
            }
        }
        
        if (ny > 25) {
            tmp = 'a' + S[1] + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(0, a.cost + 1) );
            }
        }
        else {
            char ch = ny + 'a';
            tmp = ch + S[1] + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(ch - 'a', a.cost + 1) );
            }
        }
    }
    return -1;
}
int bfs_for_one(char s, char e) {
    string tmp = "";
    int x = s - 'a';
    int y = e - 'a';
    map <string, bool> hh;
    queue <state> Q;
    Q.push(state(x, 0));
    while ( !Q.empty() ){
        a = Q.front(); Q.pop();
        if (a.pos == y) return a.cost;
        int nx = a.pos - 1;
        int ny = a.pos + 1;
        
        if (nx < 0) {
            tmp = S[0] + 'z'  + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(25, a.cost + 1) );
            }
        }
        else {
            char ch = nx + 'a';
            tmp = S[0] + ch  + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(ch - 'a', a.cost + 1) );
            }
        }
        
        if (ny > 25) {
            tmp = S[0] + 'a'  + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(0, a.cost + 1) );
            }
        }
        else {
            char ch = ny + 'a';
            tmp = S[0] + ch  + S[2];
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(ch - 'a', a.cost + 1) );
            }
        }
    }
    return -1;
}
int bfs_for_two(char s, char e) {
    string tmp = "";
    int x = s - 'a';
    int y = e - 'a';
    map <string, bool> hh;
    queue <state> Q;
    Q.push(state(x, 0));
    while ( !Q.empty() ){
        a = Q.front(); Q.pop();
        if (a.pos == y) return a.cost;
        int nx = a.pos - 1;
        int ny = a.pos + 1;
        
        if (nx < 0) {
            tmp = S[0] + S[1] + 'z';
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(25, a.cost + 1) );
            }
        }
        else {
            char ch = nx + 'a';
            tmp = S[0] + S[1] + ch;
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(ch - 'a', a.cost + 1) );
            }
        }
        
        if (ny > 25) {
            tmp = S[0] + S[1] + 'a';
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(0, a.cost + 1) );
            }
        }
        else {
            char ch = ny + 'a';
            tmp = S[0] + S[1] + ch;
            if ( mm[tmp] ) continue;
            if ( !hh[tmp] ) {
                hh[tmp] = true;
                Q.push( state(ch - 'a', a.cost + 1) );
            }
        }
    }
    return -1;
}
void Read() {
    int test, M, l1, l2 ,l3;
    string a, b, c;
    scanf("%d",&test);
    FOR(t, 1, test) {
        cin >> S;
        cin >> E; mm.clear();
        scanf("%d",&M);
        FOR(i, 1, M) {
            cin >> a >> b >> c;
            l1 = a.length(); l2 = b.length(); l3 = c.length();
            REP(i, l1)
                REP(j, l2)
                    REP(k, l3) {
                        string tmp = "";
                        tmp +=a[i];
                        tmp +=b[j];
                        tmp +=c[k];
                        mm[tmp] = true;
                    }
        }
        int r1 = bfs_for_zero(S[0], E[0]);
        int r2 = bfs_for_one(S[1], E[1]);
        int r3 = bfs_for_two(S[2], E[2]);
        if ( mm[S] || mm[E] ) r1 = -1;
        if ( r1 == -1 || r2 == -1 || r3 == -1) {
            printf("Case %d: -1\n",t);
            continue;
        }
        printf("Case %d: %d\n",t,r1 + r2 + r3);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1427 - Substring Frequency (II) ->AC
* Algorithm aho-corasick
* Time Limit 1.809s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000010
#define M 510
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
struct node{
    node* next[27];
    vector <int> out;
    node(){
        for (int i=0;i<27;i++) next[i] = NULL;
        out.clear();
    }
};
int n, ans[M];
char P[N];
char A[M][M];
node* root;
queue <node*> Q;
node* buildTrieWithFailure(char A[M][M], int n) {
    char c;
    node* root = new node;
    for (int i=0;i<n;i++) {
        node* p = root;
        for (int j=0; A[i][j]; j++) {
            c = A[i][j] - 'a' + 1;
            if ( !p->next[c] ) p->next[c] = new node;
            p = p->next[c];
        }
        p->out.pb(i);
    }
    for (int i=1;i<27;i++) {
        if ( !root->next[i] ) root->next[i] = root;
        else {
            Q.push(root->next[i]);
            root->next[i]->next[0] = root; 
        }
    }
    while ( !Q.empty() ) {
        node* u = Q.front(); Q.pop();
        for (int i=1;i<27;i++) if ( u->next[i] ) {
            node* v = u->next[i];
            node* w = u->next[0];
            while ( !w->next[i] ) w = w->next[0];
            v->next[0] = w->next[i];
            w = w->next[i];
            for (int j=0;j<w->out.size();j++) v->out.pb( w->out[j] );
            Q.push(v);
        }
    }
    return root;
}
void AhoCorasick(node* p, char P[N]) {
    char c;
    for (int i=0;P[i];i++) {
        c = P[i] - 'a' + 1;
        while ( !p->next[c] ) p = p->next[0];
        p = p->next[c];
        for (int j=0;j<p->out.size();j++) ans[ p->out[j] ]++;
    }
}
void deleteTrie(node* p) {
    for (int i=1;i<27;i++)
        if ( p->next[i] && p->next[i] != p ) deleteTrie( p->next[i] );
    delete p;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d %s ",&n, P);
        for (int i=0;i<n;i++) {
            scanf("%s",A[i]);
            ans[i] = 0;
        }
        root = buildTrieWithFailure(A, n);
        AhoCorasick(root, P);
        printf("Case %d:\n",++caseno);
        for (int i=0;i<n;i++) printf("%d\n",ans[i]);
        deleteTrie(root);
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1224 - DNA Prefix ->AC
* Algorithm trie
* Time Limit 0.129s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define N 51
#define maxN 1100000
using namespace std;

struct Node {
    int cnt, next[4];
} node[maxN];
int best, last;
char s[N];
void new_node(bool f = false) {
    if (f) last = 0;
    else last++;
    node[last].cnt = 0;
    for (int i=0;i<4;i++) node[last].next[i] = -1;
}
int convert(char a) {
    if (a == 'A') return 0;
    if (a == 'C') return 1;
    if (a == 'G') return 2;
    if (a == 'T') return 3;
}
void process() {
    gets(s); 
    int n = strlen(s), x;
    int cur = 0;
    for (int i=0;i<n;i++) {
        x = convert(s[i]);
        if ( node[cur].next[x] == -1){
            new_node();
            node[cur].next[x] = last;
            cur = last;
        }
        else cur = node[cur].next[x];
        node[cur].cnt++;
    }
}
void dfs(int cur, int m) {
    if ( m * (node[cur].cnt) > best ) best = m  * (node[cur].cnt);
    for (int i=0;i<4;i++)
        if ( node[cur].next[i] != -1)
            dfs(node[cur].next[i], m + 1);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d ",&n);
        new_node(true);
        for (int i=0;i<n;i++) process();
        best = 0;
        printf("Case %d: ",++caseno);
        dfs(0, 0);
        printf("%d\n",best);
    }
}

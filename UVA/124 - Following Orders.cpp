/***********************************************
* Author - LUONG VAN DO                        *
* 124 - Following Orders ->AC
* Algorithm Sort Topo
* Time Limit 0.012s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1001
using namespace std;
int adj[27][27];
int alpha[27];
int out[27];
int sl[27], n, found;
char s[maxN];
void dfs(int k, int n) {
    if (k == n) {
        int i;
        printf("%c",out[0]+97);
        for (i=1;i<n;i++)
            printf("%c",out[i]+97);
        puts("");
        found = 1;
    }
    else {
        Rep(i,26) {
            if (alpha[i] && !sl[i]) {
                alpha[i] = 0;
                Rep(j,26)
                    if (alpha[j] && adj[i][j]) sl[j]--;
                    out[k] = i;
                    dfs(k+1,n);
                    alpha[i] = 1;
                Rep(j,26)
                    if (alpha[j] && adj[i][j]) sl[j]++;
            }
        }
    }
}
void Solve(){
    dfs(0,n);
}
void Read_Input(){
    int blank;
    blank = 0;
    while (gets(s)) {
        int i;
        n = found = 0;
        Rep(i,26) {
            alpha[i] = sl[i] = 0;
            Rep(j,26) adj[i][j] = 0;
        }
        for (i=0;s[i];i++)
            if (s[i]!=' ' && !alpha[s[i]-'a'])
                alpha[s[i]-'a'] = 1, n++;
        gets(s);
        for (i=0;s[i];i++) {
            if (s[i]!=' ')
            if (!adj[s[i]-'a'][s[i+2]-'a']) {
                adj[s[i]-'a'][s[i+2]-'a'] = 1;
                sl[s[i+2]-'a']++;
                i+=2;
            }
        }
        if (blank) puts("");
        blank = 1;
        Solve();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

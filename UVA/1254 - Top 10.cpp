/***********************************************
* Author - LUONG VAN DO                        *
* 1254 - Top 10
* Algorithm
* Time Limit
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
#define maxN 50001
using namespace std;
struct Node{
    int isend;
    Node* Next[27];
};
map <string, int> Name;
string idx[maxN];
char s[maxN];
int n,m,l;
Node* root;
Node* New_node() {
    Node* node = new Node();
    node->isend = 0;
    Rep(i,26) node->Next[i] = NULL;
    return node;
}
void Read_Input(){
    root = New_node();
    Node* Tmp;
    scanf("%d ",&n);
    For(i,1,n) {
        gets(s);
        Tmp = root;
        l = strlen(s);
        Rep(j,l) {
            if (Tmp->Next[s[j]-'a']==NULL) Tmp -> Next[s[j]-'a'] = New_node();
            Tmp = Tmp -> Next[s[j]-'a'];
            Tmp -> isend = 0;
        }
        Tmp -> isend = i;
    }
    scanf("%d ",&m);
    For(i,1,m) {
        gets(s);
        Tmp = root;
        l = strlen(s);
        Rep(j,l) {
            Tmp = Tmp->Next[s[j]-'a'];
        }
        cout<<Tmp->isend<<endl;
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

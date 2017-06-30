/***********************************************
* Author - LUONG VAN DO                        *
* SEC ->AC
* Algorithm trie
* Time Limit 5.56s
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
    int cnt, end;
    Node* Next[2];
};
Node* root;
int n,m;
Node* New_Node(){
    Node* node = new Node();
    node->cnt = 0;
    node->end = 0;
    node->Next[0] = NULL;
    node->Next[1] = NULL;
    return node;
}
void Read_Input(){
    scanf("%d %d",&n,&m);
    root = New_Node();
    Node* Tmp;
    For(i,1,n){
        int q;
        Tmp =  root;
        scanf("%d",&q);
        while (q--){
            int bit;
            scanf("%d",&bit);
            if (Tmp->Next[bit]==NULL) Tmp->Next[bit] = New_Node();
            Tmp = Tmp->Next[bit];
            Tmp->cnt = Tmp->cnt + 1;
        }
        Tmp->end = Tmp->end + 1;
    }
}
int Solve(int q){
    int prefix = INF;
    int isend = 0;
    int bit,ok = 0;
    Node* Tmp = root;
    while (q--){    
        scanf("%d",&bit);
        if (ok) continue;
        isend+=Tmp->end;
        if (Tmp->Next[bit]==NULL){
            prefix = 0;
            ok = 1;
            continue;
        }
        Tmp = Tmp->Next[bit];
        if (Tmp->cnt < prefix) prefix = Tmp->cnt;
    }
    return isend + prefix;
}
void Write_Output(){
    For(i,1,m) {
        int q;
        scanf("%d",&q);
        printf("%d\n",Solve(q));
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
//    Solve();
    Write_Output();
}

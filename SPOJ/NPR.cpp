/***********************************************
* Author - LUONG VAN DO                        *
* NPR ->AC
* Algorithm Trie
* Time Limit 3.53s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
 
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Rep(i, n) for (int i=0; i<n; i++)
#define FORX(i,x,n) for (int i=x;i<=n;i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 250005
using namespace std;
struct Node{
    char Left[35], Right[35];
    Node* Next[27];
};
Node* New_Node(){
    Node* node = new Node();
    node ->Left[0] = '\0';
    node ->Right[0] = '\0';
    Rep(i,26) node -> Next[i] = NULL;
    return node;
}
Node* root;
void Read_Input(){
    char s[35];
    root = New_Node();
    Node* Tmp;
    while (gets(s) && strlen(s)){
        int i = strlen(s);
        Tmp = root;
        while ( true ){
            if ( strcmp(Tmp->Left,"")==0) strcpy(Tmp->Left,s);
            else {
                if (strcmp(Tmp->Right,"") == 0 || strcmp(s,Tmp->Right) < 0) {
                    if ( strcmp(s,Tmp->Left) < 0) {
                        strcpy(Tmp->Right, Tmp->Left);
                        strcpy(Tmp->Left, s);
                    }
                    else strcpy(Tmp->Right, s);
                }
            }
            i--;
            if (i<0) break;
            if (Tmp->Next[s[i]-'a']==NULL) Tmp->Next[s[i]-'a'] = New_Node();
            Tmp = Tmp->Next[s[i]-'a'];
        }
    }
}
void Write_Output(){
    char s[35];
    char rs[35];
    Node* Tmp;
    while (gets(s) && strlen(s)){
        int i = strlen(s);
        Tmp = root;
        while ( true ){
            if ( strcmp(Tmp->Left,s)!=0) strcpy(rs, Tmp->Left);
            else
                if (strcmp(Tmp->Right,"")!=0) strcpy(rs, Tmp->Right);
            i--;
            if (i<0) break;
            if (Tmp->Next[s[i]-'a']==NULL) Tmp->Next[s[i]-'a'] = New_Node();
            Tmp = Tmp->Next[s[i]-'a'];
        }
        puts(rs);
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    Write_Output();
}

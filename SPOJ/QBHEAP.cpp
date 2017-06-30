/***********************************************
* Author - LUONG VAN DO                        *
* QBHEAP ->AC
* Algorithm heap
* Time Limit 0.45s
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
#define maxN 15001
using namespace std;
int nheap,nm;
int a[maxN];
int rs[maxN];
void update(int val){
    int parent,child;
    a[++nheap] = val;
    child = nheap;
    parent = child >> 1;
    while ( parent > 0 && a[parent] < val )
    {
        a[child] = a[parent];
        child = parent;
        parent = child >> 1;        
    }
    a[child] = val;
}
int down_heap(){
    int u,v,r;
    u = a[1];
    v = a[nheap--];
    //a[1] = a[nheap];
//    nheap--;
    r = 1;
    while ( 2 * r <= nheap)
    {
        int c = 2 * r;
        if (c < nheap && a[c+1] > a[c] ) ++c;
        if (v>=a[c]) break;
        a[r] = a[c];
        r = c;
    }
    a[r] = v;
    return u;
}
void Delete(){
    int u = down_heap();
    while (u==a[1] && nheap!=0)
    {
        u = down_heap();
    }
}
void Read_Input(){
    char s[50];
    nheap = 0;
    int val;
    while ( gets( s ) )
    {
        if (s[0]=='+' && nheap<15000)
        {
            sscanf(s+1,"%d",&val);
            update(val);
        }
        else
        if (s[0]=='-' && nheap!=0)
            Delete();
    }
}
void Write_Output(){
    sort(a+1,a+nheap+1);
    a[0] = a[1] - 1;
    nm = 0;
    For(i,1,nheap)
        if (a[i]!=a[i-1]) rs[++nm] = a[i];
    printf("%d\n",nm);
    Ford(i,nm,1)
        printf("%d\n",rs[i]);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    Write_Output();
}

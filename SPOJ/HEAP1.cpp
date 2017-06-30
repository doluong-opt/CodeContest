/***********************************************
* Author - LUONG VAN DO                        *
* HEAP1 ->AC
* Algorithm heap
* Time Limit 0.05s
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
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 20001
using namespace std;
int a[maxN],n, nheap;
int64 res;
void Down_heap(int root, int nn){
    int key,r;
    key = a[root];
    r = root;
    while (2 * r<=nn)
    {
        int c = 2 * r;
        if (c < nn && a[c+1] < a[c]) c++;
        if (key<=a[c]) break;
        swap(a[r],a[c]);
        r = c;
    }
    a[r] = key;
}
void Solve(){
    nheap = n;
    for (int i=n/2;i>=1;i--)
        Down_heap(i, n);
    int64 tmp;
    while (nheap!=1)
    {
        tmp = 0;
        tmp+=a[1];
        swap(a[1],a[nheap]);
        nheap--;
        Down_heap( 1 , nheap);
        tmp+=a[1];
        swap(a[1],a[nheap]);
        nheap--;
        Down_heap(1, nheap);
        res+=tmp;
        a[++nheap] = tmp;
    }
}
void Write_Output(){
    printf("%lld\n",res);
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        res = 0;
        scanf("%d",&n);
        For(i,1,n) scanf("%d",&a[i]);
        Solve();
        Write_Output();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
}

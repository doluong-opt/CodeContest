/***********************************************
* Author - LUONG VAN DO                        *
* VPARTSUM ->AC
* Algorithm Nhi Phan
* Time Limit 1.24s
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
#define maxN 100005
using namespace std;
struct node
{
    int val,id;
};
int n,k,p,posj,posi;
node s[maxN];
bool cmp(node c, node d){
    if (c.val!=d.val) return (c.val < d.val);
    return (c.id < d.id);
}
int fx(int key, int l, int r){
    while (l<=r)
    {
        int mid = (l + r) >> 1;
        if (key>=s[mid].val) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}
void Read_Input(){
    scanf("%d %d %d",&n,&k,&p);
    s[0].val = 0; s[0].id = 0;
    For(i,1,n)
    {
        int v;
        scanf("%d",&v);
        s[i].val = (s[i-1].val + v) % p;
        s[i].id = i;
    }
    sort(s+1,s+1+n,cmp);
    int rs = INF,j;
    for (int i=1;i<=n;i++)
    {
        if (s[i].val>=k)
        {
            j = fx(s[i].val - k, 1, n);
            if ( j < i)
            rs = min(rs,s[i].val - s[j].val);
        }        
    }
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

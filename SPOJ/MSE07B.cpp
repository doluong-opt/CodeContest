/***********************************************
* Author - LUONG VAN DO                        *
* MSE07B ->AC
* Algorithm Set
* Time Limit 0.6s
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
#include <set>
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
typedef struct node
{
    int k,p;
    node(){}
    node(int kk, int pp)
    {
        k = kk; p = pp;
    };
};
bool operator < (const node& a,const node& b);
set <node> User;
set <node>::iterator it;
void Read_Input(){
    int q;
    while ( scanf("%d",&q) && q)
    {
        if (q==1)
        {
            int K,P;
            scanf("%d %d",&K,&P);
            User.insert(node(K,P));
        }
        else
        if (q==2)
        {
            if (!User.size()) puts("0");
            else
            {
                it = User.end();
                it--;
                node Userid = *it;
                printf("%d\n",Userid.k);
                User.erase(Userid);
            }
        }
        else
        {
            if (!User.size()) puts("0");
            else
            {
                node Userid  = *User.begin();
                printf("%d\n",Userid.k);
                User.erase(Userid);
            }
        }
    }
}
bool operator < (const node& a,const node& b)
{
    return a.p < b.p;
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

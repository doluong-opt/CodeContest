/***********************************************
* Author - LUONG VAN DO                        *
* NICEQUAD ->AC
* Algorithm Adhoc
* Time Limit 0.33s
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
uint64 g[6][6];
uint64 rs;
int f(int xx){
    if (xx%2 == 0) {
        if (xx > 0) return 2;
        return -2;
    }
    return (xx > 0)? 1 : -1;
}
void Solve(){
    rs = 0;
    For(ax,-2,-1)
    For(ay,1,2)
        if (g[ax+2][ay+2])
            For(bx,1,2)
            For(by,1,2)
                if (g[bx+2][by+2])
                    For(cx,1,2)
                    For(cy,-2,-1)
                        if (g[cx+2][cy+2])
                            For(dx,-2,-1)
                            For(dy,-2,-1)
                                if(g[dx+2][dy+2]) {
                                    int64 s = (bx - ax)*(by + ay + 4) + (cx - bx)*(cy + by + 4) + (dx - cx)*(dy + cy + 4) + (ax - dx)*(ay + dy + 4);
                                    if (s%2==0) rs+=(g[ax+2][ay+2]*g[bx+2][by+2]*g[cx+2][cy+2]*g[dx+2][dy+2]);
                                }
}
void Write_Output() {
    printf("%lld\n",rs);
}
void Read_Input() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        For(i,0,5)
            For(j,0,5) g[i][j] = 0;
        scanf("%d",&n);
        For(i,1,n) {
            int x,y;
            scanf("%d %d",&x,&y);
            if (!x || !y) continue;
            x = f(x); y = f(y);
            g[x+2][y+2]++;
        }
        Solve();
        Write_Output();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();    
}

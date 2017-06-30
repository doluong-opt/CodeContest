/***********************************************
* Author - LUONG VAN DO                        *
* TCDFZ ->AC
* Algorithm Adhoc
* Time Limit 0.02s
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
int n,rs;
int a[10];
void Init(){
    a[1] = 6;
    a[2] = 2;
    a[3] = 6;
    a[4] = 4;
    a[6] = 4;
    a[7] = 8;
    a[8] = 4;
    a[9] = 6;
}
int Chia(int x){
    switch (x)
    {
        case 2: return 6;
        case 4: return 2;
        case 6: return 8;
        case 8: return 4;
    }
}
void Read_Input(){
    Init();
    scanf("%d",&n);
}
void Solve(){
    rs = 1;
    if (n<=1) return;
    else
    {
        do
        {
            int c5 = n / 5;
            if ( n % 5 == 0)
                rs = (rs * ( a[ (n - 1) % 10 ]) ) % 10;
            else
                rs = (rs * ( a[ n % 10] ) ) % 10;
            for (int i=1;i<=(c5%4);i++)
                rs = Chia( rs );
            n /= 5;
        } while ( n > 1);
    }
}
void Write_Output(){
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}

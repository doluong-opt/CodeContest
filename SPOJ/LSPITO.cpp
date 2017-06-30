/***********************************************
* Author - LUONG VAN DO                        *
* LSPITO
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
int64 k;
vector <int64> v;
void Solve(){
    int64 i = 2, bit = 0, kk = 4 ,j = 3;
    while ( i<=2000000000000LL )
    {
        v.pb( i );
        if (j==kk) kk<<=1, bit = 1;
        i+=j; j+=bit; bit = !bit;
    }
}
void Write_Output(){
    if ( !binary_search(v.begin(), v.end(), k) ) puts("Conan");
    else puts("Thu Uyen");
}
void Read_Input(){
    Solve();
    while ( scanf("%lld",&k)!=EOF)
    {
        Write_Output();
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

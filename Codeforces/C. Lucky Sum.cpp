/***********************************************
* Author - LUONG VAN DO                        *
* C. Lucky Sum ->AC
* Algorithm Adhoc
* Time Limit 50ms
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int l,r;
uint64 rs, ans;
void Find(uint64 m, uint64 n){
    if (m > 100000000000000ll) return;
    if (m>=n) {
        if (ans==0) ans = m;
        else ans = min(ans, m);
        return;
    }
    Find(m*10 + 4, n);
    Find(m*10 + 7, n);
}
uint64 Next(int n){
    ans = 0;
    Find(0 , n);
    return ans;
}
void Read_Input(){
    cin >> l >> r;
    rs = 0;
    while (l<=r) {
        uint64 lucky = Next( l );
        if ( lucky <= r ) {
            rs+=(lucky - l + 1) * lucky;
            l = lucky + 1;
        }
        else
        if ( lucky > r ){
            rs+=(r - l + 1) * lucky;
            l = r + 1;
        }
    }
    cout<< rs <<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
    return 0;
}

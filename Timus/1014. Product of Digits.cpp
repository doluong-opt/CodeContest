/***********************************************
* Author - LUONG VAN DO                        *
* Product of Digits ->AC
* Algorithm Adhoc
* Time Limit 0.015s
* *********************************************/
#include <iostream>
#include <cstdio>
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

#define maxN 50001
using namespace std;
int found ,n;
vector <int> res;
void Solve(int n){
    found = 1;
    if (n < 10){
        res.pb(n);
        return;
    }
    while ( n>=2 ){
        found = 0;
        for (int i=9;i>=2;i--) {
            if ( n%i==0 ) {
                found = 1;
                res.pb( i );
                n/=i;
                break;
            }
        }
        if (!found) break;
    }
}
void Write_Output() {
    if (n==0) {
        printf("10\n");
        return;
    }
    if (found) {
        sort(res.begin(),res.end());
        for (int i=0;i<res.size();i++)
            printf("%d",res[i]);
            printf("\n");
    }
    else printf("-1\n");
}
void Read_Input(){
    while (scanf("%d",&n)!=EOF) {
        res.clear();
        Solve( n );
        Write_Output();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

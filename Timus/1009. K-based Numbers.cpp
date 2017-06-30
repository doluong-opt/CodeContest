/***********************************************
* Author - LUONG VAN DO                        *
* K-based Numbers ->AC
* Algorithm dp
* Time Limit 0.031s
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
int n,k;
int64 p,d;
void Read_Input(){
    scanf("%d %d",&n,&k);
    p = (k - 1) * (k - 1);
    d = k - 1;
    for (int i=3;i<=n;i++) {
        int64 t = p;
        p = p * (k - 1) + d * (k - 1);
        d = t;
    }
}
void Write_Output(){
    printf("%lld\n",p + d);
}
int main(){    
    Read_Input();
    //Solve();
    Write_Output();
    return 0;
}

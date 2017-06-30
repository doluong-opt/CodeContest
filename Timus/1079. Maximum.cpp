/***********************************************
* Author - LUONG VAN DO                        *
* Maximum ->AC
* Algorithm Adhoc
* Time Limit 0.015s
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
#define maxN 990001
using namespace std;
int n;
int a[maxN];
int f[maxN];
void Init(){
    a[0] = 0; a[1] = 1;
    f[0] = 0; f[1] = 1;
    for (int i=2;i<=99999;i++) {
        if (i % 2) a[i] = a[i>>1] + a[(i>>1)+1];
        else a[i] = a[i>>1];
        f[i] = max(f[i-1],a[i]);
    }
}
void Read_Input(){
    Init();
    while (scanf("%d",&n) && n){
        cout << f[n] <<endl;
    }
}
int main(){
    Read_Input();
    return 0;
}

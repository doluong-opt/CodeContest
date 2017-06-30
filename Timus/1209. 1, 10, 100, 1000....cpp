/***********************************************
* Author - LUONG VAN DO                        *
* 1, 10, 100, 1000... ->AC
* Algorithm Adhoc
* Time Limit 0.312s
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
map <int, bool> f;
void Init(){
    f[1] = true;
    int inc,x;
    inc = x = 1;
    while ( true ) {
        x = x + inc;
        if (x < 0) break;
        f[x] = true;
        inc++;
    }
}
void Read_Input(){
    Init();
    scanf("%d",&n);
    For(i,1,n) {
        scanf("%d",&k);
        if (i > 1) printf(" ");
        if (f[k]) printf("1");
        else printf("0");
    }
    printf("\n");
}
int main(){
    Read_Input();
    return 0;
}

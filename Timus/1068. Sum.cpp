/***********************************************
* Author - LUONG VAN DO                        *
* Sum ->AC
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
#define maxN 50001
using namespace std;
int64 rs,n;
void Read_Input(){
    scanf("%lld",&n);
    rs = ((1 + abs(n)) * abs(n)) / 2;
    if (n<0) rs--, rs*=-1;
    if (n==0) puts("1");
    else printf("%d\n",rs);
}
int main(){
    Read_Input();
    return 0;
}

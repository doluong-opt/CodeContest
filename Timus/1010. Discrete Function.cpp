/***********************************************
* Author - LUONG VAN DO                        *
* Discrete Function ->AC
* Algorithm Adhoc
* Time Limit 0.062s
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
int64 n, v, Max, pos, u;
void Read_Input(){
    Max = pos = 0;
    scanf("%lld",&n);
    scanf("%lld",&v);
    For(i,1,n-1) {
        scanf("%lld",&u);
        int64 temp = abs(u - v);
        if (temp > Max) {
            Max = temp;
            pos = i;
        }
        v = u;
    }
}
void Write_Output(){
    printf("%lld %lld\n",pos,pos + 1);
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    Write_Output();
    return 0;
}

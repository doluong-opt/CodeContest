/***********************************************
* Author - LUONG VAN DO                        *
* Sequence Median
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxN 250001
using namespace std;
double a[maxN];
int n;
void Read_Input(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
    sort(a+1,a+1+n);
        if (1 & n) printf("%.1lf\n",a[(n+1)/2]);
    else
        if ((1 & n)==0) printf("%.1lf\n",(a[n/2] + a[n/2+1])/2.0);
}
int main(){
    Read_Input();
    return 0;
}

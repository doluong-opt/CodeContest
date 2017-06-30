/***********************************************
* Author - LUONG VAN DO                        *
* Simple Calculations ->AC
* Algorithm Chat Nhi Phan
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
using namespace std;
const double eps = 1e-9;
double a[3005], c[3005];
double xx;
int n;
void Read_Input(){
    scanf("%d",&n);
    scanf("%lf %lf",&a[0],&a[n+1]);
    for (int i=1;i<=n;i++) scanf("%lf",&c[i]);
}
void Try(){
    for (int i=2;i<=n;i++) a[i] = 2 * (a[i-1] + c[i-1]) - a[i-2];
    xx = 2 * (a[n] + c[n]) - a[n-1];
}
void Write_Output(){
    double l,r;
    l = -2000.0; r = 2000.0;
    while (l - r < eps) {
        double mid = (l + r) / 2.0;
        a[1] = mid;
        Try();
        if (fabs(a[n+1] - xx) < eps) {
            printf("%.2lf\n",mid);
            break;
        }
        else if (a[n+1] - xx < eps) r = mid; else l = mid;
    }
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    Write_Output();
    return 0;
}

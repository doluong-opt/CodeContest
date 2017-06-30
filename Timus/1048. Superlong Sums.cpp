/***********************************************
* Author - LUONG VAN DO                        *
* Superlong Sums ->AC
* Algorithm Adhoc
* Time Limit 0.671s
* *********************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int a[1000005], b[1000005];
int c[1000005];
int m,n,nho;
void Read_Input(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
    nho = 0;
    for (int i=n;i>=1;i--) {
        nho += a[i] + b[i];
        c[i] = nho % 10;
        nho = nho / 10;
    }
}
void Write_Output(){
    for (int i=1;i<=n;i++)
        printf("%d",c[i]);
    printf("\n");
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    Write_Output();
    return 0;
}

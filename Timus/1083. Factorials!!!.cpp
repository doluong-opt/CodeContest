/***********************************************
* Author - LUONG VAN DO                        *
* Factorials!!! ->AC
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

using namespace std;
int n,k;
char p[25];
void Read_Input(){
    scanf("%d ",&n);
    gets(p); k = strlen(p);
}
long long Solve(){
    long long rs = 1;
    int t = n % k;
    int cnt = 0;
    if (t) {
        while (n-cnt*k>=t ) {
            rs*=(n - cnt * k);            
            cnt++;
        }
    }
    else {
        while (n-cnt*k>=k) {
            rs*=(n - cnt * k);
            cnt++;
        }
    }
    return rs;
}
void Write_Output(){
    printf("%d\n",Solve());
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    Solve();
    Write_Output();
    return 0;
}

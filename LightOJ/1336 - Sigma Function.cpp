/***********************************************
* Author - LUONG VAN DO                        *
* 1336 - Sigma Function ->AC
* Algorithm math
* Time Limit 1.286s
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

#define uint64 unsigned long long
#define int64 long long

using namespace std;

int main(){
    freopen("exam.inp","r",stdin);
    freopen("exam.out","w",stdout);
    int cases, caseno = 0;
    int64 ans, n;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lld",&n);
        ans = n - (int)sqrt(n);
        ans-=(int)sqrt(n>>1);
        printf("Case %d: %lld\n",++caseno, ans);
    }
    return 0;
}

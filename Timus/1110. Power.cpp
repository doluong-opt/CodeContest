/***********************************************
* Author - LUONG VAN DO                        *
* Power ->AC
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
int n,m,y,found;
void Read_Input(){
    scanf("%d %d %d",&n,&m,&y);
}
int square(int s){
    return ((s % m) * (s % m)) % m;
}
int mod(int x, int n, int m){
    if (n==0) return 1;
    if (n % 2) return ( (x % m) * mod(x,n-1,m) % m) % m;
    else return square( mod(x,n/2,m) ) % m;
}
void Solve(){
    found = 0;
    int blank = 0;
    for (int i=0;i<m;i++) {
        if ( mod(i,n,m) == y) {
            if (blank) printf(" ");
            blank = 1;
            found = 1;
            printf("%d",i);
        }
    }
    if (!found) printf("-1");
    printf("\n");
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    Solve();
    return 0;
}

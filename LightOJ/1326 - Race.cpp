/***********************************************
* Author - LUONG VAN DO                        *
* 1326 - Race ->AC
* Algorithm dp
* Time Limit 0.01s
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 ans[1005];
void init(){
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;
    ans[3] = 13;
    int64 num[1005];
    for (int i=0;i<1005;i++) num[i] = 1;
    num[0] = 1;
    num[1] = 4;
    num[2] = 6;
    num[3] = 4;
    for (int i=4;i<=1000;i++) {
        int64 val = 0;
        for (int j=i-1;j>=0;j--) {
            val+=(num[j] * ans[j]) % 10056;
            val%=10056;
        }
        ans[i] = val;
        for (int j=i;j>=1;j--) {
            num[j]+=num[j-1];
            num[j]%=10056;
        }
    }
}
void Read_Input(){
    int test,n;
    init();
    scanf("%d",&test);
    for (int i=1;i<=test;i++) {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,ans[n]);
    }
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    return 0;
}

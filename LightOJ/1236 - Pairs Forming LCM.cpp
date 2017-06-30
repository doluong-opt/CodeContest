/***********************************************
* Author - LUONG VAN DO                        *
* 1236 - Pairs Forming LCM ->AC
* Algorithm math 
* Time Limit 0.451s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>


#define uint64 unsigned long long
#define int64 long long

#define MAX 10000007
#define LMT 3165
#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

using namespace std;

vector <int> V;
int flag[MAX / 64];
int Size;
int64 n;
void sieve() {
    int i,j,k;
    flag[0]|=0;
    for (i=3;i<LMT;i+=2)
        if ( !chkC(i) )
            for (j=i*i,k=i<<1;j<MAX;j+=k) setC(j);
    V.push_back( 2 );
    for (i=3;i<MAX;i+=2)
        if (!chkC(i)) V.push_back(i);
    Size = V.size();
}
int64 solve(){
    int64 res, ans;
    res = 1;
    int ind = 0, cnt;
    while ( ind < Size && (int64)V[ind] * (int64)V[ind] <= n) {
        cnt = 0;
        while ( n % V[ind] == 0 ) {
            n/=V[ind];
            cnt++;
        }
        ++ind;
        res*=(2 * cnt + 1);
    }
    if (n > 1)
        res*=3;
    return (res - 1) / 2 + 1;
}
void Read_Input(){
    int test;
    sieve();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",t,solve());
    }
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    return 0;
}

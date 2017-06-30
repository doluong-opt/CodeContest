/***********************************************
* Author - LUONG VAN DO                        *
* 1278 - Sum of Consecutive Integers ->AC
* Algorithm math
* Time Limit 0.287s
* *********************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxN 10000005
unsigned long long n;
bool Free[maxN];
vector <int> V;
int Size;

void sieve(){
    for (int i=1;i<maxN;i++) Free[i] = 1;
    Free[1] = 0;
    for (int i=4;i<maxN;i+=2) Free[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if ( Free[i] )
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = 0;
    V.push_back( 2 );
    for (int i=3;i<maxN;i+=2)
        if (Free[i]) V.push_back( i );
    Size = V.size();
}
long long solve(){
    long long cnt, ind, ans;
    ans = 1;
    ind = 0;
    n = 2 * n;
    while (ind < Size && (long long)V[ind] * (long long)V[ind] <= n) {
        cnt = 0;
        while ( n % V[ind] == 0 ) {
            cnt++;
            n/=V[ind];
        }
        if (V[ind]!=2) ans*=(cnt + 1);
        ind++;
    }
    if (n > 1 && n!=2) ans*=2;
    return ans - 1;
}
void Read_Input(){
    int test;
    sieve();
    scanf("%d",&test);
    for (int i=1;i<=test;i++) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i,solve());
    }
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    return 0;
}

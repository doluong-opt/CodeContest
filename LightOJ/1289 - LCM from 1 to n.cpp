/***********************************************
* Author - LUONG VAN DO                        *
* 1289 - LCM from 1 to n ->AC
* Algorithm math
* Time Limit 1.124s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <set>
 
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0;i<n;i++)
#define uint64 unsigned long long
#define int64 long long

#define MOD 4294967296LL
#define MAX 100000000
#define LMT 10000

#define Chk(n) (_flag[n>>6]&(1<<((n>>1)&31)))
#define Set(n) _flag[n>>6]|=(1<<((n>>1)&31))

using namespace std;
struct node{
    int x, id;
    node(){}
    node(int xx, int idd){
        x = xx; id = idd;
    }
    bool operator < (const node &other) const{
        return x < other.x;
    }
};
vector <int> primes;
int64 _flag[(MAX >> 6) + 1];
int sz, prime, nn;
node data[LMT + 5];
int64 ans[LMT + 5];
set < pair <int, int> > S;
set < pair <int, int> > :: iterator it;
void sieve() {
    for (int i=3;i<=LMT;i+=2)
        if (!Chk(i))
            for (int j=i*i;j<=MAX;j+=i + i) Set(j);
    primes.push_back( 2 );
    for (int i=3;i<=MAX;i+=2)
        if (!Chk(i)) primes.push_back(i);
    sz = primes.size();
}
void init() {
    int64 x;
    REP(i, sz) {
        x = primes[i];
        if (x>=10000) break;
        for (int64 i=x;i<=MAX;i*=x)
            S.insert(make_pair(i, x));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    init();
    int test;
    int64 res, cnt, p;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&data[t].x);
        data[t].id = t;
    }
    sort(data + 1, data + test + 1);
    res = 1; cnt = 9975;
    it = S.begin();
    FOR(i, 1, test) {
        
        for (; it!=S.end() && it->first <= data[i].x; it++)
            res = ((res % MOD) * (it->second % MOD)) % MOD;
            
        while (cnt <= data[i].x) {
            if (!Chk(cnt) ) res = ((res % MOD) * (cnt % MOD)) % MOD;
            cnt+=2;
        }
        ans[ data[i].id ] = res;
    }
    FOR(i, 1, test)
        printf("Case %d: %lld\n",i,ans[i]);
    return 0;
}

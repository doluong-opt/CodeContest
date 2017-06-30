/***********************************************
* Author - LUONG VAN DO                        *
* A. Noldbach problem ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
vector <int> prime;
int p[1005];
int n,k;
void sieve(){
    for (int i=1;i<=1000;i++)
        p[i] = 1;
    p[1] = 0;
    for (int i=4;i<=1000;i+=2) p[i] = 0;
    for (int i=3;i*i<=1000;i+=2)
        if (p[i])
            for (int j=i*i;j<=1000;j+=2*i) p[j] = 0;
    prime.pb(2);
    for (int i=3;i<=1000;i+=2)
        if (p[i]) prime.pb(i);
}
bool Check(int m){
    m--;
    for (int i=0;i<prime.size()-1;i++)
        if ((prime[i] + prime[i+1]) == m) return true;
    return false;
}
void Read_Input(){
    bool ok = 0;
    int cnt = 0;
    sieve();
    scanf("%d %d",&n,&k);
    for (int i=2;i<=n;i++) {
        if (p[i] && Check( i ) ) cnt++;
        if (cnt>=k) {
            ok = 1;
            break;
        }
    }
    if (ok) puts("YES");
    else puts("NO");
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10669 - Three powers ->AC
* Algorithm Adhoc
* Time Limit 0.012s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
string Ans[M + 1];
int bit[M + 1];
string conver(uint64 x){
    string tmp = "";
    while ( x ) {
        tmp = char(x % 10 + 48) + tmp;
        x/=10;
    }
    return tmp;
}
string mutiple(string x, uint64 m){
    string rs = "";
    uint64 sum = 0, nho = 0;
    for (int i=x.size()-1;i>=0;i--) {
        sum = (x[i] - '0') * m + nho;
        rs = char(sum % 10 + 48) + rs;
        nho = sum / 10;
    }
    if (nho > 0) return conver(nho) + rs;
    return rs;
}
void inital(){
    Ans[0] = "1";
    for (int i=1;i<=64;i++)
        Ans[i] = mutiple(Ans[i-1], 3LL);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, nm, ind;
    uint64 n;
    inital();
    while ( scanf("%lld",&n) && n){
        nm = 0; n--;
        memset(bit, 0, sizeof(bit));
        while ( n ) {
            bit[nm++] = n % 2;
            n/=2;
        }
        printf("{ "); ind = 0;
        while (ind <=64 && !bit[ind]) ++ind;
        cout<<Ans[ind];
        for (int i=ind + 1;i<=64;i++)
            if (bit[i]) cout <<", "<<Ans[i];
        printf(" }\n");
    }
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10302 - Summation of Polynomials ->AC
* Algorithm Adhoc
* Time Limit 0.232s
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
#define M 50000

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
string conver(uint64 N){
    string tmp = "";
    while ( N ){
        tmp = (char)(N % 10 + 48) + tmp;
        N/=10;
    }
    return tmp;
}
string Add(string x, string y) {
    int64 sum, nho;
    string c = "";
    sum = nho = 0;
    while (x.length() < y.length()) x = "0" + x;
    while (x.length() > y.length()) y = "0" + y;
    for (int i=x.length()-1;i>=0;i--) {
        sum = (x[i] - '0') + (y[i] - '0') + nho;
        c = char(sum % 10 + 48) + c;
        nho = sum / 10;
    }
    if (nho > 0) c = "1" + c;
    return c;
}
void inital() {
    Ans[1] = "1";
    for (int64 i = 2;i<=M;i++)
        Ans[i] = Add(Ans[i-1], conver(i * i * i));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    inital();
    int n;
    while ( scanf("%d",&n) !=EOF){
        cout<< Ans[n] <<endl;
    }
    
}

/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1111

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

vector <string> str;
int n,d;
string x, y;
bool mark[N];
char s[N];
bool Solve(int u) {
    int kt=0,kt1;
    string tg,ch,tam;
    mark[u] = false;
    ch = str[u];
    tam = str[u];
    x = tam[0];
    tam.replace(0,1,"");
    while (1){
        kt1 = 0;
        for (int i=0;i<n-d+1;i++){
            tg=str[i];
            tg.replace(tg.length()-1,1,"");
            if (tg==tam && mark[i]) {
                mark[i]=false;
                kt++;
                ch+=str[i];
                tam=str[i];
                tam.replace(0,1,"");
                break;
            }
            else kt1++;
        }   
        if (kt1==n-d+1){
            y=ch[ch.length()-1];
            if (kt==n-d) return true;
            else return false;
        }
    }
}
int main(){
    //freopen("exam.inp","r",stdin); freopen("exam.out","w",stdout);
    scanf(" %d %d ",&n, &d);
    for (int i=1;i<=n-d+1;i++) {
        gets(s);
        str.push_back(s);
    }
    int i=0;
    memset(mark,true,sizeof(mark));
    while ( !Solve(i) ){
        memset(mark,true,sizeof(mark));
        i++; 
    }
    cout<<x<<y<<endl;
}

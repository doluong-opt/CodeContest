/***********************************************
* Author - LUONG VAN DO                        *
* 1081. Binary Lexicographic Sequence ->AC
* Algorithm Dp
* Time Limit 0.031s
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
int n,k;
int f[45], res[maxN];
void Solve(int d, int k){
    if (!k) return;
    for (int i=d;i>=1;i--) {
        if ( k>=f[i]) {
            k-=f[i];
            res[i] = 1;
            Solve(i - 2, k);
        }
    }
}
void Read_Input() {
    f[0] = 1; f[1] = 1;
    for (int i=2;i<=44;i++)
        f[i] = f[i-1] + f[i-2];
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++) res[i] = 0;
    k--;
    if (k >= f[n+1]) {
        puts("-1");
        return;
    }
    Solve( 44 , k );
    for (int i=n;i>=1;i--) printf("%d",res[i]);
    puts("");
}
int main(){
    Read_Input();
    system("pause");
    return 0;    
}

/***********************************************
* Author - LUONG VAN DO                        *
* 435 - Block Voting ->AC
* Algorithm bit
* Time Limit 0.86s
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
int n, half;
int v[25], rs[25], s[3];
void Read_Input(){
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++) {
        scanf("%d",&n);
        memset(rs, 0, sizeof(rs)); half = 0;
        for (int k=0;k<n;k++) {            
            scanf("%d",&v[k]);
            half+=v[k];
        }
        half = half / 2 + 1;
        for (int bit=0;bit<(1<<n);bit++) {
            int tmp = bit;
            for (int k=n-1;k>=0;k--) {
                s[tmp & 1]+=v[k];
                tmp = (tmp >> 1);
            }
            tmp = bit;
            for (int k=n-1;k>=0;k--) {
                if (tmp & 1) {
                    int sum = s[1] - v[k];
                    if (sum<=half - 1 && sum + v[k]>=half)
                        rs[k]++;
                }
                tmp = (tmp >> 1);
            }
            s[0] = s[1] = 0;
        }
        for (int k=0;k<n;k++) printf("party %d has power index %d\n",k+1,rs[k]);
        printf("\n");
    }
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

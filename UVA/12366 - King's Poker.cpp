/***********************************************
* Author - LUONG VAN DO                        *
* 12366 - King's Poker ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
int x[6];
void Read_Input(){
    while ( scanf("%d %d %d",&x[1],&x[2],&x[3]) && (x[1] + x[2] + x[3]) ){
        if (x[1]==x[2] && x[2]==x[3] && x[1]==13) {
            puts("*");
            continue;
        }
        sort(x+1,x+4);
        if (x[1]==x[2] && x[2]==x[3]) {
            printf("%d %d %d\n",x[1]+1,x[2]+1,x[3]+1);
            continue;
        }
        if (x[1]==x[2] && x[3] < 13) {
            printf("%d %d %d\n",x[1],x[2], x[3] + 1);
            continue;
        }
        if (x[1] < 13 && x[1]==x[2] && x[3] == 13) {
            printf("%d %d %d\n",1,x[1]+1,x[2]+1);
            continue;
        }
        if (x[2]==x[3] && x[2]==13) {
            if (x[1]+1!=13) printf("%d %d %d\n",x[1]+1,x[2],x[3]);
            else printf("1 1 1\n");
            continue;
        }
        if (x[2]==x[3] && x[2] < 13) {
            x[1]++;
            while (x[1] < 13 && x[1]==x[2]) x[1]++;
            sort(x+1,x+4);
            printf("%d %d %d\n",x[1],x[2],x[3]);
            continue;
        }
        if(x[1]!=x[2] && x[2]!=x[3] && x[3]!=x[1]) printf("%d %d %d\n",1,1,2);
    }    
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

/***********************************************
* Author - LUONG VAN DO                        *
* 102 - Ecological Bin Packing ->AC
* Algorithm Adhoc
* Time Limit 0.072s
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
char com[7][7] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
int bottles[10];
int64 out[7];
int64 Count(int a, int b, int c){
    int64 cnt = 0;
    for (int i=0;i<9;i++)
        if (a!=i && b!=i && c!=i) cnt+=bottles[i];
    return cnt;
}
void Read_Input(){
    while ( scanf("%d",&bottles[0])!=EOF) {
        char res[6];
        int64 min_move = INF;
        for (int i=1;i<9;i++) scanf("%d",&bottles[i]);        
        out[0] = Count(0,5,7);
        out[1] = Count(0,4,8);
        out[2] = Count(2,3,7);
        out[3] = Count(2,4,6);
        out[4] = Count(1,3,8);
        out[5] = Count(1,5,6);
        for (int i=0;i<6;i++)
            if ( out[i] < min_move) {
                min_move = out[i];
                strcpy(res, com[i]);
            }
        printf("%s %lld\n",res, min_move);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

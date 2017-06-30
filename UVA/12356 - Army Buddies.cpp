/***********************************************
* Author - LUONG VAN DO                        *
* 12356 - Army Buddies ->AC
* Algorithm List
* Time Limit 0.164s
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
#define maxN 100005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int Left[maxN], Right[maxN];
bool dead[maxN];
int s,b;
void Read_Input(){
    while ( scanf("%d %d",&s,&b) && (s + b)){
        for (int i=0;i<=s+1;i++) {
            Left[i] = i - 1;
            Right[i] = i + 1;
            dead[i] = false;
        }
        int y,z;
        int new_left, new_right;
        for (int i=1;i<=b;i++) {
            scanf("%d %d",&y,&z);
            for (int k=y;k<=z;k++)
                dead[k] = true;
            new_left = y;
            new_right = z;
            while (dead[new_left]) new_left = Left[ new_left ];
            while (dead[new_right]) new_right = Right[ new_right ];
            for (int k=y;k<=z;k++) {
                Left[k] = new_left;
                Right[k] = new_right;
            }
                if (new_left > 0 && new_right<=s) printf("%d %d\n",new_left,new_right);
            else
                if (new_left > 0) printf("%d *\n",new_left);
            else
                if (new_right<=s) printf("* %d\n",new_right);
            else puts("* *");
        }
        puts("-");
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

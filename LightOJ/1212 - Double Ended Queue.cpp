/***********************************************
* Author - LUONG VAN DO                        *
* 1212 - Double Ended Queue ->AC
* Algorithm Adhoc
* Time Limit 0.002s
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
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,m;
char s[1001];
int Left[15], size_left;
int Right[15], size_right;
void PushLeft(int x){
    if (size_left + size_right == n) {
        printf("The queue is full\n");
        return;
    }
    Left[++size_left] = x;
    printf("Pushed in left: %d\n",x);
}
void PushRight(int x){
    if (size_left + size_right == n) {
        printf("The queue is full\n");
        return;
    }
    Right[++size_right] = x;
    printf("Pushed in right: %d\n",x);
}
void PopLeft(){
    if (size_left + size_right == 0) {
        printf("The queue is empty\n");
        return;
    }
    if (size_left != 0)
        printf("Popped from left: %d\n",Left[size_left--]);
    else {
        printf("Popped from left: %d\n",Right[1]);
        for (int i=1;i<size_right;i++)
            Right[i] = Right[i+1];
        size_right--;
    }
}
void PopRight(){
    if (size_left + size_right == 0) {
        printf("The queue is empty\n");
        return;
    }
    if ( size_right!=0 )
        printf("Popped from right: %d\n",Right[size_right--]);
    else {
        printf("Popped from right: %d\n",Left[1]);
        for (int i=1;i<size_left;i++)
            Left[i] = Left[i+1];
        size_left--;
    }
}
void Read() {
    int test,l,D;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d ",&n,&m);
        printf("Case %d:\n",t);
        size_left = size_right = 0;
        for (int i=1;i<=m;i++) {
            scanf("%s",s);
                if ( strcmp(s, "pushLeft") == 0) {
                    scanf("%d ",&D);
                    PushLeft( D );
                }
            else
                if ( strcmp(s, "pushRight") == 0) {
                    scanf("%d ",&D);
                    PushRight( D );
                }
            else
                if ( strcmp(s, "popLeft") == 0) PopLeft();
            else
                if ( strcmp(s, "popRight") == 0) PopRight();
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

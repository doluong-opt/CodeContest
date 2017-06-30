/***********************************************
* Author - LUONG VAN DO                        *
* 514 - Rails ->AC
* Algorithm Stack
* Time Limit 0.084s
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
int n;
void Read_Input(){
    int val, found;
    while ( scanf("%d",&n) && n) {
        
        while ( true ) {
            scanf("%d",&val);
            if (!val) {
                puts("");
                break;
            }
            stack <int> x,y;
            x.push(val);
            for (int i=2;i<=n;i++) {
                scanf("%d",&val);
                x.push(val);
            }
            found = 1;
            for (int i=n;i>=1 && found; i--) {
                if (!y.empty() && i==y.top()) {
                    y.pop();
                    continue;
                }
                while ( true ) {
                    if ( !x.empty() && i!=x.top() ){
                        val = x.top();
                        y.push(val);
                        x.pop();
                        found = 0;
                    }
                    else
                    if ( !x.empty() && i==x.top() ) {
                        x.pop();
                        found = 1;
                        break;
                    }
                    else {
                        found = 0;
                        break;
                    }
                }
            }
            if (found) puts("Yes");
            else puts("No");
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

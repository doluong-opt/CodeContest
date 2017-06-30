/***********************************************
* Author - LUONG VAN DO                        *
* 1048 - Conquering Keokradong ->AC
* Algorithm Greedy
* Time Limit 0.066s
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
#define INF 2000000000
#define maxN 1005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, k, total;
int a[maxN];
bool check(int X){
    int Y = X, j = 0;
    FOR(i, 1, n) {
        int dif = a[i];
        if ( Y >= dif ) Y-=dif;
        else {
            j++;
            Y = X - dif;
        }
        if ( j > k || Y < 0 ) return false;
    }
    return true;
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
      scanf("%d %d",&n,&k);
        ++n; total = 0;
        FOR(i, 1, n) {
            scanf("%d",&a[i]);
            total += a[i];
        }
        int Left = 0, Right = total;
        int ans = INF;        
        while (Left<=Right) {
            int mid = (Left + Right) / 2;
            if ( check(mid) ) ans = min(ans , mid), Right = mid - 1;
            else Left = mid + 1;
        }
        printf("Case %d: %d\n",t,ans);
        int num = 0, h = 0;
        queue <int> q;
        for (int i=1;i<=n;i++) {
            if ( n-i>=k-h && num + a[i]<=ans)
                num+=a[i];
            else {
                q.push(num);
                num = a[i];
                h++;
            }
        }
        q.push( num );
        while ( !q.empty() ) {
            printf("%d\n",q.front());
            q.pop();
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

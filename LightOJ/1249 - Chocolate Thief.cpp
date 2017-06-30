/***********************************************
* Author - LUONG VAN DO                        *
* 1249 - Chocolate Thief ->AC
* Algorithm Adhoc
* Time Limit 0.207s
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
#define N 1000005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, x[N], y[N], z[N], total;
int pos1, pos2;
string name, idx[N];
int main(){
    //freopen("exam.inp","r", stdin);
    //freopen("exam.out","w", stdout);
    int cases, caseno = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        total = 0;
        for (int i = 1;i <= n;i++) {
            cin >> name >> x[i] >> y[i] >> z[i];
            idx[i] = name;
            total += x[i] * y[i] * z[i];
        }
        printf("Case %d: ", ++caseno);
        //cout<<total<<" "<<n<<endl;
        //if ( total % n == 0 ) puts("no thief");
        //else {
            //cout<<"ds"<<endl;
            pos1 = pos2 = -1;
            int avg = total / n;
            for (int i = 1;i <= n;i++)
                if (x[i] * y[i] * z[i] > avg) pos1 = i;
            else 
                if (x[i] * y[i] * z[i] < avg) pos2 = i;
            if (pos1 != -1 && pos2 != -1) cout <<idx[pos1]<< " took chocolate from " <<idx[pos2]<<endl;
            else puts("no thief");
        //}       
    }
    return 0;
}

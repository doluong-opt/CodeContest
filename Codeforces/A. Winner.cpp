/***********************************************
* Author - LUONG VAN DO                        *
* A. Winner ->AC
* Algorithm Adhoc
* Time Limit 60ms
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
using namespace std;
int n;
string name[maxN];
int sc[maxN];
map <string, int> idx, idd;
map <string, int> :: iterator it;
void Read_Input(){
    int ans = -INF;
    string Name;
    scanf("%d",&n);
    Rep(i,n) {
        cin >> name[i] >> sc[i];
        idx[name[i]]+=sc[i];
    }
}
void Solve(){
    int Min = -INF;
    string Name;
    for (it=idx.begin();it!=idx.end();it++)
        Min = max(Min, it->second);
    Rep(i,n) {
        idd[name[i]]+=sc[i];
        if (idx[name[i]]==Min && idd[name[i]]>=Min) {
            Name = name[i];
            break;
        }
    }
    cout<< Name << endl;
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}

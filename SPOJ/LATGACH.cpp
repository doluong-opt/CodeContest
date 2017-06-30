/***********************************************
* Author - LUONG VAN DO                        *
* LATGACH ->AC
* Algorithm Adhoc
* Time Limit 0.01s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define maxN 101
using namespace std;
string f[maxN];
string Add(string x, string y){
    string c = "";
    int nho=0,sum;
    while (x.length()<y.length()) x='0'+x;
    while (y.length()<x.length()) y='0'+y;
        for (int i=x.length()-1;i>=0;i--){
            sum = (x[i] - '0') + (y[i] - '0') + nho;
            nho = sum / 10;
            c = char(sum % 10 + 48) + c;
        }
        if (nho > 0) c = '1'+c;
    return c;
}
void Init(){
    f[1] = "1"; f[2] = "2";
    For(i,3,100) f[i] = Add(f[i-1],f[i-2]);
}
void Read_Input(){
    Init();
    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        cout << f[n] <<endl;
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}

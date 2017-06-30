/***********************************************
* Author - LUONG VAN DO                        *
* A. Train and Peter ->AC
* Algorithm Adhoc
* Time Limit 90ms
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
string out[] = {"fantasy","forward","backward","both"};
string a,b,s;
void Read_Input(){
    int ind = 0,x,y;
    cin >> s >> a >> b;
    x = s.find(a);
    y = s.find(b, x + a.size());
    if (x!=-1 && y!=-1) ind++;
    reverse(s.begin(), s.end());
    x = s.find(a);
    y = s.find(b, x + a.size());
    if (x!=-1 && y!=-1) ind+=2;
    cout << out[ind] <<endl;
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

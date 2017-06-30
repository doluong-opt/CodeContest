/***********************************************
* Author - LUONG VAN DO                        *
* B. Lucky Substring ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
char s[55];
int l;
map <string, int> H;
map <string, int>::iterator it;
string ss, rs;
bool check(int x, int y){
    ss = "";
    if (s[x]=='0') return false;
    for (int i=x;i<=y;i++) {
        if (s[i]!='4' && s[i]!='7') return false;
        ss+=s[i];
    }
    return true;
}
void Read_Input(){
    gets(s);
    l = strlen(s);
    ss = rs = "";
    H.clear();
    for (int i=0;i<l;i++)
        for (int j=i;j<l;j++)
            if ( check(i,j) )
                H[ss]++;
    int pos = 0;
    for (it=H.begin();it!=H.end();it++) {
        int ind = it->second;
        if (ind > pos) {
            pos = ind;
            rs = it->first;
        }
    }
    for (it=H.begin();it!=H.end();it++) {
        string tmp = it->first;
        if (it->second == pos && tmp < rs) rs = tmp;
    }
    if (H.size()) cout << rs << endl;
    else puts("-1");
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

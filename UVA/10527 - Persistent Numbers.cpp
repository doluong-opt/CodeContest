/***********************************************
* Author - LUONG VAN DO                        *
* 10527 - Persistent Numbers ->AC
* Algorithm Adhoc
* Time Limit 0.456s
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
vector <int> num;
string s;
int check(string x, int cs){
    int hold = 0;
    for (int i=0;i<x.length();i++)
        hold = (hold * 10 + x[i] - '0') % cs;
    return hold;
}
string Div(string x, int cs){
    int hold;
    string c = "";
    hold = 0;
    for (int i=0;i<x.length();i++) {
        hold = hold * 10 + (x[i] - '0');
        c = c + char((int)(hold / cs) + 48);
        hold = hold % cs;
    }
    while (c[0]=='0' && c.length() > 1) c.replace(0,1,"");
    return c;
}
void Solve(string s){
    int found;
    num.clear();
    if (s.length() == 1 ) {
        printf("1");
        cout<<s<<endl;
        return;
    }
    while ( s!="1" ) {
        found = 0;
        for (int i=9;i>=2;i--){
            if ( !check(s,i) ) {
                s = Div(s,i);
                found = 1;
                num.pb( i );
                break;
            }
        }
        if (!found) break;
    }
    if (!found) puts("There is no such number.");
    else {
        for (int i=num.size()-1;i>=0;i--)
            cout<<num[i];
            cout<<endl;
    }
}
void Read_Input(){
    int n;
    while ( true ) {
        cin >> s;
        if (s=="-1") break;
        Solve( s );
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

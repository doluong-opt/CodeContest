/***********************************************
* Author - LUONG VAN DO                        *
* COMMAND ->AC
* Algorithm Adhoc
* Time Limit 0.03s
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
#define maxN 50001
using namespace std;
string S;
int x,y,d;
void Dh(char ch){
    if ( ch=='L' ){
        if (d==0) d = 3;
        else
        if (d==1) d = 0;
        else
        if (d==2) d = 1;
        else d = 2;
        return;
    }
    if ( ch=='R' ){
        if (d==0) d = 1;
        else
        if (d==1) d = 2;
        else
        if (d==2) d = 3;
        else d = 0;
        return;
    }
}
void Solve(string S){
    int len = S.length();
    int ok = 1,Count = 0;
    Rep(i,len)
        if ( S[i] == 'S' ){
            Count++;
            ok = 0;
        }
        if ( ok ){
            puts("bounded");
            return;
        }
        if ( Count == len){
            puts("unbounded");
            return;
        }
        x = y = d = 0;
    Rep(i,len){
        switch (S[i]){
            case 'L':{
                Dh( 'L' );
                break;
            }
            case 'R':{
                Dh( 'R' );
                break;
            }
            case 'S':{
                if ( d == 0 ) y++;
                else
                if ( d == 1 ) x++;
                else
                if ( d == 2 ) y--;
                else x--;
            }
        }
    }
        if (x==0 && y==0 && d==0){
            puts("bounded");
            return;
        }
        else puts("unbounded");
}
void Read_Input(){
    char s[1001];
    while ( gets(s) ){
        if ( strcmp(s,"[END]")==0) break;
            S = "";
            gets( s );
        while ( gets(s) ){
            if (strcmp(s,">>")==0) break;
            S+=s;
        }
        string Tmp = S;
        Rep(i,3) S+=Tmp;
        Solve( S );
        gets( s );
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve( S );
    //Write_Output();
}

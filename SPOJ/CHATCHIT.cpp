/***********************************************
* Author - LUONG VAN DO                        *
* CHATCHIT ->AC
* Algorithm Adhoc
* Time Limit 0.00s
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
#define maxN 301
using namespace std;
string x;
void Read_Input(){
    getline(cin,x);
}
string Scan1(string q){
        if (q == "k") return "khong";
        else
        if (q == "ko") return "khong";
        else
        if (q == "ng") return "nguoi";
        else
        if (q == "n") return "nhieu";
        else
        if (q == "dc") return "duoc";
        else
        if (q == "hok") return "khong";
        else
        if (q == "ntn") return "nhu the nao";
        else
        if (q == "kq") return "ket qua";
        else return "a";
}
string Scan2(string q){
        if (q == "j" ) return "gi";
        else
        if (q == "w") return "qu";
        else
        if (q == "f") return "ph";
        else
        if (q == "z") return "d";
        else return "a";
}
void Solve(){
    int i = 0,vt;
    string tmp = "",Add;
    while ( i < x.length() )
    {
        while ( i < x.length() && x[i]==' ') ++i;
        vt = i;
        while ( i < x.length() && x[i]!=' ')
        {
            tmp+=x[i];
            ++i;
        }        
        Add = Scan1(tmp);
        tmp = "";
        if ( Add!="a" )
        {
            x.replace(vt,i-vt,Add);
            i = 0;
        }
    }
    i = 0; tmp = "";
    while ( i < x.length() - 1 )
    {
        tmp+=x[i];
        tmp+=x[i+1];
        if ( tmp == "dz" )
        {
            x.replace(i,2,"d");
            i = 0;
        }
        else ++i;
        tmp = "";
    }
    i = 0;
    while ( i < x.length() )
    {
        tmp = x[i];
        Add = Scan2( tmp );
        if ( Add!="a" )
        {
            x.replace(i,1,Add);
            i = 0;
        }
        else i++;
    }
    cout << x <<endl;
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}

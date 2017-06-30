/***********************************************
* Author - LUONG VAN DO                        *
* A. Word ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
char s[maxN];
int l,c1,c2;
void Read_Input(){
    gets(s);
    l = strlen(s);
    c1 = c2 = 0;
    Rep(i,l) {
        if (s[i]>='a' && s[i]<='z') c1++;
        if (s[i]>='A' && s[i]<='Z') c2++;
    }
}
void Solve(){
    if (c1 >= c2) {
        Rep(i,l) {
            s[i] = tolower(s[i]);
            printf("%c",s[i]);
        }
    }
    else 
        Rep(i,l) {
            s[i] = toupper(s[i]);
            printf("%c",s[i]);
        }
    printf("\n");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}

/***********************************************
* Author - LUONG VAN DO                        *
* SUBSTR ->AC
* Algorithm KMP
* Time Limit 0.7s
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
#define maxN 1000001
using namespace std;
char A[maxN], B[maxN];
int Next[maxN];
int n,m;
void Read_Input(){
    gets(A);
    gets(B);
    n = strlen(A);
    m = strlen(B);
}
void PreKMP(){
    int i = 0;
    int j = Next[0] = -1;
    while (i < m) {
        while (j > -1 && B[i]!=B[j] ) j = Next[j];
        
        ++i; ++j;
        if ( B[i] == B[j] )
            Next[i] = Next[j];
        else
            Next[i] = j;
    }
}
void Solve(){
    PreKMP();
    int i,j,blank;
    i = j = blank = 0;
    while ( j < n)
    {
        while ( i > -1 && B[i]!=A[j] ) i = Next[i];
        
        ++i; ++j;
        if ( i>=m )
        {
            if (blank) printf(" ");
            blank = 1;
            printf("%d",j - i + 1);
            i = Next[i];
        }
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

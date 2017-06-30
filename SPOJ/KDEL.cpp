/***********************************************
* Author - LUONG VAN DO                        *
* KDEL ->AC
* Algorithm Sieve + Stack                               
* Time Limit 0.64s                            
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
#define maxN 650001
using namespace std;
bool color[maxN];
vector <int> prime;
string Ch;
int n,k,Top;
int S[1000000];
void Sieve(){
    memset(color, true, sizeof(color)); color[0] = color[1] = false;
    for (int i=4;i<maxN;i+=2) color[i] = false;
    for (int i=3;i*i<maxN;i+=2)
        if (color[i])
            for (int j=i*i;j<maxN;j+=2*i) color[j] = false;
    prime.pb( 2 );
    for (int i=3;i<maxN;i+=2)
        if (color[i]) prime.pb( i );
}
int Pop(){
    Top--;
}
int Push(int value){
    Top++;
    S[Top] = value;
}
void Solve(string ch){
    int i,l;
    i = 1;
    Top = 0;
    Push( ch[0] - '0' );
    l = ch.length();
    while ( i < l )
    {
        int v = ch[i] - '0';
        while (Top && S[Top] < v && k)
        {
            Pop();
            --k;
        }
        Push( v );
        ++i;
    }
    while ( k )
    {
        Pop();
        --k;
    }    
}
void Read_Input(){
    char tmp[10];
    scanf("%d %d",&n,&k);
    Rep(i,n)
    {
        sprintf(tmp,"%d",prime[i]);
        Ch+=tmp;
    }  
}
void Write_Output(){
    For(i,1,Top) printf("%d",S[i]);
    printf("\n");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Sieve();
    Read_Input();
    Solve( Ch );
    Write_Output();
}

/***********************************************
* Author - LUONG VAN DO                        *
* 462 - Bridge Hand Evaluator ->AC
* Algorithm Adhoc
* Time Limit 0.088s
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
char s[500];
int suit[5], ace[5], king[5], queen[5], jack[5];
char ss[6] = "SHDC";
int cal(char c){
    for (int i=0;i<4;i++)
        if (ss[i] == c) return i;
}
void Read_Input(){
    char temp[5];
    int i, score, stoped, len;
    while ( gets(s) ){
        len = strlen( s );
        i = score = stoped = 0;
        for (int k=0;k<4;k++) {
            suit[k] = 0;
            ace[k] = king[k] = queen[k] = jack[k] = 0;
        }
        while ( i < len ) {
            while (i < len && s[i]==' ') ++i;
            sscanf(s+i,"%s",temp);
            if (temp[0]=='A') score+=4;
            else
            if (temp[0]=='K') score+=3;
            else
            if (temp[0]=='Q') score+=2;
            else
            if (temp[0]=='J') score++;
            int pos = cal(temp[1]);
            suit[pos]++;
            ace[pos]+=( temp[0] == 'A');
            king[pos]+=( temp[0] == 'K');
            queen[pos]+=( temp[0] == 'Q');
            jack[pos]+=( temp[0] == 'J');
            while (i < len && s[i]!=' ') ++i;
        }
        
        for (int i=0;i<4;i++) {
            if (king[i] && suit[i] < 2) score--;
            if (queen[i] && suit[i] < 3) score--;
            if (jack[i] && suit[i] < 4) score--;
            if (ace[i] || (king[i] && suit[i]>=2) || (queen[i] && suit[i]>=3) ) stoped++;
        }
        if (score>=16 && stoped==4) puts("BID NO-TRUMP");
        else {
            int Max,j;
            Max = j = -1;
            for (int i=0;i<4;i++) {
                if (suit[i]==2) score++;
                if (suit[i] < 2) score+=2;
                if (suit[i] > Max) {
                    Max = suit[i];
                    j = i;
                }
            }
            if (score < 14) puts("PASS");
            else printf("BID %c\n",ss[j]);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

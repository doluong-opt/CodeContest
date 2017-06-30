/***********************************************
* Author - LUONG VAN DO                        *
* 466 - Mirror, Mirror ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[11][31];
char r1[11][31];
char r2[11][31];
int r, c;
bool check() {
    REP(i, r)
        REP(j, c)
            if (s[i][j]!=s[i][j+r+1]) return false;
    return true;
}
void Cal1(char rr[][31], char ss[][31]) {
    REP(i, r)
        REP(j, c)
            rr[j][c-i-1] = ss[i][j];
}
void Cal2(char rr[][31], char ss[][31]) {
    REP(i, r)
        REP(j, c)
            rr[i][j] = ss[r-i-1][j];
}
bool ok(char rr[][31], char s[][31]) {
    REP(i, r)
        REP(j, c)
            if (rr[i][j]!=s[i][j+r+1]) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int Case = 0;
    while ( scanf(" %d ",&r) !=EOF ) {
        REP(i, r) gets(s[i]);
        c = r;
        if ( check() ) {
            printf("Pattern %d was preserved.\n",++Case);
            continue;
        }
        Cal1(r1, s);
        Cal2(r2, s);
        /*REP(i, r) {
            REP(j, c)
                printf("%c",r1[i][j]);
                cout<<endl;
        }
        cout<<endl;*/
            if ( ok(r1, s) ) printf("Pattern %d was rotated 90 degrees.\n",++Case);
        else {
            REP(i, r)
                REP(j, c) s[i][j] = r1[i][j];
            Cal1(r1, s);
            if ( ok(r1, s) ) printf("Pattern %d was rotated 180 degrees.\n",++Case);
            else {
                REP(i, r)
                    REP(j, c) s[i][j] = r1[i][j];
                Cal1(r1, s);
                if ( ok(r1, s) ) printf("Pattern %d was rotated 270 degrees.\n",++Case);
                else
                    if ( ok(r2, s) ) printf("Pattern %d was reflected vertically.\n",++Case);
                else {
                    REP(i, r)
                        REP(j, c) s[i][j] = r2[i][j];
                    Cal1(r2, s);
                    if ( ok(r2, s) ) printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",++Case);
                    else {
                        REP(i, r)
                            REP(j, c) s[i][j] = r2[i][j];
                        Cal1(r2, s);
                        if ( ok(r2, s) ) printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",++Case);
                        else {
                            REP(i, r)
                                REP(j, c) s[i][j] = r2[i][j];
                            Cal1(r2, s);
                            if ( ok(r2, s) ) printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",++Case);
                            else printf("Pattern %d was improperly transformed.\n",++Case);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

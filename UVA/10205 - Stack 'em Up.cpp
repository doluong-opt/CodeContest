/***********************************************
* Author - LUONG VAN DO                        *
* 10205 - Stack 'em Up ->AC
* Algorithm Adhoc
* Time Limit 0.016s
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
#define maxN 105

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
string suit[] = {"Clubs","Diamonds","Hearts","Spades"};
string value[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
map <int, string> cards;
int shuffles[maxN][55];
int nm;
void reset() {
    nm = 1;
    REP(i, 4)
        REP(j, 13)
            cards[nm++] = value[j] + " of " + suit[i];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    reset();
    bool blank = false;
    int test, n;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n)
            FOR(j, 1, 52)
                scanf("%d",&shuffles[i][j]);
        getchar();
        
        int deck[maxN];
        FOR(i, 1, 52) deck[i] = i;
        
        char input[maxN];
        int k;
        while ( gets(input) && strlen(input)) {
            int Next[maxN];
            sscanf(input,"%d",&k);
            
            FOR(i, 1, 52)
                Next[i] = deck[ shuffles[k][i] ];
            
            FOR(i, 1, 52)
                deck[i] = Next[i];
        }
        if (blank) puts("");
        blank = true;
        FOR(i, 1, 52)
            cout << cards[deck[i]] <<endl;
    }
    return 0;
}

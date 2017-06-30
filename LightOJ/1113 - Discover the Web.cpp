/***********************************************
* Author - LUONG VAN DO                        *
* 1113 - Discover the Web ->AC
* Algorithm Adhoc
* Time Limit 0.003s
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
#define maxN 1001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[maxN];
string S[maxN];
string temp;
int top, id;
void Push(string x){
    if ( id!=top ) {
        S[++id] = x;
        top = id;
    }
    else {
        S[++top] = x;
        id++;
    }
}
string Pop_Backward(){
    return S[--id];
}
string Pop_Forward() {
    return S[++id];
}
void Read() {
    int test,l,i;
    scanf("%d ",&test);
    for (int t=1;t<=test;t++) {
        top = id = 0;
        Push("http://www.lightoj.com/");
        printf("Case %d:\n",t);
        while (gets(s) && strcmp(s,"QUIT")) {
            l = strlen(s); i = 0;
            if (s[0] == 'V') {
                temp = "";
                while (i < l && s[i]!=' ') ++i;
                ++i;
                for (int j=i;j<l;j++) temp+=s[j];
                cout << temp <<endl;
                Push( temp );
            }
            else
            if (s[0] == 'B') {
                if (id == 1) printf("Ignored\n");
                else cout << Pop_Backward() <<endl;
            }
            else
            if (s[0] == 'F') {
                if (id == top) printf("Ignored\n");
                else cout << Pop_Forward() <<endl;
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}

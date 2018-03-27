/***********************************************
* Author - LUONG VAN DO                        *
* 1067 - Combinations ->AC
* Algorithm math
* Time Limit 0.126s
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
#define INF 1000003
#define LIMIT 111
using namespace std;
int n;
char s[LIMIT];
bool inValid(char s[]) {
    for (int i = 1;i < strlen(s);i++)
        if (s[i - 1] != '?' && s[i] != '?' && s[i] == s[i - 1]) return true;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf(" %d ", &n);
    gets(s);
    if (inValid(s)) puts("No");
    else {
        bool noWay = true;
        int ways = 0;
        for (int i = 0;i < n;i++)
            if (s[i] == '?') 
            {
                ways = 0;
                s[i] = 'C';
                if (!inValid(s)) ways++;
                s[i] = 'M';
                if (!inValid(s)) ways++;
                s[i] = 'Y';
                if (!inValid(s)) ways++;
                s[i] = '?';
                //printf("%s => %d\n",s, ways);
                if (ways == 1) continue;
                if (ways == 0) {
                    noWay = true;
                    break;
                }
                if (ways == 2 || ways == 3) {
                    noWay = false;
                    break;
                }

            }
        if (noWay) puts("No");
        else puts("Yes");
    }
    return 0;
}

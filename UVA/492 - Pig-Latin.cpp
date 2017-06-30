/***********************************************
* Author - LUONG VAN DO                        *
* Problem 492 - Pig-Latin ->AC
* Algorithm Adhoc
* Time Limit 0.112s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define M 5000000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string ch, s;
    int n, ind;
    while ( getline(cin, s) ) {
        n = s.length(); ind = 0;
        while (ind < n) {
            while (ind < n && s[ind] == ' ') {
                printf(" ");
                ++ind;
            }
            ch = "";
            while (ind < n && isalpha(s[ind])) {
                ch+=s[ind];
                ++ind;
            }
            if (ch[0] == 'a' || ch[0] == 'e' || ch[0] == 'u' || ch[0] == 'i' || ch[0] == 'o') cout<<ch<<"ay";
            else
            if (ch[0] == 'A' || ch[0] == 'E' || ch[0] == 'U' || ch[0] == 'I' || ch[0] == 'O') cout<<ch<<"ay";
            else
            if (ch.length() > 0){
                FOR(i, 1, ch.length()-1) cout<<ch[i];
                cout<<ch[0];
                cout<<"ay";
            }
            while (ind < n && !isalpha(s[ind])) {
                cout<<s[ind];
                ind++;
            }
        }
        puts("");
    }
}

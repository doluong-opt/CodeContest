/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11062 - Andy's Second Dictionary ->AC
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
#define M 100000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
map <string, bool> es;
vector <string> words;
string isLower(string s){
    REP(i, s.length())
        if (isalpha(s[i])) s[i] = tolower(s[i]);
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string s, ch;
    ch = "";
    int n, ind;
    while ( getline(cin, s) ) {
        n = s.length(); ind = 0;
        if (n == 0) continue;
        while (ind < n) {
            while (ind < n && s[ind] == ' ') ++ind;
            while (ind < n && isalpha(s[ind])) {
                ch+=s[ind];
                ++ind;
            }
            if (ind < n && !isalpha(s[ind]) && s[ind]!='-') {
                ch = isLower(ch);
                if (ch.size() > 0 && !es[ch]) {
                    es[ch] = true;
                    words.pb(ch);
                }
                ch = "";
            }
            while (ind < n && s[ind]!='-' && !isalpha(s[ind])) ++ind;
            if (ind + 1 == n && s[ind] == '-') ++ind;
            else
            if (ind < n && s[ind]=='-') {
                ch+="-";
                ++ind;
            }
            else {
                ch = isLower(ch);
                if (ch.size() > 0 && !es[ch]) {
                    es[ch] = true;
                    words.pb(ch);
                }
                ch = "";
            }
        }
    }
    sort(words.begin(), words.end());
    REP(i, words.size()) cout<<words[i]<<endl;
}

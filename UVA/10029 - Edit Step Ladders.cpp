/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 25100

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Node {
    Node* next[26];
    int f;
};
int dp[N], n, m, ans, pos, best;
char s[17];
Node* root;
string buff, str;
Node* newNode() {
    Node* node = new Node();
    rep(i, 26) node->next[i] = NULL;
    node->f = -1;
    return node;
}
void insertTrie(string str, int n, int id) {
    Node* p = root;
    rep(i, n) {
        int c = str[i] - 'a';
        if (p->next[c] == NULL) p->next[c] = newNode();
        p = p->next[c];
    }
    p->f = id;
}
int findTrie(string str) {
    Node* p = root;
    for (int i = 0;i < str.size();i++) {
        int c = str[i] - 'a';
        if (p->next[c] == NULL) return -1;
        p = p->next[c];
    }
    return p->f;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	root = newNode();
	fill(dp, 0); ans = m = 0;
	while ( gets(s) ) {
	    n = strlen(s);
	    buff = s; pos = 0; best = 0;
	    for (int i = 0;i < n;i++)
	        for (char j = 'a';j <= 'z';j++) {
	            str = buff.substr(0, i) + j + buff.substr(i);
                pos = findTrie(str);
                if (pos >= 0) best = max(best, dp[pos]);
                if (str.compare(buff) > 0) break;
	        }
        for (int i = 0;i < n;i++) {
            str = buff.substr(0, i) + buff.substr(i + 1);
            pos = findTrie(str);
            if (pos >= 0) best = max(best, dp[pos]);
        }
        for (int i = 0;i < n;i++)
            for (char j = 'a';j <= 'z';j++) {
                str = buff.substr(0, i) + j + buff.substr(i + 1);                
                pos = findTrie(str);
                if (pos >= 0) best = max(best, dp[pos]);
                if (str.compare(buff) > 0) break;
            }        
        dp[m] = best + 1;
        ans = max(ans, dp[m]);
        insertTrie(buff, n, m);
        m++;
	}
	printf("%d\n", ans);
	return 0;
}

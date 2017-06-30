/***********************************************
* Author - Group ???                           *
* Problem - Scheduling Fast Food Problem
* Algorithm - Greedy....
* Time Limit - 60 seconds.
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 111
#define M 111
#define LMT 1000
#define MAX_LOG 20
#define eps 1e-15
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, double> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int s, m, n, bestTime;
int quantity[M], q[M], p[M], a[M];
int amount[N][M], finishTime[M];
double r[M], remainingAverageTime[M];
vector <int> excuteMachine;
/* read input */
void readInput() {
    scanf("%d %d %d",&s, &m, &n);
    for (int i = 1;i <= m;i++) quantity[i] = 0; // Số cái bánh máy i cần phục vụ
    for (int i = 1;i <= m;i++) {
        scanf("%d %d %d", &p[i], &q[i], &a[i]);
        r[i] = (q[i] * 1.0) / (p[i] * 1.0); // Công suất của máy i
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            scanf("%d", &amount[i][j]);
            quantity[j] += amount[i][j];
        }
}
/* Check xem tất cả m máy có hoàn thành công việc xong chưa */
bool finish() {
    for (int i = 1;i <= m;i++)
        if ( quantity[i] > 0 ) return false;
    return true;
}
bool cmp(ii x, ii y) {
    return x.ss > y.ss;
}
/* Xem xét xem máy nào tiếp theo có thể được khởi động */
vector <int> findNextMachine(int startTime, int server) {
    int cnt = 0;
    vector <int> listMachine(0), tmp;
    vector <ii> ranking;
    double maxTime = 0.0;
    for (int i = 1;i <= m;i++) {
        remainingAverageTime[i] = (quantity[i] * 1.0) / r[i]; // Thời gian trung bình còn lại của máy i
        if (quantity[i] <= 0) cnt++; // cnt sẽ là số máy đã hoàn thành xong công việc
    }
    if (cnt == m) return listMachine; // Nếu tất cả m máy đã hoàn thành return.
    cnt = 0;
    for (int i = 1;i <= m;i++) {
        if ( startTime < finishTime[i] ) { // Thời gian kết thúc của máy i > thời gian dự định bắt đầu.
            cnt++;
            continue;
        }
        if ( maxTime < remainingAverageTime[i] ) maxTime = remainingAverageTime[i]; // Tìm ra thời gian trung bình phải hoàn thành là lớn nhất.
    }
    if (cnt == m) return listMachine; // Nếu tất cả các máy đều đang hoạt động thì phải chờ.
    for (int i = 1;i <= m;i++) {
        if (startTime < finishTime[i] ) continue; // Thời gian kết thúc của máy i > thời gian dự định bắt đầu.
        ranking.pb(ii(i, remainingAverageTime[i]));
    }
    sort(ranking.begin(), ranking.end(), cmp);
    for (int i = 0;i < ranking.size();i++) listMachine.pb(ranking[i].ff);
    if ((int)listMachine.size() <= server) return listMachine;
    for (int i = 0;i < server;i++) tmp.pb(listMachine[i]);
    return tmp; // Trả về index của máy mà khởi động.
}/* Chương trình chính sắp xếp lịch hoạt động của M máy */
void process(int server) {
    int startTime = 1;
    vector <int> curMachine;
    while ( true ) {
        curMachine = findNextMachine(startTime, server); // Lựa chọn máy tiếp theo cần khởi động
        if ((int)curMachine.size() > 0) {
            for (int i = 0;i < curMachine.size();i++) {
                finishTime[ curMachine[i] ] = startTime + p[ curMachine[i] ];
                quantity[ curMachine[i] ] -= q[ curMachine[i] ];
                cout<<curMachine[i]<<" "<<startTime<<" "<<finishTime[curMachine[i]]<<endl;
            }
            startTime++;
        }
        else startTime++;
        if ( finish() ) break; // Kiểm tra các công việc đã hoàn thành xong hết chưa
    }
    for (int i = 1;i <= m;i++) 
        if (bestTime < finishTime[i]) bestTime = finishTime[i];
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	readInput();
	bestTime = 0;
    for (int i = 1;i <= m;i++) finishTime[i] = 0;
    process(s);
	cout << bestTime << endl;
	return 0;
}


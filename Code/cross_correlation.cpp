/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <ctime>
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
#define N 5555
#define maxN 1000111
#define MAX_LOG 20
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

int n, m;
double *x, *y;
double *z_normolization(double *x, double *res, int n) {
    double sumx = 0.0, sumxx = 0.0;
    double meanx = 0.0, stdvx = 0.0;
    for (int i = 0;i < n;i++) {
        sumx += x[i];
        sumxx += (x[i] * x[i]);
    }
    meanx = sumx / n; stdvx = sumxx / n;
    stdvx = sqrt(stdvx - meanx * meanx);
    for (int i = 0;i < n;i++)
        res[i] = (x[i] - meanx) / stdvx;
    return res;
}
void jocorCross(double *x, int n, double *y, int m) {
    double *sumx, *sumy, *sumxx, *sumyy;
    std::clock_t start = std::clock();
    x = z_normolization(x, x, n);
    y = z_normolization(y, y, m);
	
    sumx = (double*)malloc(sizeof(double)*(n + 1));
    sumy = (double*)malloc(sizeof(double)*(m + 1));
    sumxx = (double*)malloc(sizeof(double)*(n + 1));
    sumyy = (double*)malloc(sizeof(double)*(m + 1));
    sumx[0] = sumy[0] = sumxx[0] = sumyy[0] = 0.0;
    for (int i = 1;i <= n;i++) {
        sumx[i] = sumx[i - 1] + x[i - 1];
        sumxx[i] = sumxx[i - 1] + x[i - 1] * x[i - 1];        
    }
    for (int i = 1;i <= m;i++) {
        sumy[i] = sumy[i - 1] + y[i - 1];
        sumyy[i] = sumyy[i - 1] + y[i - 1] * y[i - 1];
    }
    //for (int i = 0;i < n;i++)
        //cout<<x[i]<<" "<<sumx[i + 1]<<"  "<<sumxx[i + 1]<<endl;
    //cout<<sumx[n]<<endl;
    int lag;
    double best = 0.0, sumxy;
    //y : INR, x : SGD
    // j = 0, i = 0, 1, 2, 3;
    
    for (int i = 0;i < n - 1;i++){
        sumxy = 0.0;
        for (int j = i;j < n;j++) sumxy += (x[j - i] * y[j]);
        int len = n - i;
        double cy = sumy[m] - sumy[i];
        double cyy = sumyy[m] - sumyy[i];
        double meany = cy / len;
        double sigmay = (cyy / len) - (meany * meany);
        sigmay = sqrt(sigmay);
        double cx = sumx[n - i] - sumx[0];
        double cxx = sumxx[n - i] - sumxx[0];
        double meanx = cx / len;
        double sigmax = (cxx / len) - (meanx * meanx);
        
        sigmax = sqrt(sigmax);
        double c = (sumxy - len*meanx*meany ) / ( len*sigmax*sigmay );
        //if (c > 0.83) cout<<i<<" "<<len<<" "<<c<<endl;
        //if (i == 4484 ) cout<<i<<" "<<sumxy-len*meanx*meany<<" "<<len*sigmax*sigmay<<endl;
        //if (i == 4484) cout<<sigmax<<" "<<sigmay<<endl;
        //cout<<i<<" "<<c<<endl;
            if (c > best) {
                best = c;
                lag = i;
            }
    }
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	//printf("time for ffts : %lf\n",duration);
	//cout <<lag<<" "<<best<<endl;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	n = m = 4485;
    x = (double*)malloc(sizeof(double)*(n + 1));
    y = (double*)malloc(sizeof(double)*(m + 1));
    for (int i = 0;i < n;i++) scanf("%lf",x + i);
    for (int i = 0;i < m;i++) scanf("%lf",y + i);
    
    /*double *xx, *yy;
    xx = (double*)malloc(sizeof(double)*(n + 1));
    yy = (double*)malloc(sizeof(double)*(m + 1));
    for (int i = 0;i < n;i++) {
        xx[i] = x[i];
        yy[i] = y[i];
    }*/
    
    //for (int k = 1;k <= 1900;k++) {
        jocorCross(x, n, y, m);
        /*for (int i = 0;i < n;i++) {
            xx[i] = x[i];
            yy[i] = y[i];
        }*/
    //}
	return 0;
}

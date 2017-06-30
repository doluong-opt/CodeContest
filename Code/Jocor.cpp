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
struct Complex{
    double a, b;
    Complex(){}
    Complex(double con) {
        a = con; b = 0.0;
    }
    Complex(double _a, double _b) {
        a = _a; b = _b;
    }
};
int n, m, p, nNew;
double **z;
double *x, *y;
typedef vector <Complex> vcd;
vcd p1, p2, r1, r2, r3;

Complex add(Complex number1, Complex number2) {
    number1.a += number2.a;
    number1.b += number2.b;
    return number1;
}
Complex sub(Complex number1, Complex number2) {
    number1.a -= number2.a;
    number1.b -= number2.b;
    return number1;
}
Complex mul(Complex number1, Complex number2) {
    Complex res;
    res.a = number1.a * number2.a - number1.b * number2.b;
    res.b = number1.a * number2.b + number1.b * number2.a;
    return res;
}

void fft( vector<Complex > &a, bool invert) {
	int n = (int)a.size();
	for ( int i = 1 , j = 0 ; i < n ; ++i ) {
		int bit = n >> 1 ;
		for ( ;j >= bit;bit >>= 1 )
			j -= bit ;
		j += bit ;
		if ( i < j )
			swap ( a [ i ] , a [ j ] ) ;

	}
	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		double ang = 2 * PI / len * ( invert ? -1 : 1 ) ;
		Complex wlen (cos(ang),sin (ang)) ;

		for ( int i = 0 ; i < n ; i += len ) {
			Complex w(1) ;
			for ( int j = 0 ; j < len / 2 ; ++ j ) {
				Complex u = a[i + j] ,  v = mul(a[i + j + len / 2],w);

				a [ i + j ] = add(u, v);
				a [ i + j + len / 2 ] = sub(u, v);
				w = mul(w, wlen);

			}

		}
	}
	//for (int i = 0;i < n;i++) cout<<i<<" "<<a[i].a<<" "<<a[i].b<<endl;
}
double *multiply(double *x, int n, double *y, int m, double *z) {
    vector <Complex> X, Y, Z;
    for (int i = 0;i < 2 * n;i++) {
        if (i < n) {
              X.pb(Complex(x[i], 0));
        }
        else X.pb(Complex(0, 0));
        if (i < m) {
              Y.pb(Complex(y[i], 0));
        }
    }
    reverse(Y.begin(), Y.end());
    for (int i = 0;i < 2 * n - m;i++) Y.pb(Complex(0, 0));

     //for (int i = 0;i < 2 * n;i++) cout<<i<<" "<<Y[i].a<<" "<<Y[i].b<<endl;

    fft(X, false); fft(Y, false);
    for (int i = 0;i < 2 * n;i++) Z.pb(mul(X[i], Y[i]));
    fft(Z, true);
    for (int i = 0;i < 2 * n;i++)
        z[i] = Z[i].a / (2 * n);
    return z;
}
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
void jocorFFT(double *x, int n, double *y, int m, int nNew, int k) {
    double *sumx, *sumy, *sumxx, *sumyy;
    std::clock_t start = std::clock();
    //x = z_normolization(x, x, n);
   // for (int i = 0;i < n;i++) cout<<x[i]<<endl;
    //y = z_normolization(y, y, m);
      //for (int i = 0;i < n;i++) cout<<y[i]<<endl;
    for (int i = 0;i < nNew - n;i++) x[n + i] = 0.0;
    for (int i = 0;i < nNew - m;i++) y[m + i] = 0.0;
    for (int i = 0;i <= n;i++) {
        z[i] = (double*)malloc(sizeof(double)*(2 * nNew));
        z[i] = multiply(y, nNew, x + i, nNew - i, z[i]);
    }
    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	//printf("time for ffts : %lf\n",duration);

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
    double zz = 0.0;
    for (int i = 0;i < n;i++) if (zz < fabs(x[i])) zz = fabs(x[i]);
    for (int i = 0;i < m;i++) if (zz < fabs(y[i])) zz = fabs(y[i]);
    zz = 2 * zz; //cout<<zz<<endl;
    int minLen = 100, posX, posY, bestLen;
    double best = 0.0;
    //X : SGD, Y : INR
    for (int i = 0;i < m - minLen;i++)
        for (int j = 0;j < n - minLen;j++) {
            int maxLen = min(m - i, n - j);
            int len = minLen;
            while (len < maxLen) {
                double sumxy = z[i][nNew - i + j - 1] - z[i + len][nNew - i + j - 1];

                double cx = sumx[j+len] - sumx[j];
				double cxx = sumxx[j+len] - sumxx[j];
				double meanx = cx / len;
				double sigmax = (cxx / len) - meanx * meanx;
				sigmax = sqrt(sigmax);


				double cy = sumy[i+len] - sumy[i];
				double cyy = sumyy[i+len] - sumyy[i];
				double meany = cy / len;
				double sigmay = (cyy / len) - meany * meany;
				sigmay = sqrt(sigmay);
				double c = (sumxy - len*meanx*meany ) / ( len*sigmax*sigmay );

				if (c > best) {
				    best = c;
				    posX = i;
				    posY = j;
				    bestLen = len;
				}

				double dist = (1 - c);
				double bestD = (1 - best);
				double factor = 1.0 / (  (double)(len-1)/len + (double)(len-1)*(zz*zz)/(len*len));

				int stepSize = floor(log(bestD/dist)/(log(factor)-1.0/(double)len));
				//if (factor > 0.8) cout<<factor<<" "<<stepSize<<endl;

				if ( stepSize <= 0 || stepSize >= len )
					stepSize = 0;

				len = len + stepSize + 1;
            }
        }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	//printf("time for jocor : %lf\n",duration);
	//cout << posX<<" "<<posY<<" "<<bestLen<<" "<<best<<endl;

}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d %d", &n, &m);
    int lg = log2(n + m);
    nNew = (1 << lg);
    x = (double*)malloc(sizeof(double)*(nNew + 1));
    y = (double*)malloc(sizeof(double)*(nNew + 1));
    z = (double**)malloc(sizeof(double*)*(nNew + 1));
    for (int i = 0;i < n;i++) {
          scanf("%lf",x + i);
          //xx[i] = x[i];
    }
    for (int i = 0;i < m;i++) {
          scanf("%lf",y + i);
          //yy[i] = y[i];
    }
    jocorFFT(x, n, y, m, nNew, 1);
    for (int k = 1;k <= m;k++)
            for (int i = 0;i < n - k + 1;i++)
                  for (int j = 0;j < m - k + 1;j++)
                        if (nNew - i + j - 1 >= 0)
                        cout<<i<<" "<<j<<" "<<k<<" "<<z[i][nNew - i+ j - 1] - z[i + k][nNew - i+ j - 1]<<endl;
                        //cout<<i<<" "<<j<<" "<<k<<" "<<z[i][nNew - i+ j - 1] - z[i + k][nNew - i+ j - 1]<<" "<<z[i][nNew - i + j - 1]<<" "<<z[i + k][nNew - i + j - 1]<<endl;
	return 0;
}

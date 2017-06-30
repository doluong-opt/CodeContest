/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/
#include <stdio.h>
#define N 1000001


long long sum[N], b1[N], b2[N], ways, dseq, n;
int i;

inline void input (long long *num) { 
    char c = getchar (); 
    bool ok = false;
    while (c < '0' || c > '9') {
        if (c == '-') ok = true;
        c = getchar (); 
    }
    for ((*num) = 0; c >= '0' && c <= '9'; c = getchar ()) 
        (*num) = (*num) * 10 + c - '0'; if (ok) (*num)=-(*num); 
}
inline long long Max(long long a, long long b) {
    if (a > b) return a;
    return b;
}
inline long long Min(long long a, long long b) {
    if (a > b) return b;
    return a;
}
inline long long Abs(long long x) {
    if (x < 0) x = -x;
    return x;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);	
	input(&n);
	sum[0] = ways = dseq = 0LL;
	for (i = 1;i <= n;i++) {
	    input(&sum[i]);
	    sum[i] += sum[i - 1];
	}
	for (i = n;i >= 1;i--) {
	    b1[i] = sum[n] - sum[i - 1];
	    b2[i] = sum[n] - sum[i - 1];
	}
	for (i = n - 1;i > 1;i--) {
	    b1[i] = Min(b1[i], b1[i + 1]);
	    b2[i] = Max(b2[i], b2[i + 1]);
	}
	for (i = 1;i <= n - 1;i++) {
	    dseq = Max(dseq, Abs(sum[i] - b1[i + 1]));
	    dseq = Max(dseq, Abs(sum[i] - b2[i + 1]));
	}
    for (i = 1;i <= n - 1;i++) {
        if (Abs(sum[i] - b1[i + 1]) == dseq) ways++;
        else
        if (Abs(sum[i] - b2[i + 1]) == dseq) ways++;
    }
    ways = ways * (ways + 1) / 2;
    printf("%lld %lld\n", dseq, ways);
	return 0;
}

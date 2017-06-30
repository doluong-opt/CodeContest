#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
// TROXE
int main ()
{
map <long long, int> k;
int n, kq = 0;
long long x;
scanf("%d", &n);
for (int i = 0; i < n; i++){
	scanf ("%lld", &x);
	k[x]++;
}
map<long long, int> :: iterator ab = k.begin();
//for(;it != k.end(); it++) {
//	int p = it->second;
//	if (p <= 5) {
//		kq += 100;
//
//	} else {
//		kq += 100 + (p - 5)
//	}
//	printf("%d\n", kq);
//}

}

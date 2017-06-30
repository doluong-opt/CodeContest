#include <stdio.h>
#include <string.h>
#define N 333
#define mod 15111992
char a[N],b[N];int power(long long x,int y){long long res = 1LL;while(y){if(y&1)res=((res%mod)*(x%mod))%mod;x=((x%mod)*(x%mod))%mod;y>>=1;}return res%mod;}int solve(char a[]){int n=strlen(a),i,j,res=0;for (i=0;i<n;i++){if (a[i]=='1'){int r1=1,r2=1;for(j=1;j<=n-i-1;j++){r1=(r1<<1)%mod+power(2,j);r1%=mod;}for(j=1;j<=n-i-2;j++){r2=(r2<<1)%mod+power(2,j);r2%=mod;}if(n-i-1>0)res+=r1-r2;else res+=r1;if (res<0)res+=mod;else res%=mod;}}return res;}
int main() {
    scanf("%s",&a);scanf("%s",&b);
    printf("%d\n",(solve(b)-solve(a)+mod)%mod);
}

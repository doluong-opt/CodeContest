#include <bits/stdc++.h>
using namespace std;
int a[105][40005],x,y,z,m,b,c;
int main () {
     #ifndef ONLINE_JUDGE
        freopen("exam.inp","r",stdin);
        freopen("exam.out","w",stdout);
    #endif // ONLINE
    while ( true)  {
        int n=0,x;
        while (scanf("%d",&x)&&(x!=0)) {
            for (int i=0;i<=18000/x/2+1;++i) {
                for (int j=0; j<x-5;++j) a[n][2*i*x+j]=0;
                for (int j=x-5;j<x;++j) a[n][2*i*x+j]=1;
                for (int j=0;j<x;++j) a[n][(2*i+1)*x+j]=1;
            }
        ++n;
        }
    if (n==0) return 0;
    
    int d=0;
    bool ok;
    for (int t=0;t<=000;++t) {
        ok=true;
        for (int i=0;i<n;++i) {
            if (a[i][t]!=0) {
                d=1;
                ok=false;
                break;
            }
        }
        if (ok && d)  {
            printf("%02d:%02d:%02d\n",t/3600,(t%3600)/60,t%60);
            break;
        }
    }
    if  ( d==0 || ok==false ) printf("Signals fail to synchronise in 5 hours\n");
    }
                                        
    return 0; 
}

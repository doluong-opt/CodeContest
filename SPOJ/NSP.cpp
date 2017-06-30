#define AC
#include <stdio.h>
int a[1001][1001];
int n,k;
void Find(int value){
    int u,v;
    u = 1; v = n;
    while ( a[u][v]!=value )
    {
        if ( a[u][v] > value ) v--;
        else u++;
    }
    printf("%d %d\n",u,v);
}
void Read_Input(){
    int i,j;
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;i++)
        for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
    while (k--)
    {
        int value;
        scanf("%d",&value);
        Find( value );
    }
}
main(){
    Read_Input();
}

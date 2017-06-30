/***********************************************
* Author - LUONG VAN DO                        *
* MAJSTOR ->AC
* Algorithm Duyet
* Time Limit 0.02s
* *********************************************/
#include <iostream>
#include <stdio.h>
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
using namespace std;
char s[51];
char a[51][51];
int r,n;
void Read_Input(){
scanf("%d ",&r);
gets(s);
scanf("%d ",&n);
for (int i=0;i<n;i++)
gets(a[i]);
}
int Try(int u, char Ch){
int sum = 0;
for (int i=0;i<n;i++)
{
if (Ch==a[i][u]) sum++;
if (Ch=='S'&&a[i][u]=='P') sum+=2;
if (Ch=='P'&&a[i][u]=='R') sum+=2;
if (Ch=='R'&&a[i][u]=='S') sum+=2;
}
return sum;
}
void Solve(){
int rs1,rs2;
rs1=rs2=0;
for (int i=0;i<r;i++)
{
rs1+=Try(i,s[i]);
rs2+=max(Try(i,'S'),max(Try(i,'R'),Try(i,'P')));
}
printf("%d\n",rs1);
printf("%d\n",rs2);
}
main(){
#ifndef ONLINE_JUDGE
FileIn("exam"); FileOut("exam");
#endif
Read_Input();
Solve();
}

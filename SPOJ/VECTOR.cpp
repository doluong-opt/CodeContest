#include <iostream>
#include <vector>
using namespace std;
#define N 50
typedef struct Node{
int AU,BU;
};
typedef struct No{
int x,y;
};
int n,U,V,sum1,sum2,k,ans;
No A[N],B[N];
vector <Node> As,Bs;
void Try1(int i){
for (int j=0;j<=1;j++){
sum1 = sum1 + A[i].x*j;
sum2 = sum2 + A[i].y*j;
if (i<int(k/2)) Try1(i+1);
else{
Node tmp;
tmp.AU = sum1;
tmp.BU = sum2;
As.push_back(tmp);
}
sum1 = sum1 - A[i].x*j;
sum2 = sum2 - A[i].y*j;
}
}
void Try2(int i){
for (int j=0;j<=1;j++){
sum1 = sum1 + B[i].x*j;
sum2 = sum2 + B[i].y*j;
if (i<n) Try2(i+1);
else{
Node tmp;
tmp.AU = sum1;
tmp.BU = sum2;
Bs.push_back(tmp);
}
sum1 = sum1 - B[i].x*j;
sum2 = sum2 - B[i].y*j;
}
}
bool cmp(Node c, Node d){
if (c.AU<d.AU) return true;
if (c.AU>d.AU) return false;
return c.BU<d.BU;
}
void Process(){
Node key;
sort(Bs.begin()+1,Bs.end(),cmp);
for (int i=1;i<As.size();i++)
{
vector <Node>::iterator low, up;
key.AU = U-As[i].AU;
key.BU = V-As[i].BU;
low = lower_bound(Bs.begin()+1,Bs.end(),key,cmp);
up = upper_bound(Bs.begin()+1,Bs.end(),key,cmp);
if (low->AU==key.AU && low->BU==key.BU)
ans+=(up-low);
}
}
int main(){
sum1 = sum2 = ans = 0;
scanf("%d",&n);
k = n;
for (int i=1;i<=n/2;i++){
scanf("%d%d",&A[i].x,&A[i].y);
}
if (n%2==0) n = n/2; else n = (n/2)+1;
for (int i=1;i<=n;i++){
scanf("%d%d",&B[i].x,&B[i].y);
}
scanf("%d%d",&U,&V);
if (k>1) Try1(1);
sum1 = sum2 = 0;
Try2(1);
//for (int i=1;i<As.size();i++)
//2cout<<As[i].AU<<" "<<As[i].BU<<endl;
if ( U==V && V==0 ) ans++;
for (int i=1;i<As.size();i++)
if (As[i].AU==U && As[i].BU==V) ans++;
for (int i=1;i<Bs.size();i++)
if (Bs[i].AU==U && Bs[i].BU==V) ans++;
Process();
printf("%d",ans);
//system("pause");
}

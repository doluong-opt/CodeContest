#include <iostream>
struct ds {
int e,r;
};
ds a[50];
int c;
int n,m,sh,vt,h;
long long kq,ans=0;
char s[15];
void sap(int u, int v){
int i=u;
int j=v;
int tam=a[(i+j)/2].e;
while (i<=j){
while (a[i].e<tam) i++;
while (a[j].e>tam) j--;
if (i<=j) {
ds t=a[i];
a[i]=a[j];
a[j]=t;
i++;
j--;
}
}
if (i<v) sap(i,v);
if (u<j) sap(u,j);
}
void sap1(int u, int v){
int i=u;
int j=v;
int tam=a[(i+j)/2].r;
while (i<=j){
while (a[i].r<tam) i++;
while (a[j].r>tam) j--;
if (i<=j) {
int t=a[i].r;
a[i].r=a[j].r;
a[j].r=t;
i++;
j--;
}
}
if (i<v) sap1(i,v);
if (u<j) sap1(u,j);
}
using namespace std;
void timhang(){
if (h==0) sh=0;
else {
sh=1;
for (int i=1;i<h;i++){
if (a[i].e!=a[i+1].e) sh++;
}
}
}
int tim(int k){
while (a[k].e==a[k+1].e) k++;
return k;
}
void tinh(int ghe, int vt1, int vt2){
if (vt1==1 && ghe-2>0) ans+=(ghe-2);
else
if (vt2==vt && m-ghe-1>0) { ans+=(m-ghe-1);
if (ghe-a[vt2-1].r-2>0)
ans+=(ghe-a[vt2-1].r-2);
}
else
if (ghe-a[vt2-1].r-2>0) ans+=(ghe-a[vt2-1].r-2);
}
void xuli()
{
unsigned long long ma;
int dem,i;
ma=n-sh;
ans=(m-1)*ma;
if (sh==0) {
cout<<ans<<endl;
return;
}
for (i=1;i<=h;i++){
vt=tim(i);
if (i==vt) {
if (a[i].r-2>0) ans+=a[i].r-2;
if (m-a[i].r-1>0) ans+=m-a[i].r-1;
}
else
{
dem=0;
for (int j=i;j<=vt;j++){
dem++;
sap1(j,vt);
tinh(a[j].r,dem,j);
i=(vt+1);
i--;
}
}
}
cout<<ans<<endl;
}
bool Enter()
{
memset(a,0,sizeof(a));
h=0;
gets(s);
if (s[1]=='E') return false;
cin >> n >> m; gets(s);
gets(s);
while (gets(s)) {
if (s[0]=='>') break;
h++;
sscanf(s, "%d", &a[h].e);
}
h=0;
gets(s);
while (gets(s)) {
if (s[0]=='>') break;
h++;
sscanf(s, "%d", &a[h].r);
}
gets(s);
return true;
}
int main()
{
 freopen("exam.inp","r",stdin);
 freopen("exam.out","w",stdout);
while (Enter()) {
sap(1,h);
timhang();
xuli();
}
} 

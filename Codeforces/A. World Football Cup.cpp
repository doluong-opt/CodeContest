/***********************************************
* Author - LUONG VAN DO                        *
* A. World Football Cup ->AC
* Algorithm Adhoc
* Time Limit 30ms
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, f, s;
    string n_team;
    node(){}
    node(int xx, int ff, int ss, string nn_team){
        x = xx; n_team = nn_team;
        f = ff; s = ss;
    }
};
map <string, int> team;
string NAME[55];
node score[55];
int l,n,m;
char s[105];
bool cmp(node c, node d){
    if (c.x!=d.x) return c.x > d.x;
    if (c.f!=d.f) return c.f > d.f;
    if (c.s!=d.s) return c.s > d.s;
    return c.n_team < d.n_team;
}
void Read_Input(){
    string team1,team2,name;
    int d1,d2;
    scanf("%d",&n);
    For(i,1,n) {
        cin >> name;
        team[name] = i;
        score[i].n_team = name;
    }
    m = (n * (n - 1)) / 2;
    gets(s);
    For(i,1,m) {
        gets(s);
        l = strlen(s);
        int j = 0;
        team1 = team2 = "";
        while (j < l && s[j]!='-') {
            team1+=s[j];
            ++j;
        }
        ++j;
        while (j < l && s[j]!=' ') {
            team2+=s[j];
            ++j;
        }
        ++j;
        sscanf(s+j,"%d:%d",&d1,&d2);
        int i1,i2;
        i1 = team[team1]; i2 = team[team2];
            if (d1 > d2) score[i1].x = score[i1].x + 3;
        else
            if (d1 < d2) score[i2].x = score[i2].x + 3;
        else
            if ( d1 == d2 ) {
                score[i1].x++;
                score[i2].x++;
            }
        score[i1].f+=(d1 - d2);
        score[i2].f+=(d2 - d1);
        score[i1].s+=d1;
        score[i2].s+=d2;
    }
    sort(score+1,score+n+1,cmp);
    //For(i,1,n) cout<< score[i].x<<" "<<score[i].n_team<<endl;
    int nm = 0;
    For(i,1,n/2) NAME[++nm] = score[i].n_team;
    sort(NAME+1,NAME+nm+1);
    For(i,1,nm) cout<<NAME[i]<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

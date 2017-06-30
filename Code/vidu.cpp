#include <bits/stdc++.h>
using namespace std;
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
const int N = 1e5+10;
int n, q, chain[N], chainhead[N], pos[N], lastpos[N], nchain, inbase, child[N];
int depth[N], parent[N], fr[N], it[6*N], lazy[6*N], res;
vector <int> a[N];
inline void dfs(int u, int p, int h){
    depth[u] = h; child[u] = 1;
    for(int i = 0;i < a[u].size();i++) {
        int v = a[u][i];
        if(v!=p){
        parent[v] = u;
        dfs(v,u,h+1);
        child[u] += child[v];
        }
    }
}
inline void HLD(int u){
    if(chainhead[nchain]==0) chainhead[nchain] = u;
    chain[u] = nchain;
    pos[u] = ++inbase;
    fr[u] = 1;
    int db = -1;
    for (int i = 0;i < a[u].size();i++) {
        int v = a[u][i];
        if(fr[v]==0 && (db==-1 || child[v] > child[db])) db = v;
    }
    if(db != -1) HLD(db);
    for (int i = 0;i < a[u].size();i++) {
        int v = a[u][i];
        if(v!=db && fr[v]==0){
            nchain++;
            HLD(v);
        }
    }
    lastpos[u] = inbase;
}
inline void updateIT(int k, int l, int r, int u, int v, int val){
    if(lazy[k]>=0){
        it[k] = lazy[k];
        lazy[2*k] = lazy[2*k+1] = lazy[k];  lazy[k] = -1;
    }
    if(v<l || r<u) return;
    if(u<=l && r <=v){
        it[k] = val;    lazy[k] = -1; lazy[2*k] = lazy[2*k+1] = val;
        return;
    }
    int mid = (l+r)/2;
    updateIT(2*k,l,mid,u,v,val);
    updateIT(2*k+1,mid+1,r,u,v,val);
}
inline void queryIT(int k, int l, int r, int vt){
    if(lazy[k]>=0){
        it[k] = lazy[k];
        lazy[2*k] = lazy[2*k+1] = lazy[k];  lazy[k] = -1;
    }
    if(vt<l || r<vt) return;
    if(l==r && r==vt){
        res = it[k]; return;
    }
    int mid = (l+r)/2;
    queryIT(2*k,l,mid,vt);
    queryIT(2*k+1,mid+1,r,vt);
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
    cin >>n;
    int x, y;
    for(int i=1; i<n; i++){
        cin >>x >>y;
        x++; y++;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    parent[1] = -1;
    dfs(1,-1,1);
    nchain = 1; inbase = 0;
    HLD(1);
    //for (int i = 1;i <= n;i++) 
        //cout<<pos[i]<<" "<<lastpos[i]<<endl;
    for(int i=1; i<=6*n; i++) lazy[i] = -1;
    cin >>q;
    while(q--){
        cin >>x >>y;
        y++;
        if(x==1) {
            //cout<<pos[y]<<" "<<lastpos[y]<<endl;
            updateIT(1,1,n,pos[y],lastpos[y],1);
        }
        if(x==2) {
            while(y!=-1){
                //cout<<pos[chainhead[chain[y]]]<<" "<<pos[y]<<endl;
                updateIT(1,1,n,pos[chainhead[chain[y]]],pos[y],0);
                y = parent[chainhead[chain[y]]];
            }
        }
        if(x==3) {
            //cout<<pos[y]<<endl;
            queryIT(1,1,n,pos[y]);
            cout <<res <<"\n";
        }
    }
    return 0;
}
    
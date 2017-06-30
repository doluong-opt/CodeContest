// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1112223334
#define N 100010

struct point {
    int x, y;
    point(){}
    point(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator == (const point &p) {
        return (x == p.x && y == p.y);
    }
};

struct region{ 
    int x0, y0;
    int x1, y1;
    region(){}
    region(int _x0, int _y0, int _x1, int _y1) {
        x0 = _x0;
        y0 = _y0;
        x1 = _x1;
        y1 = _y1;
    }
};

struct kdTree{
    point p;
    kdTree *left, *right;
};


kdTree* root;
vector <point> po;
int n, m, len, id, ans;
char buff[N];

void readLine() {
    gets(buff); len = strlen(buff); id = 0;
}
int nextInt() {
    int v = 0;
    while (id < len && buff[id] != ' ') v = v * 10 + buff[id++]  - '0';
    id++;
    return v;
}

kdTree *newNode(const point &A) {
    kdTree *Node = new kdTree();
    Node ->p = A;
    Node ->left = NULL;
    Node ->right = NULL;
    return Node;
}


bool cmpx(point a, point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(point a, point b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

kdTree *buildKDTree(vector <point> P, int depth) {
    //cout << P.size() <<" "<<depth<<endl;
    if (P.size() == 0) return NULL;
    else if (P.size() == 1) return newNode(P[0]);
    
    int k = P.size();
    int mid = (k - 1) / 2;
    if (!depth) {
        point A = P[mid];
        vector <point> lf, rg;
        for (int i = 0;i < k;i++) {
            //cout <<i<<" "<<P[i].x <<" "<<A.x<<endl;
            if (P[i].x <= A.x) lf.pb(P[i]);
            else rg.pb(P[i]);
        }
        //cout <<lf.size()<< " "<<rg.size() << endl;
        //lf.resize(lf.size() + 1);
        //rg.resize(rg.size() + 1);
        kdTree *node = newNode(A);
        node->left = buildKDTree(lf, depth ^ 1);
        node->right = buildKDTree(rg, depth ^ 1);
        return node;
    }
    else {
        point A = P[mid];
        vector <point> lf, rg;
        for (int i = 0;i < k;i++)
            if (P[i].y <= A.y) lf.pb(P[i]);
            else rg.pb(P[i]);
        //lf.resize(lf.size() + 1);
        //rg.resize(rg.size() + 1);
        kdTree *node = newNode(A);
        node->left = buildKDTree(lf, depth ^ 1);
        node->right = buildKDTree(rg, depth ^ 1);
        return node;
    }
}


bool point_inRegion(point a, region R) {
    //cout<<a.x<<" "<<a.y<<endl;
    return (a.x >= R.x0 && a.x <= R.x1 && a.y >= R.y0 && a.y <= R.y1);
}

bool isContained(region A, region B) {
    return (A.x0 >= B.x0 && A.x1 <= B.x1 && A.y0 >= B.y0 && A.y1 <= B.y1);
}

bool intersection(region A, region B) {
    if (A.x0 > B.x1) return false;
    if (A.x1 < B.x0) return false;
    if (A.y0 > B.y1) return false;
    if (A.y1 < B.y0) return false;
    return true;
}

int cal(kdTree *r) {
    if (r == NULL) return 0;
    if (!r->left && !r->right) return 1;
    return cal(r->left) + cal(r->right);
}

void searchKdtree(kdTree *v, region R, int depth, region Rv) {
    
    //cout << depth<<" "<<Rv.x0<<" "<<Rv.y0<<" "<<Rv.x1<<" "<<Rv.y1<<" "<<ans<<endl;
    
    if (v == NULL) return;
    if (!v->left && !v->right) {
        if (point_inRegion(v->p, R)) ans++;
        return;
    }
    region tmpleft = Rv;
    if (!depth) tmpleft.x1 = v->p.x;
    else tmpleft.y1 = v->p.y;
    
    if (isContained(tmpleft, R)) ans += cal(v->left);
    else if (intersection(tmpleft, R)) searchKdtree(v->left, R, depth ^ 1, tmpleft);
    
    region tmpright = Rv;
    if (!depth) tmpright.x0 = v->p.x;
    else tmpright.y0 = v->p.y;
    
    if (isContained(tmpright, R)) ans += cal(v->right);
    else if (intersection(tmpright, R)) searchKdtree(v->right, R, depth ^ 1, tmpright);
}

void query(kdTree *v, region R) {
    if (v == NULL) return;
    region tmp;
    tmp.x0 = -INF;
    tmp.y0 = -INF;
    tmp.x1 = INF;
    tmp.y1 = INF;
    searchKdtree(v, R, 0, tmp);
}

/*kdTree* buildkdTreeMain(vector <point> P) {
    if (P.size() == 0) return NULL;
    else if (P.size() == 1) return newNode(P[0]);
    return buildKDTree(P, 0);
}*/


void deleteKdtree(kdTree* v, int depth) {
    if (!depth) {
        if (v->left != NULL) deleteKdtree(v->left, depth ^ 1);
        if (v->right != NULL) deleteKdtree(v->right, depth ^ 1);
    }
    else {
        if (v->left != NULL) deleteKdtree(v->left, depth ^ 1);
        if (v->right != NULL) deleteKdtree(v->right, depth ^ 1);
    }
    delete (v);
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int x1, y1, x2, y2, x, y;
    readLine();
    cases = nextInt();
    //scanf("%d", &cases);
    while (cases--) {
        readLine();
        n = nextInt(); m = nextInt();
        //scanf("%d %d", &n, &m);
        po.clear();
        rep(i, n) {
            //scanf("%d %d", &x, &y);
            readLine();
            x = nextInt(); y = nextInt();
            po.pb(point(x, y));
        }
        //for (int i = 0;i < po.size();i++) cout<<po[i].x<<" "<<po[i].y<<endl;
        sort(po.begin(), po.end(), cmpx);
        root = buildKDTree(po, 0);
        //cout << root->p.x <<" "<<root->p.y<<endl;
        printf("Case %d:\n", ++caseno);
        rep(i, m) {
            region R;
            //scanf("%d %d %d %d", &R.x0, &R.y0, &R.x1, &R.y1);
//            cout << R.x0<<" "<<R.y0<<" "<<R.x1<<" "<<R.y1<<endl;
            readLine();
            R.x0 = nextInt();
            R.y0 = nextInt();
            R.x1 = nextInt();
            R.y1 = nextInt();
            ans = 0;
            kdTree *r = root;
            query(r, R);
            printf("%d\n",ans);
        }
        deleteKdtree(root, 0);
    }
}

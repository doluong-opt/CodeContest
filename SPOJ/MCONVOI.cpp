#include <algorithm>
#include <cstdio>
#include <vector>

#define MOD 1000000007

const int inf = 1000000000;

using namespace std;

struct point { 
   int x, y; 
   point( int X, int Y ) { x=X; y=Y; }
};
bool operator < ( const point &A, const point &B ) {
   if( A.x != B.x ) return A.x < B.x;
   return A.y > B.y;
}

typedef pair<point, int> par;

vector< vector<par> > L;
vector< int > suma;

void dodaj( int kamo, point P, int br_nacina ) {
   suma[kamo] = (suma[kamo] + br_nacina) % MOD;
   L[kamo].push_back( par( P, (L[kamo].back().second + br_nacina) % MOD ) );
}

int main() {
    freopen("exam.inp", "r", stdin);
    freopen("exam.out", "w", stdout);
   int n;
   scanf( "%d", &n );

   vector< point > P;
   for( int i = 0; i < n; ++i ) {
      int x, y;
      scanf( "%d%d", &x, &y );
      P.push_back( point(x,y) );
   }
   
   sort( P.begin(), P.end() );
   for (int i = 0;i < n;i++) printf("%d %d\n", P[i].x, P[i].y);
   
   
   L.resize(n+1);
   suma.resize(n+1);
   for( int i = 0; i <= n; ++i )
      L[i].push_back( par( point(-inf, inf), 0 ) );

   dodaj( 0, point(-inf, -inf), 1 );

   int best = 0;
   for( vector<point>::iterator it = P.begin(); it != P.end(); ++it ) {
      int lo = 0, hi = n;
      while( lo < hi ) {
         int mid = (lo+hi+1)/2;
         if( L[mid].back().first.y >= it->y ) hi = mid-1; else lo = mid;
      }
      int A = lo;
      
      lo = 0, hi = L[A].size() - 1;
      while( lo < hi ) {
         int mid = (lo+hi+1)/2;
         if( L[A][mid].first.y < it->y ) hi = mid-1; else lo = mid;
      }
      int B = lo;
        
    
      printf("%d %d\n", A, B);
      dodaj( A+1, *it, (suma[A] - L[A][B].second) % MOD );
      best >?= A+1;
   }

   printf( "%d\n", best );
   printf( "%d\n", (L[best].back().second + MOD) % MOD );

   return 0;
}

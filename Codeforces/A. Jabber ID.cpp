/***********************************************
* Author - LUONG VAN DO                        *
* A. Jabber ID ->AC
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
    bool isWord(string s){
      if (s.size() < 1 || s.size() > 16)
        return (false);
      for (int i=0;i<s.size();i++)
        if (s[i] != '_' &&
            (s[i] < '0' || s[i] > '9') &&
            (s[i] < 'a' || s[i] > 'z') &&
            (s[i] < 'A' || s[i] > 'Z'))
          return(false);
      return(true);
    }

    bool good(string s){
      int pointer=0;
      if (s[0] == '.' || s[s.size()-1] == '.')
        return(false);
      while (pointer < s.size()){
        string res="";
        while (pointer < s.size() && s[pointer] != '.'){
          res+=s[pointer];
          pointer++;
        }
        pointer++;
        if (!isWord(res))
          return(false);
      }
      return(true);    
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string st;
    getline(cin,st);
    bool ok = false;
      for (int i=1;i<=16 && i+1 <= st.size();i++) if (st[i] == '@' && isWord(st.substr(0,i)))
        for (int j=1;j<=32 && i+1+j <= st.size() ;j++) if (good(st.substr(i+1,j))) {
          if (i+1+j == st.size())
            ok=true;
          else
            if (st[i+1+j] == '/' && i+j+2 < st.size() &&  isWord(st.substr(i+2+j)))
              ok=true;
        }
      if (ok)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    return 0;
}

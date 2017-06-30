/***********************************************
* Author - LUONG VAN DO                        *
* 12364 - In Braille ->AC
* Algorithm Adhoc
* Time Limit 0.036s
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
#define maxN 105
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[5];
char a[15][5] = {".*","*.","*.","**","**","*.","**","**","*.",".*"};
char b[15][5] = {"**","..","*.","..",".*",".*","*.","**","**","*."};
char c[15][5] = {"..","..","..","..","..","..","..","..","..",".."};
int x[maxN], n;
char s1[1500];
char s2[1500];
char s3[1500];
char ch[maxN];
string chuoi[1500][1000];
void Read_Input(){
    while (scanf("%d ",&n) && n){
        int cnt = 0;
        gets(s); string temp = "";
        if (s[0]=='S') {
            gets(ch);
            for (int i=0;i<strlen(ch);i++)
                x[i] = ch[i] - '0';
            for (int i=0;i<strlen(ch);i++) {
                if (i > 0) printf(" ");
                printf("%s",a[ x[i] ]);
            }
            puts("");
            for (int i=0;i<strlen(ch);i++) {
                if (i > 0) printf(" ");
                printf("%s",b[ x[i] ]);
            }
            puts("");
            for (int i=0;i<strlen(ch);i++) {
                if (i > 0) printf(" ");
                printf("%s",c[ x[i] ]);
            }
            puts("");
        }
        else
        if (s[0]=='B') {
            gets(s1);
            gets(s2);
            gets(s3);
            int l = strlen(s1);
            int i = 0;
            while (i < l) {
                while (i < l && s1[i] == ' ') ++i;
                cnt++;
                while (i < l && s1[i] !=' ') {
                    temp+=s1[i];
                    ++i;
                }
                chuoi[1][cnt] = temp;
                temp = "";
            }
            i = cnt = 0;
            while (i < l) {
                while (i < l && s2[i] == ' ') ++i;
                cnt++;
                while (i < l && s2[i] !=' ') {
                    temp+=s2[i];
                    ++i;
                }
                chuoi[2][cnt] = temp;
                temp = "";
            }
            i = cnt = 0;
            while (i < l) {
                while (i < l && s3[i] == ' ') ++i;
                cnt++;
                while (i < l && s3[i] !=' ') {
                    temp+=s3[i];
                    ++i;
                }
                chuoi[3][cnt] = temp;
                temp = "";
            }
            for (int i=1;i<=cnt;i++) {
                string rs = chuoi[1][i] + chuoi[2][i] + chuoi[3][i];
                string asd = "";
                for (int j=0;j<=9;j++) {
                    asd = a[j];
                    asd+=b[j];
                    asd+=c[j];
                    if (rs==asd) {
                        printf("%d",j);
                        break;
                    }
                    asd = "";
                }
            }
            puts("");
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}

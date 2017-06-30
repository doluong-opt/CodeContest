/***********************************************
* Author - LUONG VAN DO                        *
* Palindrome ->AC
* Algorithm LPS
* Time Limit 0.031s
* *********************************************/
#include <iostream>    
#include <cstdio>
#include <algorithm>
using namespace std;
char t[1001];
char s[1001 * 2];
int Z[1001 * 2], L, R, N;
int match(int a, int b)
{
        int i = 0;
        while (a-i>=0 && b+i<N && s[a-i] == s[b+i]) i++;
        return i;
}
void longest_palindromic_substring()
    {            
        memset(s, '.', N*2+1);
        for (int i=0; i<N; ++i) s[i*2+1] = t[i];
        N = N * 2 + 1;
     
        Z[0] = 1;
        L = R = 0;
        for (int i=1; i<N; ++i)
        {
            int ii = L - (i - L);
            int n = R + 1 - i;
     
            if (i > R)
            {
                Z[i] = match(i, i);
                L = i;
                R = i + Z[i] - 1;
            }
            else if (Z[ii] == n)
            {
                Z[i] = n + match(i-n, i+n);
                L = i;
                R = i + Z[i] - 1;
            }
            else            
                Z[i] = min(Z[ii], n);
        }
     
        int n = 0, p = 0;
        for (int i=0; i<N; ++i)
            if (Z[i] > n)
                n = Z[p = i];
     
        for (int i=p-Z[p]+1; i<p+Z[p]; ++i)
            if (i & 1)
                cout << s[i];
        cout<<endl;
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);    
    gets(t);
    N = strlen(t);
    longest_palindromic_substring();
}

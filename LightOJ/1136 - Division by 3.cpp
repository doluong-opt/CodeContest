/***********************************************
* Author - LUONG VAN DO                        *
* 1042 - Binary Weight 
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    int test,ans,A,B,i,l;
    char s[101];
    scanf("%d ",&test);
    for (int t=1;t<=test;t++) {
        A = B = i = 0;
        gets(s); l = strlen(s);
        while (i < l && s[i]!=' ') A = A * 10 + s[i++] - '0';
        i++;
        while (i < l && s[i]!=' ') B = B * 10 + s[i++] - '0';
        ans = ((A - 1) % 3 == 0) ? 0 : 1;
        A = A - (A - 1) / 3 + 1;
        B = B - (B - 1) / 3 + 1;
        printf("Case %d: %d\n",t,ans + B - A);
    }
    return 0;
}

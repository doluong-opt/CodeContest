/***********************************************
* Author - LUONG VAN DO                        *
* Reverse Root ->AC
* Algorithm Ds lien ket
* Time Limit 0.437s
* *********************************************/
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct Node{
    double ans;
    Node* Next;
};
Node* head;
Node* New_Node(){
    Node* node = new Node();
    node->ans = 0.0;
    node->Next = NULL;
    return node;
}
void Read_Input() {
    double n;
    Node* cur;
    Node* last;
    int k = 0;
    while (scanf("%lf",&n)!=EOF) {
        cur = New_Node();
        cur->ans = sqrt(n);
        if (!k) cur->Next = NULL;
        else cur->Next = last;
        last = cur;
        head = cur;
        ++k;
    }
    while ( head!=NULL ) {
        printf("%.4lf\n",head->ans);
        head = head -> Next;
    }
}
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    Read_Input();
    return 0;
}

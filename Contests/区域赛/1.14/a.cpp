#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
string s[10];
int main(){
   int n;
   cin>>n;int k=0;
   while(k<n){
    k++;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
       getchar();
       int j=0;
       while(1){
        cin>>ch;
        if(ch==' ') j++;
        else if(ch=='\n') break;
        else s[i][j].append(ch);
       }
    }
     int x;cin>>x;
     for(int i=0;i<x;i++){
        string op;
        cin>>op;
        if(op=='SHIFT'){

        }
     }
   }
}

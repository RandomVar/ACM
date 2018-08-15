#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[]={'+','-','*','/'};
int main(){
  int e;
  cin>>e;
  while(e--){
        int n;
    cin>>n;
    char s[n][n];
    int t=0;
    for(int k=0;k<=n;k++){
      for(int i=k+1;i<=n;i++)
        s[i][i-k]=a[(t++)%4];
        k++;
        if(k>n) break;
      for(int i=n;i>k;i--)
        s[i][i-k]=a[(t++)%4];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
     if(i!=j) cout<<s[i][j]<<' ';
     else cout<<s[i][j]<<endl;}
     //cout<<e<<endl;
     if(e>0) cout<<endl;

}}

#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    if((a>=0&&b>=0)||(a<0&&b<0)) {
        if(a%b==0) cout<<a/b-1<<endl;
        else cout<<a/b<<endl;
  }
  else {
    //if(a%b==0)
        cout<<a/b-1<<endl;
    //else cout<<a/b<<endl;
  }
}}

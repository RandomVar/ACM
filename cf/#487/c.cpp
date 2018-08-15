#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,p,i;
   cin>>n>>p;
   string s;
   while(cin>>s){
   for(int i=0;i<n-p;i++){
      if(s[i]=='.'&&s[i+p]=='.'){
        s[i]='1';s[i+p]='0';
        break;
      }
      if(s[i]!=s[i+p]){
        if(s[i]=='.'&&s[i+p]=='1') s[i]='0';
        else if(s[i]=='.'&&s[i+p]=='0') s[i]='1';
        else if(s[i+p]=='.'&&s[i]=='0') s[i+p]='1';
        else if(s[i+p]=='.'&&s[i]=='1') s[i+p]='0';
        break;
      }

   }
   if(i==n-p) cout<<"No"<<endl;
   else{
    for(int i=0;i<n;i++){
        if(s[i]=='.') cout<<0;
        else cout<<s[i];
    }
   }}

}

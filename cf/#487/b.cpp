#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  while(cin>>n>>p){
    char s[2010];
    cin>>s;
    int flag=0;
    for(int i=0;i<n-p;i++){
        if(s[i]!='.'&&s[i+p]!='.'){
            if(s[i]!=s[i+p]){
              flag=1;break;
            }
        }
        else if(s[i]=='.'){
            if(s[i+p]=='0') s[i]='1';
            else if(s[i+p]=='1') s[i]='0';
            else {
                s[i]='0';s[i+p]='1';
            }
            flag=1;break;
        }
        else if(s[i+p]=='.'){
            if(s[i+p]=='1') s[i]='0';
            else if(s[i+p]=='0') s[i]='1';
            flag=1;break;
        }
    }
    if(flag){
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='.') cout<<"0";
            else cout<<s[i];
        }
        cout<<endl;
    }
    else cout<<"No"<<endl;
  }
  return 0;
  }


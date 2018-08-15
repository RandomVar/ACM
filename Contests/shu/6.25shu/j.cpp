#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    string s;
    cin>>s;
    int flag=1;
    char pre=s[0];
    if(n==1&&s[0]!='1') {flag=0;}
    else{
        int f=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=pre){
            pre=s[i];
            f=0;
        }
        else if(f==1&&s[i]=='0'){
          flag=0;break;
         }
         else if(s[i]=='0'&&i==(s.size()-1)){
            flag=0;break;
         }
        else if(s[i]=='0'){
            f=1;
        }
        else {
          flag=0;break;
        }
    }

    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }

}

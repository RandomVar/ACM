#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int c[30];
int main(){
  int n;
  while(cin>>n){
    int ans=0;int flag=-1;

    memset(c,0,sizeof(c));
    getchar();
    int pos=0;
    while(n--){
    //getchar();
    string s;
       getline(cin,s);

    if(flag==-1&&s[0]=='!'){
       /* pos++;
      if(pos==1){
    for(int i=2;i<s.size();i++){
       c[s[i]-'a']=1;
    }}
    else{
       for(int i=2;i<s.size();i++){
          if(c[s[i]-'a']!=1) c[s[i]-'a']=-1;
     }

    }*/
    for(int j=0;j<26;j++){
            int x=0;
        for(int i=2;i<s.size();i++)
           if(s[i]-'a'==j){
            x=1;break;
           }
        if(x&&c[j]!=-1) c[j]=1;
        else if(x==0) c[j]=-1;
    }
    }
    if(flag==-1&&s[0]=='.'){
    for(int i=2;i<s.size();i++){
       c[s[i]-'a']=-1;
    }
  }
  if(flag==-1&&s[0]=='?'){
    c[s[2]-'a']=-1;
  }
  if(flag>=0){
    if(s[0]=='?'){
        if(s[2]-'a'!=flag) ans++;
    }
    if(s[0]=='!') ans++;
  }
  if(flag==-1){
      int cnt=0;int id=-1;int c2=0;
    for(int i=0;i<26;i++){
        if(c[i]==1) {cnt++;id=i;}
        else if(c[i]==-1) c2++;
        }
    if(cnt==1) flag=id;
    else if(c2==25){
        for(int i=0;i<26;i++){
        if(c[i]==0) {id=i;break;}
        flag=id;
        }
    }
  }
   //for(int i=0;i<26;i++)
    //    cout<<c[i];
     //   cout<<endl;
  }
 // cout<<flag<<endl;
  cout<<ans<<endl;
    }
}

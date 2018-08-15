#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long maxn=2*1e9;
  string s;
int panduan(int t){
    int ans=0;int flag=0;
  for(int i=0;i<s.size();i++){

    if(!(t&(1<<i))) {
        if(flag==0&&s[i]=='0') return 0;
        flag=1;
        ans*=10;ans+=s[i]-'0';}
  }
  int x=sqrt(ans);
  if(x*x==ans) return 1;
  return 0;
}
int main(){

  while(cin>>s){
     queue<int>que;
     que.push(0);
     //vis[0]=1;
     int ans=-1;
     while(!que.empty()){
        int t=que.front();
        que.pop();
        if(panduan(t)) {ans=t;break;}
        else {
            for(int i=0;i<s.size();i++){
               if((t&(1<<i))==0) {
                int x=(t|(1<<i));
                que.push(x);
               }
            }
        }
     }
     int cnt=0;


        for(int i=0;i<s.size();i++){
            if(ans&(1<<i)) cnt++;
        }
        if(cnt==s.size()) cout<<-1<<endl;
        else cout<<cnt<<endl;

  }

}



//vector<int>vec[13];
/*void init(){
  int w=1;
  for(int i=1;i*i<maxn;i++){
    int t=i*i;
    if(t/quickmod(10,w)==0) vec[w].push_back(t);
    else vec[++w].push_back(t);
  }
}*//*
vector<int>vec;
void init(){
  for(int i=1;(ll)i*i<maxn;i++){
    ll t=i*i;
    cout<<t<<endl;
    vec.push_back(t);
  }
}*//*
char s[15];
int main(){
    init();
  while(cin>>s){
       int flag=0;
       //cout<<vec.size()<<endl;
        /*for(int j=vec.size()-1;j>=0;j--){
            ll t=vec[j];
            string x=to_string(t);
            if(x.size()>strlen(s)) continue;
           // cout<<t<<endl;
             int i=0;int k=0;
             while(i<strlen(s)&&k<x.size()){
              if(s[i]!=x[k]) i++;
              else {i++;j++;}
             }
             if(k==x.size()) {flag=k;break;}
        }
        if(flag) cout<<strlen(s)-flag<<endl;
        else cout<<-1<<endl;
    */

 /*   }
  }
  */



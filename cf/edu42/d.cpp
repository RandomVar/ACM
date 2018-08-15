#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll>p;
priority_queue<p,vector<p>,greater<p> >que;
priority_queue<p,vector<p>,greater<p> >a;
int main(){
  ll n;
  while(cin>>n){
        ll cnt=0;
    for(ll i=0;i<n;i++){
        ll t;
        cin>>t;
        que.push(p{t,i});}
        while(!que.empty()){
           p x=que.top();
           que.pop();
         //  cout<<x.first<<endl;
           if(!que.empty()&&x.first==que.top().first){
                p e=que.top();
               que.pop();
            que.push(p{e.first*2,e.second});
           }
           else{
            a.push(p{x.second,x.first});
           }
        }
      cout<<a.size()<<endl;
      cout<<a.top().second;
      a.pop();
      while(!a.empty()){
        cout<<" "<<a.top().second;
        a.pop();
      }


  }

}

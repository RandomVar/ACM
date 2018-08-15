#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<ll,vector<ll>,greater<ll>>que;
int main(){
  int n;
  while(cin>>n){
    while(que.size())
        que.pop();
    for(int i=0;i<n;i++){
      ll t;cin>>t;
      que.push(t);
      }
      ll ans=0;
    while(que.size()){
        ll x=que.top();
        que.pop();
        if(que.size()){
        ll y=que.top();
        que.pop();
       // cout<<x<<" "<<y<<endl;
        ll z=x+y;
        ans+=z;
        if(que.size())
         que.push(z);}
        else ans+=x;
    }
    cout<<ans<<endl;
  }
}

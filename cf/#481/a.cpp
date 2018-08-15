#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
  int n;
  while(cin>>n){
    map<int,int>mp;
   priority_queue<int,vector<int>,greater<int> >que;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        mp[a[i]]=i;
    }
    map<int,int>::iterator it;
   for(it=mp.begin();it!=mp.end();it++)
      que.push(it->second);
   cout<<que.size()<<endl;
  while(que.size()>1){
    int t=que.top();
    cout<<a[t]<<" ";
    que.pop();
  }
  if(!que.empty()) cout<<a[que.top()]<<endl;
}

}

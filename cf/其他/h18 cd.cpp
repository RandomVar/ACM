#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll INF=110000000000;
struct node{
  int c;int w;double b;
}nodes[40];
ll cost[40];
int cmp(node a,node b){
return a.b>b.b;
}
int main(){
  int n,l;
  while(cin>>n>>l){
        memset(cost,0,sizeof(cost));
    for(int i=0;i<n;i++){
        cin>>nodes[i].c;
        if(i!=0) nodes[i].w=nodes[i-1].w*2;
        else nodes[i].w=1;
        nodes[i].b=(double)nodes[i].w/nodes[i].c;
  }

  //for(int i=0;i<n;i++) cout<<nodes[i].w<<endl;
     sort(nodes,nodes+n,cmp);
     for(int i=0;i<n;i++) cout<<nodes[i].w<<endl;
     int lx=l;int k=0;
     while(1){
     int flag=0;
     if(k==n) break;
     if(lx==0) break;
     if(k&&!flag) cost[k]=cost[k-1]-nodes[k-1].c;
     cout<<cost[k]<<endl;
     int t;
     if(lx%nodes[k].w==0) t=lx/nodes[k].w;
     else t=lx/nodes[k].w+1;
     if(t==0) t=1;
    cost[k]+=nodes[k].c*t;
    if(cost[k]<0) {flag=1;cost[k]=INF;}
    if(!flag) lx=lx-t*nodes[k].w+nodes[k].w;

     k++;
  }
  ll ans=INF;
  for(int i=0;i<k-1;i++){
    cout<<cost[i]<<endl;
    ans=min(ans,cost[i]);}
  cout<<ans<<endl;
  }}


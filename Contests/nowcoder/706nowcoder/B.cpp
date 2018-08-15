#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=2e5+100;
int n,m;
vector<int>edge[maxn];
int x[maxn],y[maxn];
int d[maxn];
int vis[maxn];
int top(int mid){
    mem(d,0);
    mem(vis,0);
   // if(mid==0) return 0;
    for(int i=0;i<=n;i++)
        edge[i].clear();
    if(mid>=1)
         edge[x[1]].pb(y[1]),d[y[1]]++;
  for(int i=2;i<=mid;i++){
     edge[(x[i]+1)%n+1].pb((y[i]+1)%n+1);
     d[(y[i]+1)%n+1]++;
  }
  queue<int>que;
  for(int i=1;i<=n;i++){
     if(d[i]==0) que.push(i);
  }

  while(!que.empty()){
     int t=que.front();
     que.pop();
     vis[t]=1;
     for(int i=0;i<edge[t].size();i++){
         int c=edge[t][i];
        d[c]--;
        if(d[c]==0) que.push(c);
     }

  }
  for(int i=1;i<=n;i++)
    if(!vis[i])
     return 1;
 return 0;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //int n,m;
  while(cin>>n>>m){
     for(int i=1;i<=m;i++){
         int u,v;
         cin>>u>>v;
         x[i]=u;y[i]=v;
     }
      int l=0;int r=m;
      int cnt=0;
      while(l<=r){
        int mid=(l+r)/2;
        int ans=top(mid);
        if(ans==1) cnt=mid,r=mid-1;
        else l=mid+1;
       // cout<<ans<<" "<<l<<" "<<r<<" "<<mid<<endl;
      }
     // cout<<l<<endl;
     // if(top(l)==0) l++;
      for(int i=1;i<=cnt;i++)
        cout<<1<<endl;
      for(int i=cnt+1;i<=m;i++)
      cout<<0<<endl;
  }


  }


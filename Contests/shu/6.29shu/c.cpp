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
const int maxn=500;
int edge[maxn][maxn];
int vis[maxn];
int n;
int bfs1(){
    mem(vis,0);
  queue<int>que;
  que.push(1);
  vis[1]=1;
 // cnt[1]=1;
  while(!que.empty()){
      int t=que.front();
      que.pop();
      if(t==n) return vis[t];
      for(int i=1;i<=n;i++)
      if(edge[t][i]&&!vis[i]){
          vis[i]=vis[t]+1;
        //  cnt[vis[i]]++;
         que.push(i);
      }
  }
  return -1;
}
int bfs2(){
    mem(vis,0);
  queue<int>que;
  que.push(1);
  vis[1]=1;
  while (!que.empty()){
      int t=que.front();
      que.pop();
      if(t==n) return vis[t];
      for(int i=1;i<=n;i++)
      if(edge[t][i]==0&&!vis[i]){
          vis[i]=vis[t]+1;
        //  cnt[vis[i]]++;
         que.push(i);
      }


  }
return -1;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   while(cin>>n>>m){
     mem(edge,0);
     for(int i=1;i<=m;i++){
         int u,v;
         cin>>u>>v;
        edge[u][v]=edge[v][u]=1;

     }
     int x=bfs1();int y=bfs2();
     if(x==-1||y==-1) cout<<-1<<endl;
     else cout<<max(x,y)-1<<endl;

   }


}

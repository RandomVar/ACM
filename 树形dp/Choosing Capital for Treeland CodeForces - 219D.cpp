#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=200010;
int dp[maxn][2];
struct node{
 int next,val;
};
vector<node>edge[maxn];
void dfs1(int u,int pre){
  dp[u][0]=0;
  for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i].next;
    if(v==pre) continue;
    dfs1(v,u);
    dp[u][0]+=dp[v][0]+edge[u][i].val;
  }
}
void dfs2(int u,int pre,int c){
 if(u==pre) dp[u][1]=dp[u][0];
 else {
    if(edge[pre][c].val==1)//u->pre
        dp[u][1]=dp[pre][1]-1;
    else dp[u][1]=dp[pre][1]+1;
 }
 for(int i=0;i<edge[u].size();i++){
    int v=edge[u][i].next;
    if(v==pre) continue;
    dfs2(v,u,i);
 }
}

int main(){
  int n;
  while(cin>>n){
   for(int i=0;i<maxn;i++)
      edge[i].clear();
    for(int i=1;i<n;i++){
        int s,t;
        cin>>s>>t;
        edge[s].push_back((node){t,0});
        edge[t].push_back((node){s,1});
    }
    memset(dp,0,sizeof(dp));
    dfs1(1,1);
    dfs2(1,1,0);
    int ans=INF;
    for(int i=1;i<=n;i++)
        ans=min(ans,dp[i][1]);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(ans==dp[i][1]) cout<<i<<" ";
    cout<<endl;
  }
}

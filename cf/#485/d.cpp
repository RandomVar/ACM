#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct node{
  int x;int st;

};
int a[maxn];
vector<int>edge[maxn];
vector<int>vec[110];
int vis[maxn];
int d[maxn][110];
int ans[maxn];
queue<node>que;
int main(){
  int n,m,s,k;
  while(cin>>n>>m>>k>>s){
        for(int i=0;i<110;i++)
        vec[i].clear();
     for(int i=1;i<=n;i++){
        cin>>a[i];
        vec[a[i]].push_back(i);
     }
     for(int i=0;i<maxn;i++)
        edge[i].clear();
     for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
         edge[u].push_back(v);
         edge[v].push_back(u);
     }
     memset(d,0x3f,sizeof(d));
    for(int i=1;i<=k;i++){
            memset(vis,0,sizeof(vis));
            while(!que.empty())
                que.pop();
        for(int j=0;j<vec[i].size();j++){
           que.push(node{vec[i][j],0});
            vis[vec[i][j]]=1;
            d[vec[i][j]][i]=0;
        }
        while(!que.empty()){
            node e=que.front();
            que.pop();
            for(int j=0;j<edge[e.x].size();j++)
            {
                int t=edge[e.x][j];
              if(!vis[t]){
                que.push(node{t,e.st+1});
                vis[t]=1;
                d[t][i]=e.st+1;
              }
            }

        }
    }
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
            sort(d[i]+1,d[i]+k+1);
        for(int j=1;j<=s;j++){
            ans[i]+=d[i][j];
        }
    }
  for(int i=1;i<n;i++)
  cout<<ans[i]<<" ";
cout<<ans[n]<<endl;
  }


}

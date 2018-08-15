#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int maxn=100010;
const int INF=0x3f3f3f3f;
struct node{
  int y;ll val;
};
vector<node>edge[maxn];
typedef pair<ll,int>p;
priority_queue< p,vector<p>,greater<p> >que;
ll ans[maxn];
int vis[maxn];

//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
   int t;
   cin>>t;
   while(t--){
      int n,m;
      cin>>n>>m;
      mem(vis);
      mem(ans);
      for(int i=0;i<=n;i++)
        edge[i].clear();
      for(int i=1;i<=m;i++){
        int x,y;ll z;
        cin>>x>>y>>z;
        edge[x].push_back(node{y,z});
        edge[y].push_back(node{x,z});
      }
      for(int i=1;i<=n;i++){

        for(int j=0;j<edge[i].size();j++){
             ans[i]+=edge[i][j].val;
        }
         que.push(p{ans[i],i});
      }
      ll daan=0;
      while(!que.empty()){
        p x=que.top();
        que.pop();
        //cout<<x.fir<<endl;
        if(vis[x.sec]) continue;
        vis[x.sec]=1;
        daan=max(daan,x.fir);
        for(int i=0;i<edge[x.sec].size();i++){
                node t=edge[x.sec][i];
            if(!vis[t.y]){
                ans[t.y]-=t.val;
                que.push(p{ans[t.y],t.y});
        }
      }}
  cout<<daan<<endl;
   }
return 0;
}

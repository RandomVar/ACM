#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=3*1e5+100;
int ans[maxn][30];
int vis[maxn];
int de[maxn];
vector<int>edge[maxn];
string s;
void dfs(int u){
   vis[u]=1;
   for(int i=0;i<edge[u].size();i++){
      int e=edge[u][i];
      //if(e==pre) continue;
       if(vis[e]){
        for(int j=0;j<26;j++){
            ans[u][j]=max(ans[u][j],ans[e][j]);
        }
       }
       else{
           dfs(e);
        for(int j=0;j<26;j++){

            ans[u][j]=max(ans[u][j],ans[e][j]);
        }
       }
   }
   ans[u][s[u]-'a']+=1;
}
int n;
bool top(){
    queue<int>que;
  for(int i=0;i<n;i++)
    if(de[i]==0) que.push(i);
  while(!que.empty()){
     int t=que.front();
     que.pop();
     for(int i=0;i<edge[t].size();i++)
     {
       int e=edge[t][i];
       if(de[e])
       {
           de[e]--;
          if(de[e]==0) que.push(e);
       }
  }
}
 for(int i=0;i<n;i++)
    if(de[i]) return 0;
return 1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   while(cin>>n>>m){
     for(int i=0;i<=n;i++)
        edge[i].clear();
        memset(de,0,sizeof(de));
     cin>>s;
     memset(vis,0,sizeof(vis));
     for(int i=0;i<m;i++)
     {

         int u,v;
         cin>>u>>v;
         edge[u-1].pb(v-1);
        // edge[v-1].pb(u-1);
         de[v-1]++;//de[v-1]++;
     }
     for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i);
   }
   int cnt=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<26;j++)
       cnt=max(cnt,ans[i][j]);
   }
  // cout<<cnt<<endl;
   if(top()==0) cout<<-1<<endl;
   else cout<<cnt<<endl;
}

return 0;
}

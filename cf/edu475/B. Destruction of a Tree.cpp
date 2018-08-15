#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
vector<int>vec[maxn];
vector<int>ans;
stack<int>st;
int pa[maxn];
int deg[maxn];
int vis[maxn];
void dfs(int u,int pre){
 // st[u]=tot;
 pa[u]=pre;
 st.push(u);
  for(int i=0;i<vec[u].size();i++){
    //tot++;
    int t=vec[u][i];
    if(t==pre) continue;
    dfs(t,u);
  }
  //ed[u]=tot;
}
void dfs2(int u){
    vis[u]=1;
    ans.push_back(u);
  for(int i=0;i<vec[u].size();i++){
    int t=vec[u][i];
    deg[t]--;
    if(t==pa[u]||vis[t]) continue;
    if(deg[t]%2==0) dfs2(t);
  }
}

int main(){
  int n;
  while(cin>>n){
        for(int i=0;i<=n;i++)
          vec[i].clear();
       ans.clear();
       while(!st.empty())
         st.pop();
  memset(deg,0,sizeof(deg));
  memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
      if(t)  {
        vec[i].push_back(t);
        vec[t].push_back(i);
        deg[t]++;
        deg[i]++;}
    }
    //tot=0;
    dfs(1,-1);
    while(!st.empty()){
        int t=st.top();
        st.pop();
        if(deg[t]%2==0){
            dfs2(t);
            }
    }
   if(ans.size()==n){
    cout<<"YES"<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
   }
   else cout<<"NO"<<endl;
  }
  return 0;

}

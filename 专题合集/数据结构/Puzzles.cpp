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
const int maxn=1e5+100;
double ans[maxn];
double cnt[maxn];
int sn[maxn];
vector<int>edge[maxn];
int n;
void dfs(int u){
 for(int i=0;i<edge[u].size();i++){
     int t=edge[u][i];
     dfs(t);
     sn[u]+=sn[t]+1;
 }
 for(int i=0;i<edge[u].size();i++){

     int t=edge[u][i];
     ans[u]+=(sn[t]+1)*(n-sn[u]+1);
    // cout<<u<<" "<<ans[u]<<endl;
 }
}
void dfs2(int u){
  for(int i=0;i<edge[u].size();i++){
      int t=edge[u][i];
      cnt[t]=ans[u]/sn[u];
      dfs2(t);
  }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //int n;
  while(cin>>n){
        for(int i=0;i<=n;i++)
        edge[i].clear();
  mem(ans,0);
  mem(sn,0);
     for(int i=2;i<=n;i++)
     {
         int p;
         cin>>p;
         edge[p].pb(i);
     }
     dfs(1);
     dfs2(2);
     for(int i=1;i<=n;i++)
        cout<<cnt[i]<<" ";
     cout<<endl;


  }


}

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
void dfs(int u){
 st[u]=++tot;
 for(int i=0;i<edge[u].size();i++){
     node e=edge[u][i];
     dfs(e.t);
 }
  ed[u]=tot;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
     for(int i=1;i<=n;i++){
         int p,d;
         cin>>p>>d;
         edge[p].push_back(node{i,d});

     }
      dfs(1);
      int q;
      cin>>q;
      for(int i=1;i=q;i++){

          cin>>q[i].x>>q[i].k;



      }

  }


}

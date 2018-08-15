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
*/const int maxn=2*1e5+100;
int st[maxn];
vector<int>edge[maxn];
int tot;
int id[maxn];
int ed[maxn];
void dfs(int u)
{
    st[u]=++tot;
    id[tot]=u;
    for(int i=0;i<edge[u].size();i++)
    {
        int t=edge[u][i];
        dfs(t);
    }
    ed[u]=tot;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,q;
   while(cin>>n>>q)
   {
       for(int i=0;i<maxn;i++)
       edge[i].clear();
       tot=0;
       for(int i=2;i<=n;i++)
         {
             int t;
             cin>>t;
             edge[t].pb(i);
         }
         dfs(1);
         for(int i=1;i<=q;i++)
         {
             int u,k;
             cin>>u>>k;
             int x=st[u]+k-1;
             if(x>ed[u]) cout<<-1<<endl;
             else cout<<id[x]<<endl;
         }
   }


 return 0;
  }


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
ll c[20];
vector<int>edge[20];
int n;
/*
ll dfs(int x,ll c)
{
    ll ans=0;
    ans|=(1<<x);
  for(int i=0;i<edge[x].size();i++)
  {
      int t=edge[x][i];
      if(((1<<t)&c)) continue;
      ans|=(1<<t);
      ans|=dfs(t,(c|(1<<x)));
  }
   return ans;
}
*/
ll dfs(int x,ll c)
{
   ll ans=(1LL<<x);
   for(int i=0;i<edge[x].size();i++)
   {
     int t=edge[x][i];
     if(((1LL<<t)&c)==0) continue;
     ans|=(1LL<<t);
     ans|=dfs(t,(c|(1LL<<x)));

   }
return ans;
}

ll solve(ll vis)
{
    if(vis<=0) return 0;
    ll cnt=INF;
    for(int i=1;i<=n;i++)
    {
        if((vis&(1LL<<i)))
        {
            ll ans=0;
       
          for(int j=0;j<edge[i].size();j++)
          {

              int x=edge[i][j];
              ll d=(vis&(~(1LL<<i)));
              d=dfs(x,d);         
             cout<<d<<endl;
              ans=max(ans,solve(d));
              //cout<<ans<<endl;
          }

          ans+=c[i];
        cnt=min(cnt,ans);
        }
    
    }
return cnt;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  // int n;
   while(cin>>n)
   {
       for(int i=0;i<=n;i++)
        edge[i].clear();
       for(int i=1;i<=n;i++)
         cin>>c[i];
       for(int i=2;i<=n;i++)
       {
           int x;
           cin>>x;
           edge[x].pb(i);
           edge[i].pb(x);
        }

        ll vis=0;
    for(int i=1;i<=n;i++)
      vis|=(1<<i);
     cout<<solve(vis)<<endl;
  
   }

 return 0;
  }


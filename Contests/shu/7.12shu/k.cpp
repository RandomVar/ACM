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
 3    freopen("data.out","w",stdout);
    #endif
*/
string s[1100];
vector<int>edge[1100];
int vis[1100];
int pre[1100];
int n;
int ans;
bool flag;
const int base=31;
const int mod=1e9+7;

map<ll,int> m;
ll b[1100];
void init(){
    b[0]=1;
  for(int i=1;i<n;i++)
  {
      b[i]=(b[i-1]*base+2)%mod;
  }
}
void dfs(int x,int p,int pos,ll sta)
{
    if(m[sta])
        return ;
    m[sta]=1;
    pre[x]=p;
    if(pos==n)
    {
        flag=true;
        ans=x;
        return ;
    }
    if(flag)
        return ;
    for(int i=0;i<edge[x].size();i++)
    {
        if(flag)
            return ;
        int t=edge[x][i];
        if(!vis[t])
        {
            vis[t]=1;
            dfs(t,x,pos+1,sta+b[t]);
            vis[t]=0;
        }
    }
}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(cin>>n)
  {  
      init();
      m.clear();
      for(int i=0;i<1095;i++)
      edge[i].clear();
      flag=false;
      for(int i=0;i<n;i++)
        {
            cin>>s[i];
           for(int j=0;j<n;j++){
               if(s[i][j]=='1')
                 edge[i].pb(j);
           }
        }
        mem(vis,0);
        vis[0]=1;
        dfs(0,-1,1,b[0]);
      /*for(int i=0;i<n;i++)
      {
          if(!vis[i]) {flag=0;break;}
      }*/
  if(!flag) 
    cout<<"impossible"<<endl;
  else {
     while(ans!=-1)
     {
         cout<<ans<<" ";
         ans=pre[ans];
     }
  cout<<endl;
  }
  }
return 0;

  }


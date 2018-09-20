#include<bits/stdc++.h>
#define ll long long
#define mkr make_pair
#define fir first
#define sec second
using namespace std;

queue<ll>q[2];
typedef pair<ll,int> P;
map<ll,int>vis[2];
map<ll,P> pre[2];
vector<ll>ans;

ll p;
ll quickmod(ll a,ll b)
{
  ll res=0;
   while(b>0)
   {
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
   }
   return res;
}

void add(ll u,ll v,int id,int op)
{
  if(vis[id][v]) return;
  vis[id][v]=1;
  q[id].push(v);
  pre[id][v]=mkr(u,op);
}

void getans(ll x,ll y,ll u)
{
  for(ll i=u;i!=x;i=pre[0][i].fir)
   ans.push_back(pre[0][i].sec);
   reverse(ans.begin(),ans.end());

  for(ll i=u;i!=y;i=pre[1][i].fir)
   ans.push_back(pre[1][i].sec);
}

void bfs(ll x,ll y)
{
   q[0].push(x);
   q[1].push(y);
   vis[0][x]=1;
   vis[1][y]=1;
   pre[0][x]=mkr(x,0);
   pre[1][y]=mkr(y,0);
  //  pre[0].push(mkr(u,0));
  //  pre[0].push(mkr(v,0));
   while(!q[0].empty()||!q[1].empty())
   {
       int n=q[0].size();
       while(n--)
       {
         ll u=q[0].front();
         q[0].pop();



         if(!vis[1].count(u))
           getans(x,y,u);

         add(u,(u+1)%p,0,1);
         add(u,(u-1+p)%p,0,2);
         add(u,quickmod(u,p-2),0,3);
       }
       int m=q[1].size();
       while(m--)
       {
         ll u=q[1].front();
         q[1].pop();

      if(!vis[0].count(u))
        getans(x,y,u);

          add(u,(u+1)%p,1,1);
          add(u,(u-1+p)%p,1,2);
          add(u,quickmod(u,p-2),1,3);
       }
   }

}
int main()
{
  ll u,v;
  while(scanf("%lld%lld%lld",&u,&v,&p)==3)
  {
      bfs(u,v);
      cout<<ans.size()<<endl;
      for(int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";
       cout<<endl;
  }
}

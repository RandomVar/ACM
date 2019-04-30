#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int>P;
const int maxn=55;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int cost[maxn][maxn];
int vis[maxn];
int d[maxn];
char s[maxn];
int cnt[maxn];
int main()
{
   int n;
  while(scanf("%d",&n)==1)
 {
    for(int i=1;i<=n;i++)
    {
       scanf("%s",&s);
       for(int j=1;j<=n;j++)
       {
         cost[i][j]=s[j-1]-'0';
         if(cost[i][j]==0) cost[i][j]=inf;
       }
    }
      // cout<<"??"<<endl;
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    priority_queue<P,vector<P>,greater<P> >que;
    que.push(make_pair(0,1));
     d[1]=0;cnt[1]=1;
    //  for(int i=2;i<=n;i++)
    //   d[i]=cost[1][i];
     while(!que.empty())
     {
       P p=que.top();
       que.pop();
       if(vis[p.second]) 
       {
         if(d[p.second]==p.first)
           cnt[p.second]++;
         continue;
       }
       vis[p.second]=1;
       
      // cout<<"pop"<<p.second<<endl;
       for(int i=1;i<=n;i++)
       {
         if(!vis[i]&&cost[p.second][i]!=inf&&d[i]>d[p.second]+cost[p.second][i]) 
        {
            d[i]=d[p.second]+cost[p.second][i];
            // vis[i]=1;
            cnt[i]=1;
            que.push(make_pair(d[i],i));
            // cout<<i<<endl;
        }
        else if(cost[p.second][i]!=inf&&d[i]==d[p.second]+cost[p.second][i])
        {
             que.push(make_pair(d[i],i));
        }
        }
     }
     ll ans=1;
     for(int i=1;i<=n;i++)
      ans=(ans*cnt[i])%mod;
   printf("%lld\n",ans);
}
}
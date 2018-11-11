#include<bits/stdc++.h>
#define mkr make_pair
using namespace std;
typedef pair<int,int> P;
const int inf=0x3f3f3f3f;
int cost[60][60];
int d[60];
int vis[60];
int pre[60];
int cnt[60];
int n;
int dij(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    cnt[s]=0;
    priority_queue<P,vector<P>,greater<P> >que;
    que.push(mkr(d[s],s));
    while(!que.empty())
    {
        P u=que.top();
        que.pop();
        if(vis[u.second]) continue;
        vis[u.second]=1;
        for(int i=1;i<=n;i++)
        {
            if(cost[u.second][i]!=inf&&d[i]>u.first+cost[u.second][i])
            {
                d[i]=u.first+cost[u.second][i];
                pre[i]=u.second;
                cnt[i]=cnt[u.second]+1;
                que.push(mkr(d[i],i));
                // cout<<d[i]<<" "<<i<<endl;
            }
            if(cost[u.second][i]!=inf&&d[i]==u.first+cost[u.second][i]&&(cnt[i]>cnt[u.second]+1||(cnt[i]==cnt[u.second]+1&&pre[i]>u.second))
            {
                 pre[i]=u.second;
                 cnt[i]=cnt[u.second]+1;
            }
        }
    }
    return d[t];
}
int s;
void prin(int x)
{
   if(x==inf)
       return;
    if(x!=s)
   cout<<"->";
   cout<<x;
   prin(pre[x]);
}
int main()
{
    int cas=0;
    while(cin>>n)
    {
        memset(pre,0x3f,sizeof(pre));
        // memset(cost,0x3f,sizeof(cost));
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            {
                int x;
                cin>>x;
               if(x==-1) x=inf;
               if(i==j) x=0;
               cost[j][i]=x;
            }
            int t;
            cin>>s>>t;
        int ans=dij(t,s);
        cout<<"Case "<<++cas<<endl;
        cout<<"The least distance from "<<s<<"->"<<t<<" is "<<ans<<endl;
        cout<<"the path is ";
        prin(s);
        cout<<endl;
    }
}
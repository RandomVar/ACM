#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int n,k;
const int maxn=1e5+100;
const int maxm=4100;
struct node{
    int to;ll cost;
    bool operator<(const node &b)const
    {
        return cost>b.cost;
    }
};
struct Node
{
    int u;int v;ll w;

};
vector<node>edge[maxm*2];
map<ll,int>mp;
Node e[maxm];
ll d[maxm*2];
void dij(int s,int t)
{
   // memset(d,0x3f,sizeof(d));

   memset(d,0x3f,(k+5)*sizeof(ll));
     d[s]=0;
     priority_queue<node>que;
     que.push(node{s,0});

     while(!que.empty())
     {
          node u=que.top();
          que.pop();
          if(u.to==t) break;
          if(u.cost>d[u.to]) continue;
          for(int i=0;i<edge[u.to].size();i++)
          {
              node v=edge[u.to][i];
              if(u.to==s&&v.to==t) continue;
              if(d[v.to]>d[u.to]+v.cost)
              {
                  d[v.to]=d[u.to]+v.cost;
                 if(d[v.to]<ans)
                    que.push(node{v.to,v.cost});
              }
          }
     }
}

void init()
{
    for(int i=1;i<=2*n+5;i++)
     edge[i].clear();

}
int main()
{
    int t;scanf("%d",&t);int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        k=0;
        init();
        mp.clear();
        int x1,y1,x2,y2,w;
        int id1,id2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&w);
            if(!mp.count(x1*maxn+y1))
                mp[x1*maxn+y1]=++k;
               id1=mp[x1*maxn+y1];

           if(!mp.count(x2*maxn+y2))
             mp[x2*maxn+y2]=++k;
             id2=mp[x2*maxn+y2];
            edge[id1].push_back(node{id2,w});
            edge[id2].push_back(node{id1,w});
            e[i]=Node{id1,id2,w};
        }

        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;i++)
        {
            dij(e[i].u,e[i].v);
            ans=min(ans,e[i].w+d[e[i].v]);
        }

        if(ans==0x3f3f3f3f3f3f3f3f)
          ans=0;
        printf("Case #%d: %lld\n",++cas,ans);
    }
}
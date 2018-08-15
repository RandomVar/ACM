#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int p[maxn];
int f[maxn];
struct node{
   ll a,b;int id;
   bool operator<(const node &t)const{
      if(a<b&&t.a>=t.b)
        return 0;
      if(a>=b&&t.a<t.b)
        return 1;
      if(a>=b&&t.a>=t.b)
          return  b<t.b;
        return a>t.a; 
   }
}s[maxn];
vector<int>edge[maxn];
int vis[maxn];
void init(int n)
{
    for(int i=1;i<=n;i++)
      p[i]=i;
    for(int i=0;i<=n;i++)
      edge[i].clear();
}
int Find(int x)
{
    return x==p[x]?x:Find(p[x]);
}
int Union(int pa,int y)
{
    int x1=Find(pa);
    int y1=Find(y);
    if(x1!=y1)
    {
        p[y1]=x1;
        ll u=max(s[x1].a,s[x1].a+s[y1].a-s[y1].b);
        s[x1].b=s[y1].b-s[y1].a-s[x1].a+u;
        s[x1].a=u;
    }
}
void dfs(int u,int pre)
{
      f[u]=pre;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==pre)
          continue;
        dfs(v,u);
    }
}
int main(){
     int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        init(n);
        priority_queue<node>que;
       for(int i=2;i<=n;i++)
        {
            scanf("%lld%lld",&s[i].a,&s[i].b);
            s[i].id=i;
            que.push(s[i]);
        }
        for(int i=2;i<=n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
       dfs(1,0);
       memset(vis,0,sizeof(vis));
       vis[1]=1;
       ll ans=0;
       ll pre=0;
       while(!que.empty())
       {
           node e=que.top();
           que.pop();
           if(vis[e.id]) continue;
           if(s[e.id].a!=e.a||s[e.id].b!=e.b) continue;
           int fa=Find(f[e.id]);
           if(vis[fa])
           {
               ans=min(ans,pre-s[e.id].a);
               pre=pre-s[e.id].a+s[e.id].b;
               vis[e.id]=1;
           }
           else{
               Union(fa,e.id);
               que.push(s[fa]);
           }
       }
       ans=min(ans,pre);
       printf("%lld\n",abs(ans));

    }

}
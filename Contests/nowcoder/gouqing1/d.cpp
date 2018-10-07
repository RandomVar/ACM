#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
const int maxnode=1e5*600+100;
struct node{
    int u,v,w;
    bool operator<(const node &b)
    {
        return w<b.w;
    }
}edge[maxn];
int v[maxn];
int sz[maxn];
int fa[maxn];
int root[maxn];
vector<int>vec[maxn];
int nex[maxnode][2];
int cnt;
int Find(int x)
{
    if(x==fa[x]) return x;
    int y=Find(fa[x]);
    return fa[x]=y;
}
int newnode()
{
    nex[cnt][0]=nex[cnt][1]=-1;
    cnt++;
    return cnt-1;
}
void inser(int rt,int x)
{
    int now=rt;
    for(int i=18;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(nex[now][id]==-1)
          nex[now][id]=newnode();
         now=nex[now][id];
    }
}
int query(int rt,int x)
{
    int now=rt;
    int ans=0;
    for(int i=18;i>=0;i--)
    {
        int id=(x>>i)&1;
        if(nex[now][id^1]!=-1)
        {
            ans+=(1<<i);
            now=nex[now][id^1];
        } 
        else now=nex[now][id];
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            vec[i].clear();
          vec[i].push_back(i);
          root[i]=newnode();
          fa[i]=i;
          sz[i]=1;
          inser(root[i],0);
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge+1,edge+n);
        for(int i=1;i<n;i++)
        {
            int x=edge[i].u;int y=edge[i].v;
            int w=edge[i].w;
            int fx=Find(x);
            int fy=Find(y);
            if(sz[fx]>sz[fy])
            {
                swap(fx,fy);
                swap(x,y);
            }
           w^=v[x]^v[y];
           int ans=0;
           for(int i=0;i<vec[fx].size();i++)
             ans=max(ans,query(root[fy],v[vec[fx][i]]^w));

           for(int i=0;i<vec[fx].size();i++)
           {
               v[vec[fx][i]]^=w;
            //    cout<<v[vec[fx][i]]<<endl;
               vec[fy].push_back(vec[fx][i]);
               inser(root[fy],v[vec[fx][i]]);
           }
           fa[fx]=fy;
           sz[fy]+=sz[fx];
           printf("%d%c",ans,i==n-1?'\n':' ');
        }
    }
}
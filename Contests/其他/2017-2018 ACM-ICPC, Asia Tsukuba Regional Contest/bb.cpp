#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
}a[20];
int vis[20];
int m;
typedef pair<int,int> P;
vector<P>g[400];
int tot;
P zhi[400];
int check(int fz,int fm,int zz,int mm)
{
    if(fz!=0&&fm!=0)
    {
        if(fz*mm==fm*zz) return 1;
        return 0;
    }
    if(fz==0&&zz==0) return 1;
    if(fm==0&&mm==0) return 1;
    return 0;
}
int solve(int u,int v)
{
    int zz=a[u].y-a[v].y;
    int mm=a[u].x-a[v].x;
    for(int i=1;i<=tot;i++)
     if(check(zhi[i].first,zhi[i].second,zz,mm))
       {
           return i;
       }
    tot++;
    zhi[tot].first=zz;zhi[tot].second=mm;
    return tot;
}
int ans,daan;
void gao(int id,int i,int num,int ans)
{
    if(id==tot+1)
    {
        // cout<<ans<<endl;
        daan=max(daan,ans);
        return;
    }
    if(i==g[id].size()) 
    {
        // ans+=num*(num-1)/2;
        gao(id+1,0,0,ans+num*(num-1)/2);
        return;
    }
    P x=g[id][i];
    if(!vis[x.first]&&!vis[x.second])
    {
        vis[x.first]=vis[x.second]=1;
       gao(id,i+1,num+1,ans);
       vis[x.first]=vis[x.second]=0;
    }
    gao(id,i+1,num,ans);
}

void init()
{
    for(int i=0;i<400;i++)
     g[i].clear();
     memset(vis,0,sizeof(vis));
}
int main()
{

    while(scanf("%d",&m)==1)
    {
        init();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        int ans=0;tot=0;
       for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
        {
            int id=solve(i,j);
           g[id].push_back(make_pair(i,j));
        }
        daan=0;ans=0;
        gao(1,0,0,0);
     printf("%d\n",daan);
    }
}
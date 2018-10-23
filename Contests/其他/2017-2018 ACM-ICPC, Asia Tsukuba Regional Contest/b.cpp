#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
}a[20];
int vis[20];
int m;
int check(int fz,int fm,int zz,int mm)
{
    if(fz!=0&&fm!=mm)
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
    int fz=a[u].y-a[v].y;
    int fm=a[u].x-a[v].x;
    // int y=gcd(abs(fz),abs(fm));
    // fz/=y;fm/=y;
    int ans=1;
    memset(vis,0,sizeof(vis));
    vis[u]=1;vis[v]=1;
    for(int i=1;i<=m;i++)
    {
        if(vis[i]) continue;
        vis[i]=1;
        int flag=0;
        for(int j=1;j<=m;j++)
        {
            if(vis[j]) continue;
          int zz=a[i].y-a[j].y;
          int mm=a[i].x-a[j].x;
          if(check(fz,fm,zz,mm))
            {
                // cout<<u<<" "<<v<<" "<<i<<" "<<j<<endl;
                vis[j]=1;
                ans++;
                flag=1;
               break;
            }
        }
          if(flag==0) vis[i]=0;
    }
    return ans;
}
int main()
{

    while(scanf("%d",&m)==1)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        int ans=0;
       for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
        {
            ans=max(ans,solve(i,j));
        }
     printf("%d\n",ans);
    }
}
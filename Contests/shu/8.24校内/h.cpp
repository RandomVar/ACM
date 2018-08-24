#include<bits/stdc++.h>
#define pb  push_back 
using namespace std;
struct node{
    int x,y;
    vector<int>vec;
}p[20];
int ans;
int cnt[10];
int a[10];
int n,m;
int mp[35][35];
void init()
{
    int k=0;
    p[++k].x=4;p[k].y=1;p[k].vec.pb(1);
    p[++k].y=4;p[k].x=1;p[k].vec.pb(1);
    p[++k].x=2;p[k].y=2;p[k].vec.pb(2);//
    p[++k].x=4;p[k].y=2;p[k].vec.pb(3);p[k].vec.pb(3);
    p[++k].x=2;p[k].y=4;p[k].vec.pb(3);p[k].vec.pb(3);
    p[++k].x=4;p[k].y=2;p[k].vec.pb(4);p[k].vec.pb(4);

    // p[++k].x=4;p[k].y=2;p[k].vec.pb(4);p[k].vec.pb(3);
    p[++k].x=2;p[k].y=4;p[k].vec.pb(4);p[k].vec.pb(4);//
    p[++k].x=7;p[k].y=2;p[k].vec.pb(5);p[k].vec.pb(6);p[k].vec.pb(7);
    p[++k].x=7;p[k].y=2;p[k].vec.pb(5);p[k].vec.pb(6);p[k].vec.pb(7);
    p[++k].x=2;p[k].y=7;p[k].vec.pb(5);p[k].vec.pb(6);p[k].vec.pb(7);
    p[++k].x=2;p[k].y=7;p[k].vec.pb(5);p[k].vec.pb(6);p[k].vec.pb(7);
}
void dfs(int x,int y)
{
   
    for(int i=1;i<=11;i++)
    {
        if(x+p[i].x-1>n||y+p[i].y-1>m) continue; 
        int flag=1;
        for(int j=0;j<p[i].vec.size();j++)
        {
            int c=p[i].vec[j];
               a[c]--;
            if(a[c]<0) flag=0;
        }
        if(flag)
        {
            int f=1;

           for(int xx=x;xx<=x+p[i].x-1;xx++)
            for(int yy=y;yy<=y+p[i].y-1;yy++)
            {
              if(mp[xx][yy]) f=0;
              mp[xx][yy]++;
            }
           if(f!=0) 
           {
               if(x+p[i].x-1==n&&y+p[i].y-1==m)
                 cout<<i<<endl,ans++;
          else{
           
            /*for(int c=xx;c<=n;c++)
              for(int r=1;r<=m;r++)
                if(!mp[c][r]) dfs(c,r),ff=0;
            if(ff)
                ans++;
              */
        if(y+p[i].y-1<m)
          dfs(x,y+p[i].y);
          else
           dfs(x+p[i].x,1); 
        }
           }
        for(int xx=x;xx<=x+p[i].x-1;xx++)
            for(int yy=y;yy<=y+p[i].y-1;yy++)
              mp[xx][yy]--;
        }
        for(int j=0;j<p[i].vec.size();j++)
           { int c=p[i].vec[j];a[c]++;}
    }
}
int main()
{
    // freopen("data.in","r",stdin);
     //freopen("data.out","w",stdout);
    init();
   int t;
   scanf("%d",&t);
   while(t--)
   {
      memset(mp,0,sizeof(mp));
       scanf("%d%d",&n,&m);
       for(int i=1;i<=7;i++)
        scanf("%d",&cnt[i]);
     for(int i=1;i<=7;i++)
      a[i]=cnt[i];
   
   ans=0;
   dfs(1,1);
   printf("%d\n",ans);
   }
}
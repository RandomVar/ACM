#include<bits/stdc++.h>
using namespace std;
int vis[20][20];
struct node
{
    int s;
    int x,y;
}a[10];
int n,xx,yy;
int idx[]={-1,-1,-1,0,0,1,1,1};
int idy[]={-1,0,1,-1,1,0,-1,1};
int vec[10][10]; 
int ishas(int x,int y)
{
    for(int i=1;i<=n;i++)
      if(a[i].x==x&&a[i].y==y)
       return 1;
    if(xx==x&&yy==y)
     return 1;
     return 0;
}
int getid(int x,int y)
{
    return (y-4)*3+(x-1);
}
void init()
{
    
  vec[0][0]=1;vec[0][1]=3;vec[0][2]=4;
  vec[1][0]=2;vec[1][1]=4;vec[1][2]=0;
  vec[2][0]=1;vec[2][1]=4;vec[2][2]=5;
  vec[3][0]=0;vec[3][1]=4;vec[3][2]=6;
  vec[4][0]=0;vec[4][1]=1;vec[4][2]=2;  vec[4][3]=3;vec[4][4]=8;vec[4][5]=5;  vec[4][6]=6;vec[4][7]=7;
  vec[5][0]=2;vec[5][1]=8;vec[5][2]=4;
  vec[6][0]=3;vec[6][1]=4;vec[6][2]=7;
  vec[7][0]=6;vec[7][1]=4;vec[7][2]=8;
  vec[8][0]=7;vec[8][1]=5;vec[8][2]=4;
}
int get(int x)
{
    if(x==1)
    {
        return -2;
    }
    if(x==2)
     return -1;
    if(x==3)
     return 1;
     if(x==4)
      return 2;
}
int getj(int x)
{
    if(x>0) return x-1;
    return x+1;
}
void solve(int id)
{
    if(a[id].s==1)
    {
     for(int i=1;i<=3;i++)
        vis[i][a[id].y]=1;
    }
    else if(a[id].s==2)
    {
        for(int i=a[id].y-1;i>=1;i--)
        {
            if(!ishas(a[id].x,i))
            {
                vis[a[id].x][i]=1;
            }
            else break;
        }
        for(int i=a[id].y+1;i<=9;i++)
        {
            if(!ishas(a[id].x,i))
            {
                vis[a[id].x][i]=1;
            }
            else break;
        }
        for(int i=a[id].x+1;i<=10;i++)
        {
            if(!ishas(i,a[id].y))
              vis[i][a[id].y]=1;
            else break;
        }
        for(int i=a[id].x-1;i>=1;i--)
        {
            if(!ishas(i,a[id].y))
              vis[i][a[id].y]=1;
              else break;
        }
    }
    else if(a[id].s==3)
    {
        int flag=0;
        for(int i=a[id].y-1;i>=1;i--)
        {
            if(!flag&&ishas(a[id].x,i))
              flag=1;
            else if(flag&&ishas(a[id].x,i))
             {
                 vis[a[id].x][i]=1;
                 break;
             }
        }
        flag=0;
        for(int i=a[id].y+1;i<=9;i++)
        {
             if(!flag&&ishas(a[id].x,i))
              flag=1;
            else if(flag&&ishas(a[id].x,i))
             {
                 vis[a[id].x][i]=1;
                 break;
             }
        }
         flag=0;
         for(int i=a[id].x-1;i>=1;i--)
         {
             if(!flag&&ishas(i,a[id].y))
              flag=1;
              else if(flag&&ishas(i,a[id].y))
               {
                   vis[i][a[id].y]=1;
                   break;
               }
         }
        flag=0;
        for(int i=a[id].x+1;i<=10;i++)
        {
            if(!flag&&ishas(i,a[id].y))
              flag=1;
              else if(flag&&ishas(i,a[id].y))
               {
                   vis[i][a[id].y]=1;
                   break;
               }
        }

    }
    else if(a[id].s==4)
    {
        for(int x=1;x<=4;x++)
          for(int y=1;y<=4;y++)
          {
              int cx=get(x);
              int cy=get(y);
              int jx=getj(cx);
              int jy=getj(cy);
              if(!ishas(a[id].x+jx,a[id].y+jy)&&ishas(a[id].x+cx,a[id].y+cy))
                {
                    vis[a[id].x+cx][a[id].y+cy]=1;
                }
          }
    }
}
char s[10];
int main()
{
   init();
    while(scanf("%d",&n)==1)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&xx,&yy);
        if(!n&&!xx&&!yy) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(s[0]=='H')
            {
                a[i].s=4;
            }
            else if(s[0]=='G')
              a[i].s=1;
            else if(s[0]=='R')
             a[i].s=2;
            else if(s[0]=='C')
            a[i].s=3;
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i=1;i<=n;i++)
        {
            solve(i);
        }
        int flag=0;
        int id=getid(xx,yy);
        for(int i=0;i<3||(id==4&&i<9);i++)
        {
            int x=vec[id][i]%3+1;
            int y=vec[id][i]/3+4;
        if(!vis[x][y])
              {
                //   cout<<x<<" "<<y<<endl;
              flag=1;
              }
        }
        if(!flag)
         printf("YES\n");
        else printf("NO\n");
       }
}
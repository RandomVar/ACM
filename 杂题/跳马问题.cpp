#include<bits/stdc++.h>
using namespace std;
int vis[20][20];
int cx[]={1,1,-1,-1,2,2,-2,-2};
int cy[]={2,-2,2,-2,1,-1,1,-1};
struct node
{
    int st;int x,y;
 bool operator<(const node &b)const
 {
     return st>b.st;
 }
};
int bfs(int sx,int sy,int tx,int ty)
{
    priority_queue<node>que;
  que.push(node{1,sx,sy});
  vis[sx][sy]=1;
  while(!que.empty())
  {
      node p=que.top();
      que.pop();
      for(int i=0;i<8;i++)
      {
          int xx=p.x+cx[i];
          int yy=p.y+cy[i];
          if(xx==tx&&yy==ty)
            return p.st+1;
          if(xx>=1&&xx<=7&&yy>=1&&yy<=8&&!vis[xx][yy])
            {
              que.push(node{p.st+1,xx,yy});
              vis[xx][yy]=p.st+1;
            }
      }
  }
return -1;
}
int main()
{
    char s[10];
    while(scanf("%s",s)==1)
    {
        memset(vis,0,sizeof(vis));
        int sx=s[0]-'a'+1;
        int sy=s[1]-'0';
        scanf("%s",s);
        int tx=s[0]-'a'+1;
        int ty=s[1]-'0';
        int ans=bfs(sx,sy,tx,ty);
       if(ans==-1)
         printf("Cannot move!");
        else
        {
            printf("%c%c==>%c%c: %d moves\n",sx+'a'-1,sy+'0',tx+'a'-1,ty+'0',ans-1);
        }
    }
}
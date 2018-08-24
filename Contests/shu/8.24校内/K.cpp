#include<bits/stdc++.h>
using namespace std;
int N,M;
int G[105][105];
int vis[105][105][150];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
struct node
{
    int x;
    int y;
    int state;
    int step;
    node(int x,int y,int state,int step):x(x),y(y),state(state),step(step){}
};
int tot;
int bfs(int xx,int yy)
{
    queue<node> q;
    q.push(node(xx,yy,0,0));
    vis[xx][yy][0]=1;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=u.x+dx[i];
            int ty=u.y+dy[i];
            if(tx<1||ty<1||tx>N||ty>M||G[tx][ty]==-1)
                continue;
            int st=u.state|G[tx][ty];
            if(st==tot)
                return u.step+1;
            if(vis[tx][ty][st])
                continue;
            q.push(node(tx,ty,st,u.step+1));
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&N,&M)==2&&N&&M)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                scanf("%d",&G[i][j]);
        int ans;
        int di,dj;
        tot=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(G[i][j]==2)
                {
                    G[i][j]=0;
                    di=i,dj=j;
                    continue;
                }
                if(G[i][j]==1)
                {
                    G[i][j]=(1<<tot);
                    tot++;
                }
            }
        }
        tot=(1<<tot)-1;
        printf("%d\n",bfs(di,dj));
    }
    return 0;
}
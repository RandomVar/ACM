#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node
{
    int x,y,cost;
    bool operator<(const node &b)const
    {
        return cost>b.cost;
    }
};
int d[maxn][maxn];
void bfs()
{
    memset(d,0x3f,sizeof(d));
    priority_queue<node>que;
  
    d[0][0]= s[0][0]=='a'?0:1;
      que.push(node{0,0,d[0][0]});
    while(!que.empty())
    {
        node p=que.top();
        que.pop();
     
        for(int i=0;i<4;i++)
        {
            int x=que.first()+dx[i];
            int y=que.second()+dy[i];
            int t=s[x][y]=='a'?0:1;
            t+=d[p.x][p.y];
        if(d[x][y]<t)
        {
            if(d[x][y]<k)
            que.push(make_pair{x,y,t});
           d[x][y]=t;
        }
        }
    }
}  
void solve()
{
    q.push(node{n-1,n-1,0});
    while(!q.empty())
    {
        node p=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.x+dx[i];
            int y=p.y+dy[i];
            if(d2[i]>p.cost)
            {
                d2[i]=p.cost;
            }

        }
    }
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
          cin>>s[i];
          k=min(k,2*n-1);
        bfs();
      for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
         if(d[x][y]==k)
         {
             q.push(node{x,y,0});
         }
        solve();
    }
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
// int dx[]={1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0};
// int dy[]={1,1,1,0,0,0,-1,-1,1,1,-1,-1};
// int dz[]={1,0,-1,1,-1,1,-1,1,-1};
ll cost[50][50][50];
ll dp[50][50][50];
  int n;
  int check(int x,int y,int z)
  {
    if(x<0||y<0||z<0) return 0;
    if(x>=n||y>=n||z>=n) return 0;
    return 1; 
  }
  struct node{
    int x,y,z;ll val;
    bool operator<(const node &b)const{
      return val<b.val;
    }
  };
int main()
{

  while(cin>>n)
  {
    ll ans=-1;
    node pos;
    for(int i=1;i<=n*n*n;i++)
    {
      int x,y,z;ll p;
      cin>>x>>y>>z>>p;
       cost[x][y][z]=p;
       if(ans<p)
       {
         ans=p;
         pos.x=x;pos.y=y;pos.z=z;
         pos.val=p;
       }
      //  dp[x][y][z]=p;
      // ans=max(ans,p);
    }
    memset(dp,0,sizeof(dp));
    dp[pos.x][pos.y][pos.z]=cost[pos.x][pos.y][pos.z];
    priority_queue<node>que;
    que.push(pos);
    while(!que.empty())
    {
      node e=que.top();
      que.pop();
      if(e.val<dp[e.x][e.y][e.z]) continue;
      // cout<<"!"<<e.x<<e.y<<e.z<<" "<<dp[e.x][e.y][e.z]<<endl;
       for(int i=0;i<6;i++)
      {
        
        int x=dx[i]+e.x;int y=dy[i]+e.y;int z=dz[i]+e.z;
        // x+=e.x;y+=e.y;z+=e.z;
        //  cout<<"hh"<<x<<" "<<y<<" "<<z<<endl;
        if(check(x,y,z))
        {
        //  cout<<"??"<<x<<" "<<y<<" "<<z<<" "<<dp[x][y][z]<<" &&"<<cost[x][y][z]<<" "<<cost[e.x][e.y][e.z]<<" "<<dp[x][y][z]<<" "<<dp[e.x][e.y][e.z]+cost[x][y][z]<<endl;
          if(cost[x][y][z]<cost[e.x][e.y][e.z]&&dp[x][y][z]<dp[e.x][e.y][e.z]+cost[x][y][z])
            {
              dp[x][y][z]=dp[e.x][e.y][e.z]+cost[x][y][z];
              ans=max(ans,dp[x][y][z]);
              // cout<<x<<" "<<y<<" "<<z<<" "<<dp[x][y][z]<<endl;
              que.push(node{x,y,z,dp[x][y][z]});
            }
        }
      }
    }
    // bfs();
    // for(int i=0;i<n;i++)
    // for(int j=0;j<n;j++)
    //  for(int k=0;k<n;k++)
    //  for(int x=-1;x<=1;x++)
    // for(int y=-1;y<=1;y++)
    //  for(int z=-1;z<=1;z++)
    //  {
    //    if(x==0&&y==0&&z==0) continue;
    //    x+=i;y+=j;z+=k;
       
    //   //  int x=i+dx[e];int y=j+dy[e];int z=k+dz[e];
    //   //  cout<<x<<" "<<k<<" "<<z<<endl;
    //   if(check(x,y,z)&&cost[i][j][k]>=cost[x][y][z])
    //   {
    //     dp[x][y][z]+=dp[i][j][k];
    //     ans=max(ans,dp[x][y][z]);
    //   }
    //  }
     cout<<ans<<endl;
    
  }
}
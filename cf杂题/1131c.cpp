#include<bits/stdc++.h>
using namespace std;
const int maxn=1500;
int vis[maxn*2];
int ru[maxn*2];
const int inf=0x3f3f3f3f;
struct node
{
  int to;int cost;
  node(int _to,int _cost)
  {
    to=_to;cost=_cost;
  }
};
string s[maxn];
vector<node>edge[maxn*2];

int main()
{
  int n,m;
  while(cin>>n>>m)
  {
    for(int i=0;i<n;i++)
     cin>>s[i];
    //  for(int i=0;i<maxn;i++)
    //   vis[i]=inf;
     memset(vis,0,sizeof(vis));
     memset(ru,0,sizeof(ru));
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(s[i][j]=='<')
        {
          edge[i].push_back(node(j+n,1));
          ru[j+n]++;
          // edge[j+n].push_back(node(i,-1));
        }
        else if(s[i][j]=='>')
        {
          edge[j+n].push_back(node(i,1));
          ru[i]++;
          // edge[i].push_back(node(j+n,-1));
        }
        else if(s[i][j]=='=')
        {
           edge[i].push_back(node(j+n,0));
           edge[j+n].push_back(node(i,0));
        }
      }
    }
    queue<int>que;
    int flag=1;
    for(int i=0;i<n+m;i++)
    {
       if(ru[i]==0)
         {
           que.push(i);
            vis[i]=1;
         }
    }
    if(que.empty())
    {
      cout<<"No"<<endl;
      continue;
    }
    while(!que.empty())
    {
       int p=que.front();
       que.pop();
       for(int i=0;i<edge[p].size();i++)
       {
         node e=edge[p][i];
         cout<<p<<" "<<vis[p]<<" "<<e.to<<" "<<vis[e.to]<<endl;
         if(!vis[e.to])
           {
             ru[e.to]--;
             if(ru[e.to]==0)
             {
               vis[e.to]=vis[p]+e.cost;
               que.push(e.to);
             }
           }
           else
           {
             if(vis[e.to]!=vis[p]+e.cost)
               {flag=0;break;}
           }
       }
       if(flag==0) break;
    }
    // int flag=1;
    //  for(int i=0;i<n+m;i++)
    //  {
    //    if(vis[i]==inf)
    //     if(!dfs(i,1))
    //        {flag=0;break;}
    //  }
     if(!flag) {
       cout<<"No"<<endl;
       continue;
     }
     else cout<<"Yes"<<endl;
     for(int i=0;i<n;i++)
      cout<<vis[i]<<" ";
     cout<<endl;
    for(int i=0;i<m;i++)
     cout<<vis[i+n]<<" ";
     cout<<endl;
  }
}
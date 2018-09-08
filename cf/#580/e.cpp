#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int p[5];
int vis[5];
vector<int> edge[5][5];
ll G[5][5];
ll cc[5][5];
int d[5];
void init()
{
    for(int i=0; i<=4; i++)
        p[i]=i;
}
int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}

int Union(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)
        return 0;
    p[x1]=y1;
      return 1;
}
void add(int u,int v)
{
    d[u]++;
    d[v]++;
}
int ok()
{
    int x=0;
    for(int i=1;i<=4;i++)
      if(d[i]%2) x++;
    // cout<<x<<endl;
   if(x>2)  return 0;
   return 1; 
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       mem(G,0x3f);
       mem(cc,0);
      for(int i=1;i<=4;i++) G[i][i]=0;
       for(int i=1;i<=n;i++)
       {
           int u,v,val;
           cin>>u>>val>>v;
           if(u>v) swap(u,v);
           edge[u][v].pb(val);
       }
       for(int i=1;i<=4;i++)
       {
           for(int j=i;j<=4;j++)
           {
               sort(edge[i][j].begin(),edge[i][j].end());
               int sz=edge[i][j].size();
               ll ans=0;
               for(int k=sz-1;k>=0;k--)
                 ans+=edge[i][j][k];
                if(sz%2==1&&i!=j) 
                {
                    ans-=edge[i][j][0];
                   G[i][j]=edge[i][j][0];
                }
                else if(sz) 
                {
                  if(i!=j)    
                      G[i][j]=-edge[i][j][0];
                }
                cc[i][j]=ans;
           }
       }
       
       ll daan=0;
       for(int i=0;i<(1<<16);i++)
       {
        //    cout<<"*";
           init();
           mem(vis,0);
           mem(d,0);
           ll ans=0;
          for(int j=0;j<16;j++)
          {
              if((i&(1<<j))==0) continue;
              int u=j/4+1;
              int v=j%4+1;
             if(u>v) continue;
            if(G[u][v]==INF) continue;
              ans+=G[u][v];
             vis[u]=vis[v]=1;
             
             add(u,v);
             Union(u,v);
            // cout<<u<<" "<<v<<endl;
          }
            
          for(int j=0;j<16;j++)
          {
              int u=j/4+1;
              int v=j%4+1;
              if(u>v) continue;
              if(vis[u]||vis[v]) 
                 {
                     ans+=cc[u][v];
                 
                 }
                 if(vis[u]&&vis[v]&&G[u][v]<0) Union(u,v);
          }
          
          int p=-1;int flag=1;
          for(int i=1;i<=4;i++)
            if(vis[i]) 
            {
                if(p==-1)
                  p=Find(i);
                else if(p!=Find(i))
                  flag=0;
            }
        
          if(flag&&ok()) 
          {
              daan=max(daan,ans);
          }
        
       }
       cout<<daan<<endl;
   }
 return 0;
  }

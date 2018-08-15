/*
  求图能由几笔画出来，并输出路径

  将奇度点连起来，形成一个欧拉回路，再把新添的边去掉
  一个连通向量的max(d/2,1) //d为奇度点的个数

*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
struct node{
   int to;int id;
};
vector<node>edge[maxn];
int d[maxn];
int vis[maxn];
int tag[maxn*3];
vector<int>ans[maxn*2];
int cnt;
void dfs(int u)
{
    vis[u]=1;
    int len=edge[u].size()-1;//最先遍历新增加的点
    for(int i=len;i>=0;i--)
    {
        node e=edge[u][i];
       // cout<<u<<" "<<e.to<<endl;
        if(!tag[abs(e.id)]) 
          {
              tag[abs(e.id)]=1; 
              dfs(e.to);
              if(e.id>1e5+5) cnt++;
              else ans[cnt].push_back(-e.id); 
            // cout<<cnt<<" "<<e.id<<endl;
          }
    }
}

void init(int n)
{
    mem(d,0);
    mem(vis,0);
    mem(tag,0);
    for(int i=0;i<=n;i++)
      edge[i].clear();
    for(int i=0;i<maxn*2;i++)
     ans[i].clear();
   cnt=0;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(cin>>n>>m)
   {
       init(n);
       for(int i=1;i<=m;i++)
       {
             int u,v;
             cin>>u>>v;
             edge[u].push_back(node{v,i});
             edge[v].push_back(node{u,-i});
             d[u]++;
             d[v]++;
       }
       int x=0;
       int base=1e5+10;
       for(int i=1;i<=n;i++)
       {
           if(d[i]&1)
           {
              if(x) {
                  // cout<<i<<" "<<x<<endl;
                  edge[x].push_back(node{i,++base});
                  edge[i].push_back(node{x,base});
                  x=0;   
              }
              else x=i;
          
           }
       }

       for(int i=1;i<=n;i++)
       {
           if(!vis[i]&&(d[i]&1))
              cnt++,dfs(i),cnt--;
        }

     for(int i=1;i<=n;i++)
     {
         if(!vis[i]&&d[i])  cnt++,dfs(i);
     }
   
        cout<<cnt<<endl;
      for(int i=1;i<=cnt;i++)
      {
         
          cout<<ans[i].size();
         int len=ans[i].size();
         for(int j=0;j<len;j++)
            cout<<" "<<ans[i][j];
            cout<<endl;
      }

   }

 return 0;
  }

/*
3 2
1 2
2 3
*/
#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e5+100;
int h[maxn];
int vis[maxn][2];
int p[maxn][2];
vector<int>edge[maxn];
void dfs(int x,int st,int pre){
   p[x][st]=pre;
   vis[x][st]=1;
   int flag=0;
   for(int i=0;i<edge[x].size();i++){
      int t=edge[x][i];
      if(!vis[t][st^1])  dfs(t,st^1,x);
   }

}
bool huan(int x){
   h[x]=1;
   for(int i=0;i<edge[x].size();i++){
        int t=edge[x][i];
      if(h[t]==1||h[t]==0&&huan(t)) return 1;
   }
   h[x]=2;
   return 0;
}

void print(int x,int st){
   if(x==0) return;
   print(p[x][st],st^1);
   printf("%d ",x);
}
int main(){
   int n,m;
   while(scanf("%d%d",&n,&m)==2){
        memset(vis,0,sizeof(vis));
        memset(h,0,sizeof(h));
        for(int i=0;i<=n;i++)
            edge[i].clear();
      int c;
      for(int i=1;i<=n;i++){
        scanf("%d",&c)==1;
        for(int j=1;j<=c;j++)
        {
            int t;
            scanf("%d",&t);
            edge[i].push_back(t);
        }
      }

      int s;
      scanf("%d",&s);
      dfs(s,1,0);
      int flag=0;
      for(int i=1;i<=n;i++){
          if(vis[i][0]&&edge[i].size()==0)
          {
              flag=1; printf("Win\n"); print(p[i][0],1);
              printf("%d\n",i);
              break;
          }
      }
     if(flag==0){
      if(huan(s)) printf("Draw\n");
      else printf("Lose\n");
     }

   }
return 0;
}

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
int vis[maxn];
/*struct node{
    int id;int cnt;
    bool operator<(const node &b)const {
        return cnt<b.cnt;
    }
}*/
int d[maxn];
vector<int>edge[maxn];
int ans;
void dfs(int x)
{
     for(int i=0;i<edge[x].size();i++)
    {
        int t=edge[x][i];
        if(d[t]%2==0)
        {
            ans++;
            d[x]--;
            d[t]--;
            
        }
         dfs(t);
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       for(int i=0;i<=n;i++)
       edge[i].clear();
      // memset(d,0,sizeof(d));
       for(int i=1;i<n;i++)
       {
           int u,v;
           cin>>u>>v;
           edge[u].pb(v);
           edge[v].pb(u);
           d[u]++;
           d[v]++;
           //d[u].id=u;
           //d[v].id=v;
       }
       //sort(d+1,d+n+1);
       ans=0;
       mem(vis,0);
       int flag=0;
       int f=1;
      dfs(1);
       /*for(int i=1;i<=n;i++)
       {
           if(d[i].cnt%2==0)
           {
               int x=d[i].id;
               for(int j=0;j<edge[x].size();j++)
               {
                   int t=edge[x][j];
                   if(d[t].cnt&&d[t].cnt%2==0)
                   {
                       d[t].cnt--;
                       d[i].cnt--;
                       ans++;
                       flag=1;
                       //break;
                   }
               }
               if(!flag) f=0;
           }*/
           /*if(d[i].cnt%2){
               flag=0;
               for(int j=0;j<edge[d[i].id].size();j++)
               {
                   int t=edge[d[i].id][j];
                  if(d[t].cnt&&d[t].cnt%2==0){
                      //vis[t]=1;
                      d[t].cnt--;
                      
                      ans++;
                 //  flag=1;
                   break;
                  }
               }
               //if(flag==0) {f=0;break;}
           }*/
    //dfs(1);
    
       if(f==0) cout<<-1<<endl;
       else cout<<ans<<endl;
   }


 return 0;
  }


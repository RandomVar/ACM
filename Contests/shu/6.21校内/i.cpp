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
int vis[1010][1010];
string s[1010];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int check(int u,int v){
  if(u<0||u>=n||v<0||v>=m)
      return 0;
  if(vis[u][v]) return 0;
  return 1;
}

void dfs1(int u,int v){
    vis[u][v]=1;
      for(int i=0;i<4;i++)
      {
          int xx=u+dx[i];int yy=v+dy[i];
          if(check(xx,yy)&&s[xx][yy]=='1')
            dfs1(xx,yy);
      }
}
void dfs2(int u,int v){
    vis[u][v]=1;
      for(int i=0;i<4;i++)
      {
          int xx=u+dx[i];int yy=v+dy[i];
          if(check(xx,yy)&&s[xx][yy]=='0')
            dfs2(xx,yy);
      }

}
int main(){
  //int n,m;
  while(cin>>n>>m){
     for(int i=0;i<n;i++)
        cin>>s[i];
     int flag=0;
     memset(vis,0,sizeof(vis));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(s[i][j]=='0') continue;
          if(flag==1&&!vis[i][j])
          {flag=-1;break;}
          if(!vis[i][j]){
              dfs1(i,j);
            flag=1;
          }
          }
          if(flag==-1) break;
        }
       // cout<<flag<<endl;
        if(flag==0||flag==-1) {cout<<-1<<endl;continue;}
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(i==0||j==0||i==n-1||j==m-1)
               if(s[i][j]=='0'&&!vis[i][j]){
                  dfs2(i,j);
               }
        }
        flag=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             if(s[i][j]=='0'&&!vis[i][j])
             {
                if(flag==0){
                 dfs2(i,j);
                 flag=1;
                }
                else if(flag==1)
                {
                    flag=-1;break;
                }
             }
          }
          if(flag==-1) break;
        }
          if(flag==-1) {cout<<-1<<endl;continue;}
          else if(flag==1) cout<<0<<endl;
          else cout<<1<<endl;




      }
  }


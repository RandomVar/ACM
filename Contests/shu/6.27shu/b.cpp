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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string s[100];
int vis[100][100];
int n,m;
int check(int u,int v){
  if(u<0||u>=n||v<0||v>=m) return 0;

return 1;
}
int dfs(int u,int v,int preu,int prev,int pos){
    //cout<<u<<" "<<v<<endl;
  vis[u][v]=1;
  for(int i=0;i<4;i++){
    int xx=u+dx[i];
    int yy=v+dy[i];
     if(check(xx,yy)){
            if(xx==preu&&yy==prev) continue;
        if(vis[xx][yy]==1&&pos>=4) return 1;
       else if(vis[xx][yy]==2||s[xx][yy]!=s[u][v]) continue;
        if(dfs(xx,yy,u,v,pos+1)) return 1;
   }
   }
     vis[u][v]=2;
return 0;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while(cin>>n>>m){
     for(int i=0;i<n;i++)
        cin>>s[i];
        int flag=0;
        mem(vis,0);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(vis[i][j]==0)
            if(dfs(i,j,-1,-1,1)) {flag=1;break;}
    }
    if(flag) break;
  }
 /* for(int i=0;i<n;i++){
  for(int j=0;j<m;j++)
    cout<<vis[i][j]<<" ";
    cout<<endl;}*/
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}
}

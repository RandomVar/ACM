#include<bits/stdc++.h>
using namespace std;
char mp[15][15];
int vis[15][15];
int biao[15][15];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dfs(int u,int v){
  vis[u][v]=1;
  int cnt=0;
  for(int i=0;i<4;i++)
  {
      int xx=u+dx[i];
      int yy=v+dy[i];
      if(xx>=0&&xx<9&&yy>=0&&yy<9&&!vis[xx][yy]&&!biao[xx][yy])
         if(mp[xx][yy]=='.') {
                biao[xx][yy]=1;
                cnt++;
         }
         else if(mp[xx][yy]=='o') {
            cnt+=dfs(xx,yy);
  }

  }
return cnt;
}
int main(){
  int t;
  cin>>t;int cas=0;
  while(t--){
    getchar();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<9;i++)
        cin>>mp[i];
        int flag=1;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
          if(!vis[i][j]&&mp[i][j]=='o')
              {
                  memset(biao,0,sizeof(biao));
                  int f=dfs(i,j);
                  if(f==1) {flag=0;break;}

         }
         cout<<"Case #"<<++cas<<": ";
    if(flag==0) cout<<"Can kill in one move!!!"<<endl;
    else cout<<"Can not kill in one move!!!"<<endl;

}
return 0;
}

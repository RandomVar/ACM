#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;int cnt;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char a[30][30];
int vis[30][30];
void dfs(int x,int y){
  if(x<0||x>=n||y<0||y>=m) return;
    vis[x][y]=1;
  if(a[x][y]=='.'||a[x][y]=='@') cnt++;
  else if(a[x][y]=='#') return;
  for(int i=0;i<4;i++)
    if(!vis[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);

}
int main(){
  while(cin>>m>>n&&m&&n){
        int x,y;
        memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
           getchar();
     for(int j=0;j<m;j++){
        cin>>a[i][j];
     if(a[i][j]=='@') {x=i;y=j;}
     }
  }

  cnt=0;
  dfs(x,y);
    cout<<cnt<<endl;

  }
}

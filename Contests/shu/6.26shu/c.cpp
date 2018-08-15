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
const int maxn=200010;
struct node{
 int x;int y;int st;

};
int xi,xj;int yi,yj;
int n,m,d;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int vis[maxn+100];

string s[maxn];
int check(int u,int v){
  if(u<0||u>=n||v<0||v>=m) return 0;
  if(vis[u*m+v]) return 0;
return 1;
}

int bfs(){

   queue<node>que;
   if(check(xi,xj)==0) return -1;
  if(check(yi,yj)==0) return -1;
     vis[xi*m+xj]=1;
   que.push(node{xi,xj,0});
   while(!que.empty()){
      node t=que.front();
      que.pop();
     //cout<<t.x<<" "<<t.y<<endl;
       for(int i=0;i<4;i++){
          int xx=t.x+dx[i];
          int yy=t.y+dy[i];
          if(check(xx,yy))
          {
              if(s[xx][yy]=='F') return t.st+1;
              vis[xx*m+yy]=1;
              que.push(node{xx,yy,t.st+1});
          }
       }
   }
   return -1;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //int n,m,d;
  while(cin>>n>>m>>d){
        queue<node>que;
        memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
              if(s[i][j]=='S') {xi=i;xj=j;}
              if(s[i][j]=='F') {yi=i;yj=j;}
            if(s[i][j]=='M') {vis[i*m+j]=1;que.push(node{i,j,0});}

        }
        while(!que.empty()){
      node e=que.front();
      que.pop();
      if(e.st>=d) break;
      for(int i=0;i<4;i++){
          int xx=e.x+dx[i];
          int yy=e.y+dy[i];
          if(check(xx,yy)){
             vis[xx*m+yy]=1;
             que.push(node{xx,yy,e.st+1});

          }
      }

  }
      cout<<bfs()<<endl;



  }


}


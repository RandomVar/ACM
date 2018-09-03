#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=310;
int vis[maxn][maxn];
int step[maxn][maxn];
int n;
struct node{
int x,y;
};
queue<node>q1;
queue<node>q2;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,-2,2,2,-2};
bool check(node a){
  if(a.x>=0&&a.x<n&&a.y>=0&&a.y<n)
    return true;
  return false;
}
int bfs(node s,node t){
    while(!q1.empty())
        q1.pop();
    while(!q2.empty())
        q2.pop();
   vis[s.x][s.y]=1;
   q1.push(s);
   vis[t.x][t.y]=2;
   q2.push(t);
   step[s.x][s.y]=0;
   step[t.x][t.y]=0;
   while(!q1.empty()||!q2.empty()){
      if(!q1.empty()){
         node e=q1.front();
         q1.pop();
         int st=step[e.x][e.y];
         for(int i=0;i<8;i++){
                node t;
         t.x=e.x+dx[i];t.y=e.y+dy[i];
            if(check(t)){
                if(vis[t.x][t.y]==2){
                    return step[t.x][t.y]+st+1;
                }
                else if(!vis[t.x][t.y]){
                    vis[t.x][t.y]=1;
                    step[t.x][t.y]=st+1;
                    q1.push(t);
                }
            }
         }
      }
      if(!q2.empty()){
         node e=q2.front();
         q2.pop();
         int st=step[e.x][e.y];
         for(int i=0;i<8;i++){
                node t;
         t.x=e.x+dx[i];t.y=e.y+dy[i];
            if(check(t)){
                if(vis[t.x][t.y]==1){
                    return step[t.x][t.y]+st+1;
                }
                else if(!vis[t.x][t.y]){
                    vis[t.x][t.y]=2;
                    step[t.x][t.y]=st+1;
                    q2.push(t);
                }
            }
         }
      }

   }
}
int main(){
   int tt;
   cin>>tt;
   while(cin>>n){
    memset(vis,0,sizeof(vis));
    //memset(step,0,sizeof(step));
    node s;node t;
    cin>>s.x>>s.y>>t.x>>t.y;
    if(s.x==t.x&&s.y==t.y) cout<<0<<endl;
    else cout<<bfs(s,t)<<endl;
   }
}

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=11;
struct node{
	int dis;int x;int y;
};
int n,m;
int vis[maxn][maxn];
char map[maxn][maxn];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0}; 
queue<node>que;
int bfs(){
	int ans=0;
	node e;
	while(!que.empty()){
	e=que.front();que.pop();
		for(int i=0;i<4;i++){
			if(e.x+dx[i]<n&&e.x+dx[i]>=0&&e.y+dy[i]<m&&e.y+dy[i]>=0&&map[e.x+dx[i]][e.y+dy[i]]=='#'&&vis[e.x+dx[i]][e.y+dy[i]]==0)
			  {
			  //ans=e.dis+1;
		      que.push((node){e.dis+1,e.x+dx[i],e.y+dy[i]});
		      vis[e.x+dx[i]][e.y+dy[i]]=1;
		}}
	}
  for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
   if(map[i][j]=='#'&&(!vis[i][j])) return -1;
   return e.dis;
   }
	 
int main(){
	int x;cin>>x;int k=0;
	while(k<x){
		k++;int ans=INF;
		cin>>n>>m;
		vector<node>v;
		for(int i=0;i<n;i++)
		  scanf("%s",map[i]);
		for(int i=0;i<n;i++)
		  for(int j=0;j<m;j++){
		  	if(map[i][j]=='#')
			   v.push_back((node){0,i,j});
				 }
		for(int i=0;i<v.size();i++)
		  for(int j=i;j<v.size();j++){
		  	while(!que.empty())
		      que.pop();
		    memset(vis,0,sizeof(vis));
		  	que.push(v[i]);
		  	vis[v[i].x][v[i].y]=1;
		  	que.push(v[j]);
		  	vis[v[j].x][v[j].y]=1;
		  	int t=bfs();
	    	if(t!=-1) ans=min(ans,t);
	}
     if(ans==INF) printf("Case %d: -1\n",k);
     else printf("Case %d: %d\n",k,ans);
}
return 0;
}

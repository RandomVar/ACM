#include<bits/stdc++.h>
using namespace std;
struct node{
	int z,x,y;
};
int vis[2][12][12];
string s[2][12];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,m,t;
void bfs(int sz,int sx,int sy){
  queue<node>que;
  memset(vis,0,sizeof(vis));
  que.push(node{sz,sx,sy});
  vis[sz][sx][sy]=1;
  while(!que.empty()){
  	node e=que.front();que.pop();
  	int tz=e.z;int tx=e.x;int ty=e.y;
  	//cout<<tz<<tx<<ty<<endl;
  	if(s[tz][tx][ty]=='P') {
  		printf("YES\n");return;
	  }
	else if(s[tz][tx][ty]=='#') {
		if(!vis[~tz][tx][ty]){
	       vis[~tz][tx][ty]=1;
		  que.push(node{~tz,tx,ty});
	}}
	else if(s[tz][tx][ty]=='.'||s[tz][tx][ty]=='S'){
		for(int i=0;i<4;i++){
			int ax=tx+dx[i];int ay=ty+dy[i];
			if(ax>=0&&ax<n&&ay>=0&&ay<m&&!vis[tz][ax][ay]) 
			 { vis[tz][ax][ay]=1;
			que.push(node{tz,ax,ay});
		}
	}
  }}
  printf("NO\n");return;
}

int main(){
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d%d%d",&n,&m,&t);
	for(int k=0;k<2;k++)
		for(int i=0;i<n;i++)
		  cin>>s[k][i];
	for(int k=0;k<2;k++)
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(s[k][i][j]=='S') {
	    			bfs(k,i,j);break;
				}
			}
		} 
	}
} 

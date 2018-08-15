#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f;
int m[10][10];
int d[10][10];
int sx,sy;
int zx,zy;
char f[40];
char a[4]={'E','N','W','S'};
int dx[4]={1,0,0,-1};int dy[4]={0,1,-1,0};
int bfs(){
	queue<P>que;
    que.push(P(sx,sy));
    d[sx][sy]=0;
    int k=0;
	while(que.size()){
		P p=que.front();
		que.pop();
		if(p.first==zx&&p.second==zy) break;
		for(int i=0;i<4;i++){
			int nx=p.first+dx[i];int ny=p.second+dy[i];
			if(nx>=0&&ny>=0&&nx<=6&&ny<=6&&m[nx][ny]==0&&d[nx][ny]==INF) {
				que.push(P(nx,ny));d[nx][ny]=d[p.first][p.second]+1;
			} 
		}
	}
	return d[zx][zy];	
}
int main(){
	while(1){
		memset(m,0,sizeof(m));
		for(int i=0;i<10;i++)
		  for(int j=0;j<10;j++)
		    d[i][j]=INF;
		cin>>sx>>sy;
		if(sx==0&&sy==0) break;
		cin>>zx>>zy;
		int k=3;
		while(k--){
		int i,j,x,y;
		cin>>x>>y>>i>>j;
		if(y==j)
			for(int t=x;t<=i;t++) m[t][j]=1;
		if(x==i) 
		    for(int t=y;t<=j;t++) m[i][t]=1;
	}
	for(int i=0;i<=6;i++){
	  for(int j=0;j<=6;j++)
	    cout<<m[i][j];
	    cout<<endl;}
    	cout<<bfs()<<endl;
}}

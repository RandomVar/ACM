#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int par[1005];
int find(int x){
	return par[x]==x?x:x=find(par[x]);
}
void unit(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	par[x]=y;
}
int main(){
	int n,m;
	while(cin>>n&&n!=0){
		cin>>m;
		for(int i=1;i<=n;i++)
		  par[i]=i;
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			unit(u,v);
		}
		int cnt=0;
		for(int i=1;i<=n;i++) 
		  if(par[i]==i) cnt++;
		cout<<cnt-1<<endl;
	}
	return 0;
}

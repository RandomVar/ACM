#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int IN[1005];//Èë¶È 
int PAIR[1005];
int find(int x){
	return PAIR[x]==x?x:PAIR[x]=find(PAIR[x]);
}

void unit(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  PAIR[x]=y;	
}

int main(){
	int n,m;
	while(cin>>n&&n!=0){
		cin>>m;
		memset(IN,0,sizeof(IN));
		for(int i=1;i<=n;i++){
            PAIR[i]=i; 
        }
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			unit(u,v);
			IN[u]++;IN[v]++;
		}
	
		int flag=1;
		int temp=find(1);
		for(int i=1;i<=n;i++){
		  if(IN[i]&1) {flag=0;break;}
		  if(temp!=find(i)) {flag=0;break;}
	}
	printf("%d\n",flag);
} 
return 0;
}

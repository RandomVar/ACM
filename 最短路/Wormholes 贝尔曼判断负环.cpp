//±´¶ûÂüÅĞ¶Ï¸º»· 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
typedef struct node{
	int s,e,t;
};node edge[6000]; 
int d[510];
int n,E,w,m;
int find_nl(){
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=E;j++){
			node e=edge[j];
			if(d[e.e]>d[e.s]+e.t){
				d[e.e]=d[e.s]+e.t;
			if(i==n) return 1;
		}
	}}
	return 0;
}
int main(){
	int f;cin>>f;
	while(f--){
		E=1;
		cin>>n>>m>>w;
		for(int i=1;i<=m;i++){
			cin>>edge[E].s>>edge[E].e>>edge[E].t;
			E++;
			edge[E].s=edge[E-1].e;
			edge[E].e=edge[E-1].s;
			edge[E].t=edge[E-1].t;
			E++;
		}
		for(int i=m+1;i<=m+w;i++){
			int t;
			cin>>edge[E].s>>edge[E].e>>t;
			edge[E].t=-t;
			E++;
		} 
		E--;
	if(find_nl()==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
	}
}

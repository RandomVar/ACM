#include<iostream>
#include<cstdio> 
#include<vector>
#include<cstring>
using namespace std;
vector<int>G[505];
int ans[505];
int deg[505];//表示入度 
int n,m;
void topsort(){
  for(int i=0;i<n;i++){
  	for(int j=1;j<=n;j++){
  		if(deg[j]==0){
  			ans[i]=j;
  			deg[j]--;
  			for(int k=0;k<G[j].size();k++)
  			  deg[G[j][k]]--;
  			  break;
		  }
	  }
  }	
}

int main(){
  while(cin>>n>>m){
  	memset(deg,0,sizeof(deg));
  	for(int i=0;i<505;i++)
  	  G[i].clear();
  	 for(int i=0;i<m;i++){
  	 	int u,v;
  	 	cin>>u>>v;
  	 	deg[v]++;
  	 	G[u].push_back(v);
	   }
	   topsort();
	   for(int i=0;i<n-1;i++)
	     cout<<ans[i]<<" ";
	    cout<<ans[n-1]<<endl;
  }
  return 0;} 

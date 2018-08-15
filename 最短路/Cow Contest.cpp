#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int map[110][110];
int main(){
	int n,m;
	while(cin>>n>>m){
		memset(map,0,sizeof(map));
		for(int i=1;i<=m;i++)
		  { int a,b;
		    cin>>a>>b;
		    map[a][b]=1;}
		for(int k=1;k<=n;k++)
		  for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++)
		      if(map[i][k]&&map[k][j])
		        map[i][j]=1;
		int ans=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n;j++)
			  if(map[i][j]||map[j][i]) sum++;
			 if(sum==n-1) {
			 ans++;} 
		}
		cout<<ans<<endl;
	}
} 

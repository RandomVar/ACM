#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
struct node{
	int x,y;
}g[16];
int dp[1<<16];
struct rec{
	int cover;
	int area;
};
bool isin(int i, int j, int k)
{
    return ((g[i].x - g[k].x) * (g[j].x - g[k].x) <= 0) && ((g[i].y - g[k].y) * (g[j].y - g[k].y) <= 0);
}
 
int main(){
	int n;
	while(cin>>n&&n){
		for(int i=0;i<n;i++){
			cin>>g[i].x>>g[i].y;
		}
		vector<rec>v; 
		for(int i=0;i<n;i++)
		  for(int j=i+1;j<n;j++){
		  	rec r;
			r.cover=1<<i|1<<j;
			r.area=(max((abs)(g[i].x-g[j].x),1)*(max((abs)(g[i].y-g[j].y),1)));
		  	for(int k=i;k<j;k++){
		  	  if(isin(i,j,k))
		  	    r.cover|=1<<k;
			  }
			v.push_back(r);
		  }
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<v.size();i++)
		  for(int s=0;s<(1<<n);s++){
	        int ns=s|v[i].cover;
	      if(dp[s]!=INF&&ns!=s)
		    dp[ns]=min(dp[ns],dp[s]+v[i].area);
	}
	cout<<dp[(1<<n)-1]<<endl;
	}
	return 0;
}

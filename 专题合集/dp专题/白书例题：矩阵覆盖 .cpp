#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int map[20][20];
int next[1<<20];
int cnt[1<<20];
int main(){
	int n;
	while(cin>>n&&n){
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    cin>>map[i][j];//0²»ÄÜ±»¸²¸Ç 
		cnt[1]=0;next[1]=0;
		for(int i=n;i>0;i--)
		  for(int j=n;j>0;j--){
		  	for(int s=1;s<1<<(n+1);s++){
		  		if(s>>(j&1)||!map[i][j])
		  		  next[s]=cnt[s&~(1<<j)];
			  else{
			  	int ans=0;
			  	if(j+1<=n&&!(s&~(1<<(j+1)))&&map[i][j+1])
			  	  ans+=cnt[s|1<<(j+1)];
			  	if(i+1<=n&&map[i+1][j])
			  	  ans+=cnt[s|1<<j];
			  	next[s]=ans;
			  }
			  }
			  swap(next,cnt);
			  }
			cout<<cnt[0]<<endl; 
		  }
	}

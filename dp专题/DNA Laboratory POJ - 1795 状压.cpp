#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int dp[1<<16][16];
int cost[16][16]; 
string a[16];
int len[16];
int r[1<<16][16];
int main(){
	int t;cin>>t;int k=0;
	while(t--){
		k++;
		int n;
		cin>>n;
		memset(r,0,sizeof(r));
		for(int i=0;i<n;i++)
		  cin>>a[i];
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++){
		  	if(i!=j&&a[i].find(a[j])!=string::npos)
		  	   a[j]=a[i];
		  }
		sort(a,a+n);
		n=unique(a,a+n)-a;
	//	cout<<n<<endl;
		for(int i=0;i<n;i++)
		  len[i]=a[i].size();
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++){
		  	for(int l=0;l<=min(len[i],len[j]);l++)
		  	  if(a[i].substr(len[i]-l)==a[j].substr(0,l))
		  	    cost[i][j]=len[j]-l;//j接到i的后面 
		  }
		 // cout<<cost[2][1]<<endl;
		memset(dp,0x3f,sizeof(dp));
		//memset(dp[0],0,sizeof(dp[0]));
	    for(int i=0;i<n;i++)
	      dp[1<<i][i]=len[i];
		for(int s=0;s<(1<<n);s++)
		 for(int j=0;j<n;j++){
		   	if(s&(1<<j)){
		  for(int i=0;i<n;i++){
		    if((s&(1<<i))==0){
		  	 dp[s|(1<<i)][i]=min(dp[s|(1<<i)][i],dp[s][j]+cost[j][i]);
		  }}}}
		int ans=INF;
		  for(int i=0;i<n;i++)
		    ans=min(ans,dp[(1<<n)-1][i]);
		//cout<<ans<<endl;
		for(int i=0;i<n;i++) 
	       if(dp[(1<<n)-1][i]==ans) r[(1<<n)-1][i]=1;
	    for(int s=(1<<n)-1;s>=0;s--){
	    	for(int i=0;i<n;i++){
	    		if(r[s][i]){
	    			for(int j=0;j<n;j++){
	    				if(i!=j&&(s&(1<<j)))
	    				r[s&~(1<<i)][j]|=(dp[s&~(1<<i)][j]+cost[j][i]==dp[s][i]);
					}
				}
			}
		}
	   	string res=string(1,'z'+1);
	   	int last;
	   	//cout<<n<<endl; 
	   	for(int i=0;i<n;i++){
	   		if(r[1<<i][i]&&(res>a[i])){
	   		  res=a[i];last=i;
		   }}
		//cout<<last<<endl;
		int app=1<<last;
		for(int u=0;u<n-1;u++){
			string tail=string(1,'z'+1);
			int key;
			for(int i=0;i<n;i++){
				if(!(app&(1<<i))){
			      if(r[app|(1<<i)][i]&&(dp[app|(1<<i)][i]==dp[app][last]+cost[last][i])&&tail>a[i].substr(len[i]-cost[last][i])){
				  
			      key=i;tail=a[i].substr(len[i]-cost[last][i]);
				  }}}  
			last=key;
			//cout<<tail<<endl;
			app|=1<<key;
			res+=tail;
		}
		printf("Scenario #%d:\n%s\n\n", k, res.c_str());
	}
}

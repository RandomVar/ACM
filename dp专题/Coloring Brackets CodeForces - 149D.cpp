#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long MOD=1000000007;
ll dp[750][750][4][4];
int g[750];
void dfs(int u,int v){
	if(u+1==v) {
	dp[u][v][0][1]=dp[u][v][0][2]=dp[u][v][1][0]=dp[u][v][2][0]=1;
	return;}
	if(g[u]==g[v]){
		dfs(u+1,v-1);
		for(int i=0;i<3;i++)
		  for(int j=0;j<3;j++){
		  if(j!=1) dp[u][v][0][1]=(dp[u][v][0][1]+dp[u+1][v-1][i][j])%MOD;
		  if(j!=2) dp[u][v][0][2]=(dp[u][v][0][2]+dp[u+1][v-1][i][j])%MOD;
		  if(i!=1) dp[u][v][1][0]=(dp[u][v][1][0]+dp[u+1][v-1][i][j])%MOD;
		  if(i!=2) dp[u][v][2][0]=(dp[u][v][2][0]+dp[u+1][v-1][i][j])%MOD;
		  }
	}
   else{
   	dfs(u,g[u]);
   	dfs(g[u]+1,v);
   	for(int i=0;i<3;i++)
   	  for(int j=0;j<3;j++)
   	    for(int t=0;t<3;t++)
   	      for(int p=0;p<3;p++){
   	      	if(t==0||t!=p)
   	      	dp[u][v][i][j]=(dp[u][v][i][j]+(dp[u][g[u]][i][t]*dp[g[u]+1][v][p][j])%MOD)%MOD;
			 }
   }
}
int main(){
	string s;
	while(getline(cin,s)){
		int len=s.size();
		stack<int>st;
	  for(int i=0;i<len;i++){
	  	if(s[i]==')') {
		  int t=st.top();st.pop();
		  g[t]=i;g[i]=i;
	  }
	  else  st.push(i);
	}
	memset(dp,0,sizeof(dp));
	dfs(0,len-1);
	ll ans=0;
		for(int i=0;i<3;i++)
		  for(int j=0;j<3;j++){
		  	ans=(ans+dp[0][len-1][i][j])%MOD;
		  }
		cout<<ans<<endl;}}
	

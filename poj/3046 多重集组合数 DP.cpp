/*多重集组合数-DP
http://blog.csdn.net/viphong/article/details/48110525
dp[i][j]  表示前i种物品,一共拿了j个物品的方法数
if(j >a[i] )
dp[i+1][j] = (dp[i][j] + dp[i+1][j-1] - dp[i][j-1-a[i]] +M)%M;
else{
dp[i+1][j] = dp[i][j] + dp[i+1][j-1]; 
}
 */
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
const int M=1000000;
int dp[2][100100];
int x[1010];
int main(){
	int t,a,s,b;
	while(cin>>t>>a>>s>>b){
		memset(x,0,sizeof(x));
		for(int i=0;i<a;i++){
			int u;cin>>u;
			x[u]++;
		}
		for(int i=0;i<=1;i++)
		 dp[i][0]=1;
		for(int i=0;i<t;i++)
		  for(int j=1;j<=b;j++){
		  	if(j-x[i+1]-1>=0)
         dp[(i+1)&1][j] = (dp[i&1][j] + dp[(i+1)&1][j-1] - dp[i&1][j-1-x[i+1]] +M)%M;
          else
           dp[(i+1)&1][j] = (dp[i&1][j] + dp[(i+1)&1][j-1]+M)%M; 
		  }
		  int ans=0;
		    for(int i=s;i<=b;i++)
		      ans=(dp[t&1][i]+ans)%M;
		    cout<<ans<<endl;
	}
} 

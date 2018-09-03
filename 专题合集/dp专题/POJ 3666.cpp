/* dp[i][j]前i个元素，以第j小的结尾
dp[i][j]=min dp[i-1][k] +abs(a[i]-b[j]) b为重排后的数组 
*/ 
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
ll a[2010];
ll p[2010];
ll dp[2010][2010];
ll aabs(ll a){
	if(a<0) return -a;
	return a;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	  { cin>>a[i];p[i]=a[i];}
	sort(p+1,p+1+n);
	ll ans=1e9;
	for(int i=1;i<=n;i++)
	  dp[1][i]=aabs(a[1]-p[i]);
	for(int i=2;i<=n;i++){
		ll mmin=dp[i-1][1];
		for(int j=1;j<=n;j++){
			dp[i][j]=mmin+aabs(a[i]-p[j]);
			if(mmin>dp[i-1][j+1]) mmin=dp[i-1][j+1];
		}
	}
	for(int j=1;j<=n;j++){
		ans=min(ans,dp[n][j]);
	}
	cout<<ans<<endl;
}

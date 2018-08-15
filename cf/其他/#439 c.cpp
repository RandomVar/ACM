#include<iostream>
#define ll long long
using namespace std;
const int maxn=5000;
const ll MOD=998244353;
ll pre[maxn][maxn];
ll p[maxn];
void init(){
	pre[0][0]=1;
	for(int i=1;i<=maxn;i++){
	pre[i][0]=1;
	  for(int j=1;j<=i;j++)
	    pre[i][j]=(pre[i-1][j-1]+pre[i-1][j])%MOD;
}}
void prep(){
	p[0]=1; 
	for(int i=1;i<=maxn;i++)
	  p[i]=(p[i-1]*i)%MOD;
}
ll solve(int x,int y){
	ll res=0;
	for(int i=0;i<=x&&i<=y;i++){
		ll ans=p[i];
		ans=(ans*pre[x][i])%MOD;
		ans=(ans*pre[y][i])%MOD;
		res=(res+ans)%MOD; 
	}
	return res;
}
int main(){
	int a,b,c;
	init();
	prep();
	while(cin>>a>>b>>c){
		ll ans=1;
		ans=(ans*solve(a,b))%MOD;
		//cout<<ans<<endl;
		ans=(ans*solve(a,c))%MOD;
		//cout<<ans<<endl;
		ans=(ans*solve(b,c))%MOD;
		cout<<ans<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[40010];
int a[50];
ll quickmod(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int n;double p;
    scanf("%d%lf",&n,&p);
    int s=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        s+=a[i];}
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++)
      for(int j=s;j>=a[i];j--){
         dp[j]+=dp[j-a[i]];
    }
    double cnt=1.0*quickmod(2,n)*p;
    int index=-1;
    ll ans=0;
    for(int j=0;j<=s;j++){
        ans+=dp[j];
        if((double)ans>=cnt) {index=j;break;}
    }
    printf("%d\n",index);
  }
return 0;

}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
/* 素数筛选
 prime数组存小于等于MAXN的素数 prime[0] 存的是素数的个数 */
const int MAXN=100000;
int prime[MAXN+1];
ll a[100];
ll l,r,x,y;
void getPrime() {
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++) {
            if(!prime[i])
                prime[++prime[0]]=i;
    for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)  {
          prime[prime[j]*i]=1;
    if(i%prime[j]==0) break;
      } } }
//factor[0]中存质因数 factor[1]中存质因数的个数
long long factor[100][2];
int fatCnt;
int getFactors(long long x) {
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++) {
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0){
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0){
            factor[fatCnt][1]++;
            tmp/=prime[i]; }
            fatCnt++;
        } }
       if(tmp!=1)  {
         factor[fatCnt][0]=tmp;
         factor[fatCnt++][1]=1; }
         return fatCnt;
    }
ll dfs(ll ans,int i,int n){
    ll cnt=0;
   // cout<<ans<<endl;
  if(i==n&&ans*x>=l&&ans*x<=r&&y/ans>=l&&y/ans<=r) {return 1;}
  if(i+1<=n)  cnt+=dfs(ans,i+1,n);
    ans*=a[i];
  if(i+1<=n) cnt+=dfs(ans,i+1,n);
return cnt;
}

ll quickm(ll a,ll b){
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
 // ll l,r,x,y;
  getPrime();
  while(cin>>l>>r>>x>>y){
     if(y%x) cout<<0<<endl;
     else{
      ll d=y/x;
      int cnt=getFactors(d);
      for(int i=0;i<cnt;i++){
         a[i]=quickm(factor[i][0],factor[i][1]);
        // cout<<a[i]<<endl;
      }
      cout<<dfs(1,0,cnt)<<endl;
  }
  }
return 0;
}

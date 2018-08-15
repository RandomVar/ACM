#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll quickmod(ll a,ll b,ll c){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a%c;
		a=a*a%c;
		b>>=1;
	}
	return res;
}

int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n,k,p;
  while(scanf("%lld%lld%lld",&n,&k,&p)==3){

       /* ll x=quickmod(2,n,p);
        ll ans=quickmod(2,x-n,p);
       if(k==0) printf("%lld\n",ans-1);
       else printf("%lld\n",ans);*/
       if(p!=2){
        ll a=n%(p-1);
        ll b=quickmod(2,a,p);
        ll x=(b-n+p)%p;
        ll y=x%(p-1);
        ll ans=quickmod(2,y,p);
        if(k==0) printf("%lld\n",ans-1);
       else printf("%lld\n",ans);
       }
       else {
          if(k==0) printf("1\n");
          else printf("0\n");

       }
  }

return 0;
}
/*
long long cnt[100000];
int n;

void dfs(int u,int ans){
 cnt[ans^u]++;
 if(u==(pow(2,n)-1)) return;
  dfs(u+1,ans^u);
  dfs(u+1,ans);

}
int main(){
  //int n,k;
  while(cin>>n){
        memset(cnt,0,sizeof(cnt));
    dfs(0,0);
    for(int i=0;i<pow(2,n);i++)
        cout<<i<<": "<<cnt[i]<<endl;
  }


}*/

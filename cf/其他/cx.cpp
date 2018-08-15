#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
ll cnt[40];
ll m[40];
ll c[40];
ll w[40];
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
  int n,l;
  while(cin>>n>>l){

    for(int i=0;i<n;i++){
        cin>>c[i];
        if(i==0) w[i]=1;
        else w[i]=w[i-1]*2;
        //if(w[i]>l) t=i;
  }
  memset(cnt,0,sizeof(cnt));
  memset(m,0x3f,sizeof(m));
  int t=n;int lx=l;int e=n;
  while(1){
    for(int i=0;i<e;i++)
      if(w[i]>lx) t=i;
    //int m=INF;
    if(t<e){
        for(int i=t;i<e;i++)
            m[e]=min(m[e],c[i]);
    }
    ll ans=INF;
    for(int i=t-1;i>=0;i--)
        ans=min(ans,c[i]*lx/w[i]);
    if(m[e]<=ans) {cnt[e]=cnt[e+1]+m[e];break;}
    else {cnt[e]=cnt[e+1]+ans;
      for(int x=n;x>e;x--)
        if(cnt[e]>=cnt[x]+m[x]) break; }
    //if(t==e) break;
    lx=l-w[t-1];e--;}
   cout<<cnt[e]<<endl;

  }
  }

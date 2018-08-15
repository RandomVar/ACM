#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
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
        int t=-1;
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(i==0) w[i]=1;
        else w[i]=w[i-1]*2;
        if(w[i]>l) t=i;
  }
    int m=INF;
    if(t!=-1) {
        for(int i=t;i<n;i++)
            m=min(m,c[i]);
    }

    ll ans=INF;
    for(int i=t-1;i>=0;i--)
        ans=min(ans,c[i]*quickmod(2,t-i-1));
  }
      anz+=ans;
  }

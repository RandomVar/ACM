#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=1e18;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=2*1e5;
ll powm(int a,int b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
struct node{
  ll d,h;
  bool operator<(const node& b)const{
  return h-d>b.h-b.d;
  }
}x[maxn+10];
int main(){
  int n,a,b;
  while(cin>>n>>a>>b){
        for(int i=0;i<n;i++){
            cin>>x[i].h>>x[i].d;
        }
        ll chushu=0;
        ll ans=0;int index=-1;
    if(a&&b){
       for(int i=0;i<n;i++){
          ll cnt=x[i].h*powm(2,a)-x[i].d;
          if(ans<cnt){ans=cnt;index=i;}
       }
         if(ans){
                chushu+=ans+x[index].d;
                x[index].h=-INF;
                  b--;}
    }
    //cout<<chushu<<endl;
    int ii=0;
    sort(x,x+n);
    if(b){
        while(b){
          if(x[ii].h<x[ii].d) break;
            chushu+=x[ii].h;
            ii++;b--;
        }}
       // cout<<ii<<endl;
        for(;ii<n;ii++)
          if(x[ii].h!=-INF)  chushu+=x[ii].d;
     cout<<chushu<<endl;
  }
}

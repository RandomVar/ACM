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
const int INF=0x3f3f3f3f;
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
       int index=-1;
     sort(x,x+n);
    for(int i=0;i<n;i++)
        chushu+=x[i].d;
     if(b){
        int ii=0;

        while(b){
          if(x[ii].h<x[ii].d) break;
            chushu+=x[ii].h-x[ii].d;
            ii++;b--;
        }
        if(a){
            ll ans1=0;ll ans2=0;
            ll ans=0;
            for(int i=0;i<ii;i++){
              ll cnt=x[i].h*powm(2,a)-x[i].d;
                  if(ans<cnt){ans=cnt;index=i;}
                 }
            if(index!=-1){
              ans1=ans-x[index].h+x[index].d;
            }
            ans=0;
            index=-1;
            for(int i=ii;i<n;i++){
                ll cnt=x[i].h*powm(2,a)-x[i].d;
                  if(ans<cnt){ans=cnt;index=i;}
            }
            if(index!=-1){
                 if(b) ans2=ans;
                 else ans2=ans-x[ii-1].h+x[ii-1].d;
              }
             chushu+=max(ans1,ans2);
        }}



     cout<<chushu<<endl;
  }
}

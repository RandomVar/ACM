#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
vector<int>v;

/****¿ìËÙÃÝ****/
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
bool check(int x){
  while(x){
    if(x%10==7) return 1;
    x/=10;
  }
  return 0;
}
void init(){
 /* for(int i=6;i>=0;i--)
  {
      int len=quickmod(10,i);
      int x=7*len;
      for(int j=x;j<x+len;j++)
        for(int t=;t<=;t+=len*10)
        v.pb(j);
      for(int j=x;j<=5000000;j+=len)
        v.pb(j);
  }*/
  //cout<<1<<endl;
 // for(int i=7;i<=5000000;i+=7)
   // v.pb(i);
   for(int i=7;i<=15000000;i++){
      if(i%7==0||check(i))
          v.pb(i);
   }
 //sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  init();
  int m,n;
  for(int i=0;i<100;i++)
    cout<<v[i]<<" ";
  while(cin>>m>>n){

      int p=upper_bound(v.begin(),v.end(),m)-v.begin();
      p+=n-1;
      cout<<v[p]<<endl;

  }


  }


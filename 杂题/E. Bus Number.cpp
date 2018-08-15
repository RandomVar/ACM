#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
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
int sum[15];
int a[15];
ll jc[20];
ll cnt;
void dfs(int x){

 if(x==10){
    int a1=0;ll a2=1;
  for(int i=0;i<10;i++){
      if(a[i]){
         a1+=a[i];
         a2*=jc[a[i]];
      }
  }
  ll ans=jc[a1]/a2;
  //cout<<ans<<endl;
  if(a[0]){
     a1-=1;
     a2=a2/jc[a[0]]*jc[a[0]-1];
     ans-=jc[a1]/a2;
  }
  cnt+=ans;
  return ;
 }

  for(int i=1;i<=sum[x];i++){
      a[x]=i;
      dfs(x+1);
  }
  if(sum[x]==0) dfs(x+1);
  //cout<<ans<<endl;
}

void init(){
 jc[0]=1;
  for(int i=1;i<20;i++)
    jc[i]=jc[i-1]*i;

}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n;
  init();
  while(cin>>n){
      ll x=n;
      mem(sum,0);
      mem(a,0);
      while(x){
        sum[x%10]++;
        x/=10;
      }
      cnt=0;
      dfs(0);
      cout<<cnt<<endl;

  }


}

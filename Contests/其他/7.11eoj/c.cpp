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
const int maxn=1e6+100;
struct node{
  ll w,y;
  bool operator<(const node &b) const{
      if(y>=0&&b.y>=0)
        return w<b.w;
      if(y>=0&&b.y<0)
        return 1;
      if(y<0&&b.y>=0)
      return 0;
      return w>b.w;
  
  }
}a[maxn];
int n;
int check(ll x){
    ll c=x;
    for(int i=1;i<=n;i++)
{  
   if(c>=a[i].w)  c+=a[i].y; 
  else return 0;
}
return 1;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  while(cin>>n)
  {
      for(int i=1;i<=n;i++)
      {
          cin>>a[i].w>>a[i].y;
      }
      sort(a+1,a+1+n);
      ///for(int i=1;i<=n;i++)
      // cout<<a[i].w<<" "<<a[i].y<<endl;
      ll l=0;ll r=1e18;
      while(l<=r)
      {
        ll mid=(l+r)/2;
        if(check(mid))
          r=mid-1;
        else l=mid+1;

      }
      cout<<l<<endl;
  }
  
return 0;
  }


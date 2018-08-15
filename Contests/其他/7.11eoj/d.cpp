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
const int maxn=3*1e5+100;
ll a[maxn];
ll cnt[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k)
  {
     // map<double,int>cnt;
      ll sum=0;
      ll sumi=0;
      ll mi=0;
      mem(cnt,0);
      ll ans=0;
      for(int i=1;i<=n;i++)
      {
          cin>>a[i];
          int x=a[i]+k*((n+1)/2-i);
          cnt[x]++;
          sum+=x;
      }
      ll daan=INF;
      if(n%2==0) sum+=k*1.0/2*n;
      for(int i=0;i<=1e4;i++)
     {
         int x=i;
         if(n%2==0) x=i+k*0.5;
       ll ans=(sum-sumi)-x*(n-mi)+x*mi-sumi;
        mi+=cnt[i];
        sumi+=cnt[i]*x;
        daan=min(ans,daan);
        //cout<<i<<" "<<ans<<endl;
     }
     cout<<daan<<endl;
  }

return 0;
  }


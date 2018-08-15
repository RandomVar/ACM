#include<bits/stdc++.h>
#define ll long long
const ll INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
ll dp[3010];
struct node{
  ll x,c;
  bool operator<(const node &b)const{
  return x<b.x;
  }
}a[3010];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
        memset(dp,0x3f,sizeof(dp));
      for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].c;
      sort(a+1,a+1+n);
      dp[1]=a[1].c;
      ll cnt=0;
      for(int i=2;i<=n;i++)
     {
         cnt=0;
        for(int j=i-1;j>=1;j--){
             cnt+=(a[j+1].x-a[j].x)*(i-j-1);
           dp[i]=min(dp[i],dp[j]+cnt+a[i].c);
     }
     }
     ll ans=INF;
    // for(int i=1;i<=n;i++)
      // cout<<dp[i]<<" ";
     for(int i=1;i<=n;i++){
         ll cnt=0;
       for(int k=i+1;k<=n;k++)
           cnt+=a[k].x-a[i].x;
        ans=min(ans,dp[i]+cnt);
     }
     cout<<ans<<endl;
  }

return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int a[maxn];
int t[maxn];
ll sum[maxn];
int main(){
  int n,k;
  cin>>n>>k;
  ll cnt=0;
  for(int i=1;i<=n;i++){
        cin>>a[i];
        }
    sum[0]=0;
  for(int i=1;i<=n;i++){
       cin>>t[i];
       if(t[i]==1) cnt+=a[i];
  }
  for(int i=1;i<=n;i++){
        sum[i]=sum[i-1];
    if(t[i]==0) sum[i]+=a[i];
  }
  ll ans=0;
   for(int i=1;i<=n-k+1;i++){
      ans=max(sum[i+k-1]-sum[i-1],ans);
   }
   cout<<ans+cnt<<endl;
}

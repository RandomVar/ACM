#include<bits/stdc++.h>
using namespace std;
int cnt[1010];
int main(){
    memset(cnt,0,sizeof(cnt));
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++)
   {
       int t;
       cin>>t;
       cnt[t]++;
   }
   int ans=m;
   for(int i=1;i<=n;i++){
      ans=min(ans,cnt[i]);
   }
   cout<<ans<<endl;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int a[maxn][25];
ll cnt[25];
int main(){
   int t;
   //cin>>t;
   scanf("%d",&t);
   while(t--){
     int n;
     scanf("%d",&n);
     //cin>>n;
     memset(a,0,sizeof(a));
     memset(cnt,0,sizeof(cnt));
     for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        int j=0;
        while(x)
        {
         a[i][j]=x%2;
         x/=2;
         j++;
       }
     }
    for(int j=0;j<=20;j++){
        int i=1;ll ans=0;
        while(i<=n){
            if(a[i][j]==1) {ans++;}
            else if(ans){
                cnt[j]+=(ans+1)*ans/2;
               ans=0;
            }
            i++;
        }
        if(ans) cnt[j]+=(ans+1)*ans/2;
    }
    ll ans=0;
  for(int i=0;i<=20;i++)
     ans+=cnt[i]*((ll)1<<i);

   printf("%lld\n",ans);
   }

return 0;
}

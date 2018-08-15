#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+100;
int c[maxn];
int pre[maxn];
int dp[maxn];
int main(){
   int t;//cin>>t;
   scanf("%d",&t);
   while(t--){
    int n;
    //cin>>n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       // cin>>c[i];
      scanf("%d",&c[i]);
    }
    memset(pre,0x3f,sizeof(pre));
    pre[c[1]]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(pre[c[i]]+1,dp[i-1]+1);
        pre[c[i]]=dp[i];

    }
    printf("%d\n",dp[n]);
    //cout<<dp[n]<<endl;
   }

return 0;
}

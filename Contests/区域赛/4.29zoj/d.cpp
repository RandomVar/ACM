#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
ll val[1010];
int n;
char s[1010];
ll sum[1010];
int a[1010];
ll dp[1010][1010];
ll v[1010];
int main(){
   // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;

 scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
        scanf("%lld",&val[i]);
        int cnt=0;int k=0;
    sum[0]=0;
    for(int i=0;i<n;i++){
        if(s[i]==')') {cnt++;sum[cnt]=sum[cnt-1]+val[i];}
        if(s[i]=='(') {v[k]=val[i];a[k++]=cnt;}
    }
    memset(dp,0,sizeof(dp));

    for(int i=k-1;i>=0;i--){
            dp[i][cnt+1]=-INF;
        for(int j=cnt;j>=a[i];j--)
            dp[i][j]=max(dp[i][j+1],v[i]*(sum[j]-sum[a[i]])+dp[i+1][j]);//移到的位置>=j时最多的收获
        for(int j=a[i]-1;j>=0;j--)
            dp[i][j]=dp[i][j+1];
    }
    ll ans=0;
    for(int j=a[0];j<=cnt;j++)
        ans=max(ans,dp[0][j]);
    printf("%lld\n",ans);
    //cout<<ans<<endl;
  }
return 0;
}

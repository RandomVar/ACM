#include<bits/stdc++.h>
using namespace std;
int dp[1010][110];
int a[110];
int b[110];
int v[110],c[110];
int main(){
 int t;
 cin>>t;
 while(t--){
    int n,V,k;
    cin>>n>>V>>k;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    memset(dp,0,sizeof(dp));
   for(int i=1;i<=n;i++)
    for(int s=V;s>=c[i];s--){
      for(int j=1;j<=k;j++){
        a[j]=dp[s-c[i]][j]+v[i];
        b[j]=dp[s][j];
   }
    a[k+1]=b[k+1]=-1;
    int x=1,y=1,z=1;
    while(z<=k&&(x<=k||y<=k)){
        if(a[x]<b[y]){
            dp[s][z]=b[y];
            y++;
        }
        if(a[x]>=b[y]){
            dp[s][z]=a[x];
            x++;
        }
        if(z==1||dp[s][z]!=dp[s][z-1]){
            z++;
        }
    }}
    cout<<dp[V][k]<<endl;
   /*int m=0;
   for(int s=c[i];s<=V;s++){
     m=max(m,dp[n][s]);}
   for(int i=n;i>0;i--)
     for(int s=V;s>=c[i];s--){
      if(dp[i][s]==m){

      }
   }*/
 }}

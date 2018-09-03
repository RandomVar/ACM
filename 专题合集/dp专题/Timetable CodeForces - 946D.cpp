#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int INF=0x3f3f3f3f;
char c[maxn];
int dp[maxn];
int p[maxn];
int ans[maxn][maxn];
int main(){
  int n,m,k;
  while(cin>>n>>m>>k){
        int cnt=0;
        memset(dp,0x3f,sizeof(dp));
        //memset(ans,0x3f,sizeof(ans));
        dp[0]=0;
        //ans[0][0]=0;
    for(int i=0;i<n;i++){
        cin>>c;int top=0;
       for(int j=0;j<m;j++){
            if(c[j]=='1'){cnt++;
                    p[top++]=j;}}
        for(int j=0;j<top;j++)
           for(int k=j;k<top;k++)
                dp[k-j+1]=min(p[k]-p[j]+1,dp[k-j+1]);//ith days and has cur classes
    for(int j=0;j<=k;j++){
            ans[i+1][j]=(i+1)*m;
         for(int cur=min(j,cnt);cur>=0;cur--){
             ans[i+1][j]=min(ans[i+1][j],dp[cnt-cur]+ans[i][j-cur]);
    }
  }}

  cout<<ans[n][k]<<endl;
  }
}



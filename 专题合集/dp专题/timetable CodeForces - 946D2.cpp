#include<bits/stdc++.h>
using namespace std;
const int maxn=510;

char c[maxn][maxn];
int p[maxn];
int dp[maxn][maxn];
int ans[maxn];
int top[maxn];
int main(){
  int n,m,k;
  while(cin>>n>>m>>k){
        int cnt=0;
        memset(dp,0x3f,sizeof(dp));
        memset(top,0,sizeof(top));
    for(int i=0;i<n;i++){
        cin>>c[i];
       for(int j=0;j<m;j++){
            if(c[i][j]=='1'){
                int cur=0;
                cnt++;p[++top[i]]=j;}}
        for(int j=1;j<=top[i];j++)
            for(int k=j;k<=top[i];k++){
                    dp[i][k-j+1]=min(p[k]-p[j]+1,dp[i][k-j+1]);//ith days and has cur classes
                  }
           }
  //memset(ans,0x3f,sizeof(ans));
  for(int i=0;i<n;i++){
    dp[i][0]=0;
    //ans[i][0]=0;
    }

  /*int num=cnt-k;
  for(int i=0;i<n;i++)
    for(int j=0;j<=num;j++){
        if(i==0) ans[i][j]=dp[i][j];
  else{
    for(int cur=0;cur<=min(j,top[i]);cur++){
        ans[i][j]=min(ans[i][j],dp[i][cur]+ans[i-1][j-cur]);
    }
  }}*/
  for(int i=0;i<n;i++)
        for(int j=k;j>=0;j--)
            for(int p=0;p<=min(top[i],j);p++)
        {
            ans[j]=max(ans[j],ans[j-p]+dp[i][p]);
        }
  cout<<n*m-ans[k]<<endl;
  }}




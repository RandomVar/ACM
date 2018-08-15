#include <iostream>
#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1100][20];//i为车费，j为使用的个数，值为最小的数的值
int a[20];
int main(){
   int n,s;
   cin>>n>>s;
   int ma=0;
   for(int i=0;i<n;i++){
     cin>>a[i];
     ma=max(ma,a[i]);
     }
    // sort(a,a+n);
    memset(dp,0,sizeof(dp));
    for(int k=0;k<n;k++)
     for(int i=0;i<n;i++)
    for(int j=s+ma;j>=a[i];j--){

          dp[j][k+1]=max(dp[j][k+1],min(a[i],dp[j-a[i]][k]));
    }
    int ans=-1;
    for(int i=s;i<=s+ma;i++){
    for(int k=n;k>=0;k--){
        if(i-dp[i][k]<s) {
            ans=k;break;
        }
    }
    if(ans!=-1) break;}
    cout<<ans<<endl;
}


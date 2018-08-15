#include <iostream>
#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
   int n,s;
   cin>>n>>s;
   int ma=0;
   for(int i=0;i<n;i++){
     cin>>a[i];
     ma=max(ma,a[i]);
     }
    for(int i=0;i<n;i++)
    for(int j=s+ma;j>=a[i];j--){
      dp[j]=max(dp[j],dp[j-a[i]]+1);
    }
}

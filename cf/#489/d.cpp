#include<bits/stdc++.h>
#define ll long long
using namespace std;
void ST(int n) {

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
               dp[i][j] = dp[i][j - 1]+dp[i + (1 << (j - 1))][j - 1];
              if(pro[i][j - 1]!=-1&&pro[i + (1 << (j - 1))][j - 1]){
                   pro[i][j]= pro[i][j - 1]*pro[i + (1 << (j - 1))][j - 1];
                   if(pro[i][j]>dp[i][j]*k) pro[i][j]=-1;
              }
              else pro[i][j]=-1;

        }
    }
}
int RMQ1(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;

    return dp[l][k]+dp[r - (1 << k) + 1][k];
}
int RMQ2(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
     if(pro[l][k]==-1||pro[r - (1 << k) + 1][k]==-1) return -1;
    return pro[l][k]*pro[r - (1 << k) + 1][k];
}
int main(){
   int n,k;
   while(cin>>n>>k){
    for(int i=1;i<=n;i++){
        cin>>dp[i][1];
        pro[i][1]=dp[i][1];
    }
     ST(n);
     int r=1;
     for(int i=1;i<=n;i++){
        if(RMQ(1,r))
     }
   }

return 0;
}

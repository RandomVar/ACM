#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
 int dp[1300][1300];
 char s1[1300];
 char s2[1300];
void lcs(){
  memset(dp,0,sizeof(dp));
  int n=strlen(s1);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
  {

      if(i==0||j==0) {
            dp[i][j]=0;}
      else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
      else {dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
  }
}
int main(){

 while(cin>>s1){
        //getchar();
    //    cout<<s1<<endl;
     int k=0;
    for(int i=strlen(s1)-1;i>=0;i--){
        if(s1[i]>='A'&&s1[i]<='Z') s1[i]=s1[i]-('A'-'a');
        s2[k++]=s1[i];}
      //  cout<<s2<<endl;

        lcs();
         int n=strlen(s1);

    cout<<n-dp[n][n]<<endl;
 }
}

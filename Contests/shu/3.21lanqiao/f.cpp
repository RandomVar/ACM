#include<bits/stdc++.h>
#define ll long long
using namespace std;
int val[30]={258055, 69760, 163908, 249856, 53440,151684 ,77958, 176134, 8262 ,229446,245953 ,20676, 45189 ,69826, 131075,
28672,155717, 118851 ,221318, 254150,135235 ,86083 ,41089 ,28743, 32772,225475 ,118855 ,249862 ,184320 ,217154};
const int maxn=1e6+1e5;
int dp[maxn];
int main()
{
  freopen("f.out","w",stdout);
  int cnt=1048576;
  dp[0]=1;
  int ans=0;
  for(int i=0;i<30;i++)
  {
    for(int j=0;j<cnt;j++)
     if(dp[j]) 
     {
      //  cout<<j<<" "<<val[i]<<" "<<(j^val[i])<<endl;
       dp[j^val[i]]=1;
       ans=max(ans,j|val[i]);
     }
  }
  cout<<ans<<endl;
}
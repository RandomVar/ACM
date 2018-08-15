#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
     cin>>s+1;
     mem(dp1,0);
     for(int i=1;i<=n;i++)
     {
        for(int j=s[i]-'0';j<10;j++)
             dp1[i][j] =dp1[i-1][j]; 
         for(int j=0;j<s[i]-'0';j++)
               dp1[i][s[i]-'0']=max(dp1[i][s[i]-'0'],dp1[i-1][j]+1);

     }
   
     for(int i=n;i>=1;i--)
     {
         for(int j=9;j>=s[i]-'0';j--)
              dp2[i][s[i]-'0']=max(dp2[i][s[i]-'0'],dp2[i+1][j]+1);
             
         for(int j=s[i]-'0';j>=0;j--)
               dp2[i][j] = dp2[i+1][j];
     }
   
     for(int i=n;i>=1;i--)
     {
         for(int j=s[i]-'0';j<10;j++)
             dp3[i][j] =dp3[i+1][j]; 
         for(int j=0;j<s[i]-'0';j++)
               dp3[i][s[i]-'0']=max(dp3[i][s[i]-'0'],dp3[i+1][j]+1);
     }

     for(int i=n;i>=1;i--)//中间区间右端点位置要 >=i-1
     {
         for(int j=0;j<10;j++)//中间区间的左端点的值为j
         {
            for(int k=0;k<s[i]-'0';k++)
              {
              if(cnt[i][j][k]<=dp2[i][j]-dp3[i][s[i]-'0'])
              {
              cnt[i][j][k]=dp2[i][j]-dp3[i][s[i]-'0'];//中间区间的右端点>=k的
              b[i][j][k]=i-1;
              }
            if(cnt[i][j][k]<=cnt[i+1][j][k])
              {
              cnt[i][j][k]=cnt[i+1][j][k];//中间区间的右端点>=k的
              b[i][j][k]=b[i+1][j][k];
              }
              }
            for(int k=s[i]-'0';k<10;k++)
             {
                 if(cnt[i][j][k]<=dp2[i][j]-dp3[i][s[i]-'0']+1)
              {
              cnt[i][j][k]=dp2[i][j]-dp3[i][s[i]-'0']+1;//中间区间的右端点>=k的
              b[i][j][k]=i-1;
              }
            if(cnt[i][j][k]<=cnt[i+1][j][k])
              {
              cnt[i][j][k]=cnt[i+1][j][k];//中间区间的右端点>=k的
              b[i][j][k]=b[i+1][j][k];
             }
         }      
     //右端点的位置为i
     }
     }

     ll daan=0;
     int ii=0,jj=0;
     for(int i=1;i<=n;i++)
     {
         int k=a[i];//中间区间的左端点
         for(int c=0;c<=k;c++)//中间区间的右端点
         {
            
             ans=cnt[i+1][k][c]+dp1[i-1][c]+dp3[i][k];
              if(daaan<ans)
                 {
                   daan=ans;
                    ii=i;jj=b[i+1][k][c];
                }
         }
     }
     cout<<daan<<endl;
     cout<<ii<<" "<<jj<<endl;
 return 0;
  }

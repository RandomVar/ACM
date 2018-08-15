#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=2010;
string s[maxn];
int dp[maxn][maxn];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(cin>>n>>m)
   {
       mem(dp,0);
       int ans=0;
       for(int i=0;i<n;i++)
        cin>>s[i];
        for(int i=n/2;i>=1;i--)
          for(int j=m/2;j>=1;j--)
          {
              if(i==n/2&&j==m/2) {dp[i][j]=1;continue;}
              if(i==n/2&&dp[i][j+1])
              {
                  int k1=m/2-(j+1);int k2=m/2+j;
                  int x=0;
                  for(x=0;x<n/2;x++)
                  {
                      int x2=n-x-1;
                       if(s[x][k1]!=s[x][k2]) break;
                      if(s[x][k1]!=s[x2][k1]) break;
                      if(s[x][k2]!=s[x2][k2])  break;
                    
                  }
                  if(x==n/2) 
                  {
                      dp[i][j]=1;
                      cout<<i<<" "<<j<<endl;
                  }
                continue;
              }
              if(dp[i+1][j])
              {
                  int y=j;
                  int x1=n/2-(i+1);int x2=n/2+(i+1)-1;
                  for(y=j;y<m/2;y++)
                  {
                      int y2=n-y-1;
                     if(s[x1][y]!=s[x2][y]) break;
                     if(s[x2][y]!=s[x2][y2]) break;
                     if(s[x1][y]!=s[x1][y2]) break;
                  }
                  if(y==m/2) 
                  {
                      dp[i][j]=1;
                      if(j!=m/2) ans++;
                       cout<<i<<" "<<j<<endl;
                  }
                  //check();
              }
          }
          cout<<ans<<endl;
   }

 return 0;
  }

/*
4
6 8 
acbbbbca 
dcaccacd 
cdaddadc 
cdaddadc 
dcaccacd 
acbbbbca 
6 8 
acbcbbca 
dcaccacd 
cdaddadc 
cdaddadc 
dcaccacd 
acbbbbca 
6 8 acbbbbca dcadcacd cdaddadc cdaddadc dcaccacd acbbbbca 


*/
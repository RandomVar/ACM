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
const int N=10;
ll c[N+10][N+10];
ll dp[N+10][N+10];
void init()
{
    
for(int j=0;j<N;j++)
    c[j][0]=1;
for(int i=0;i<N;i++)
   for(int j=1;j<N;j++)
    {
     if(i==j) c[i][j]=1;
      else if(i<j) c[i][j]=0;
      else c[i][j]=(c[i-1][j-1]+c[i-1][j]); 
    }

}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   init();
   while(cin>>n>>m)
   {
       mem(dp,0);
    for(int j=min(m,n);j>=1;j--)
      dp[n][j]=c[m][j];
     for(int i=n-1;i>=1;i--)
     {
       for(int j=min(m,i);j>=1;j--)
         { 
         dp[i][j]=dp[i+1][j+1]*(j+1)+dp[i+1][j];
         }
     }
     cout<<dp[1][1]<<endl;

    // m-=1;
     //cout<<(m+2)*(m*m+3*m+2)<<endl;
   }
 return 0;
  }
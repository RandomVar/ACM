#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=210;
int a[maxn];
double dp[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;int cas=0;
  scanf("%d",&t);
  while(t--)
  {
      int n;
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        // double sum=1;
       dp[1]=1.0;
      for(int i=2;i<=n;i++)
        {
            dp[i]=0;
            double sum=0;
            for(int j=max(1,i-6);j<i;j++)
              dp[i]+=dp[j]*(1.0/min(6,n-j));
            // x=min(6,n-i);
        
        //    cout<<i<<" "<<dp[i]<<endl;
        }
    printf("Case %d: ",++cas);
        double ans=0;
    for(int i=1;i<=n;i++)
      ans+=dp[i]*a[i];
    printf("%.7f\n",ans);

  }
 return 0;
  }

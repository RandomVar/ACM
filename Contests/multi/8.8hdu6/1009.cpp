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
const int maxn=100100;
int g[maxn][3];
char s[20];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
       mem(g,0);
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
          int x;
          cin>>x>>s;
          if(s[0]=='w') g[x][1]++;
          else g[x][0]++;
       }
       int ans=0;
       for(int i=1;i<=n;i++)
       {
           ans+=min(g[i][0],g[i][1]);
       }
       cout<<0<<" "<<ans<<endl;
   }
 return 0;
  }

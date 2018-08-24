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
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=2*1e5+100;
int w[maxn];
vector<ll>v[15];
ll a[maxn][15];
int wei(ll x)
{
    int bit=1;
    while(x>=10)
    {
        x/=10;
     bit++;
    }
    return bit;
}
int main(){
//  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;ll k;
   while(scanf("%d%I64d",&n,&k)==2)
   {
       for(int i=1;i<=n;i++)
        {
            ll x;
        scanf("%I64d",&x);
         w[i]=wei(x);
         //cout<<w[i]<<endl;
         x%=k;
        for(int j=0;j<=10;j++)
           {
               v[j].pb(x);
               a[i][j]=x;
              x=x*10%k;
           }
        }
        for(int i=0;i<=10;i++)
         sort(v[i].begin(),v[i].end());
        ll ans=0;
        for(int i=1;i<=n;i++)
        { 
          // for(int j=0;j<v[w[i]].size();j++)
         //  cout<<v[w[i]][j]<<" ";
           // cout<<endl;
           int p=upper_bound(v[w[i]].begin(),v[w[i]].end(),(k-a[i][0])%k)-v[w[i]].begin();
           int p2=lower_bound(v[w[i]].begin(),v[w[i]].end(),(k-a[i][0])%k)-v[w[i]].begin();
           ll cnt=p-p2;
           //cout<<p<<" "<<p2<<endl;
           if(a[i][w[i]]==(k-a[i][0])%k)
            cnt--;
            ans+=cnt;
        }
       printf("%I64d\n",ans);
   }
 return 0;
  }

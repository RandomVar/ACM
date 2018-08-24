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
const int maxn=5*1e5+100;
ll a[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       for(int i=1;i<=n;i++)
        cin>>a[i];
        int cnt=1;
        ll pre=a[1];
        int ans=1;
       for(int i=2;i<=n;i++)
       {
           if(pre*2>=a[i])
             cnt++,pre=a[i];
            else
            {
                ans=max(ans,cnt);
                cnt=1;pre=a[i];
            }
       }
       ans=max(ans,cnt);
       cout<<ans<<endl;
   }
 return 0;
  }


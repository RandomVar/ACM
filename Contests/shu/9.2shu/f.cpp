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
map<ll,int>mp;
map<ll,int>::iterator it;
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
        mp.clear();
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int op,s;
            scanf("%d%d",&op,&s);
            if(op==2)
            {
                ll x;
               for(int j=1;j<=s;j++)
                scanf("%lld",&x),mp[x]=-1;
            }
            else
            {
                ll x;
                cnt++;
                 for(int j=1;j<=s;j++)
                    scanf("%lld",&x),mp[x]++;
            }
        }
        ll ans=0;
        if(cnt==0)
        {
            ans=1e18-(ll)mp.size();
            // cout<<mp.size()<<endl;
            printf("%lld\n",ans);
        }
        else{
        for(it=mp.begin();it!=mp.end();it++)
          if(it->second==cnt)
            ans++;
        printf("%lld\n",ans);
    }
    }
 return 0;
  }


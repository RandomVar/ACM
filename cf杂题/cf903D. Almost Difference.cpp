#include<bits/stdc++.h>
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
int N;int cnt;
const int maxn=2e5+100;
ll a[maxn];
map<ll,long double>mp;
ll s[maxn];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
            // v.clear();v.push_back(-1);v.push_back(1e9+10);
        
        for(int i=1;i<=n;i++)
         scanf("%lld",&a[i]);
         long double ans=0;
         long double s=0;
         mp.clear();
        for(int i=n;i>=1;i--)
        {
            long double  x=s-mp[a[i]]*a[i]-mp[a[i]+1]*(a[i]+1)-mp[a[i]-1]*(a[i]-1)-((long double)(n-i-mp[a[i]]-mp[a[i]+1]-mp[a[i]-1]))*a[i];
            ans+=x;
            // cout<<(n-i-mp[a[i]]-mp[a[i]+1]-mp[a[i]-1])*a[i]<<" ";
           mp[a[i]]++;
           s+=a[i];
        //    cout<<ans<<endl;
        }
        cout << fixed << setprecision(0) << ans << '\n';
    }
}
#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll n;
bool check(ll x)
{
    ll p=n;
    ll cnt=0;
    while(p>0)
    {
        cnt+=min(x,p);
        p-=x;
        if(p>0)
            p=p-p/10;
    }
    if(cnt>=(n+1)/2)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n)
    {
        ll l=1;ll r=n;
        ll ans;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}


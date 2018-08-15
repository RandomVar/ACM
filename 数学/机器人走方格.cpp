#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod =1e9+7;
ll pow(ll a,ll i)
{
    ll ans=1;
    while(i)
    {
        if(i&1)
            ans=ans*a%mod;
        i>>=1;
        a=a*a%mod;
    }
    return ans;
}
ll jc(ll n)
{
    ll ans=1;
    for(ll i=1;i<=n;i++)
        ans=ans*i%mod;
    return ans;
}
ll C(ll n,ll m)
{
    ll ans=1;
    ans=ans*jc(n)%mod;
    ans=ans*pow(jc(m),mod-2)%mod;
    ans=ans*pow(jc(n-m),mod-2)%mod;
    return ans;
}
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        cout<<C(n-1+m-1,n-1)<<endl;
    }
}
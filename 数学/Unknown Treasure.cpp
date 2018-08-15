#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=1e5+100;
ll fac[maxn];
ll inv[maxn];
ll pow_mod(ll a, int n, int mod)
{
    ll ret = 1;
    while (n)
    {
        if (n&1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}
 
void ini(int x)
{
    fac[0] = 1;
    for(int i = 1; i < x; i++) fac[i] = fac[i-1]*i%x;
    inv[x - 1] = pow_mod(fac[x-1],x-2,x);
    for(int i = x - 2; i >= 0; i--)   inv[i] = inv[i+1] * (i+1) % x;
}
 
ll c(ll a,ll b,ll p)
{
    if(a < b || a < 0 || b < 0)
        return 0;
    return fac[a]*inv[b]%p*inv[a-b]%p;
}
 
ll lucas(ll a,ll b, int p)
{
    if( b == 0)
        return 1;
    return lucas(a/p,b/p,p)*c(a%p,b%p,p)%p;
}
 
 
ll ex_gcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ex_gcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
 
ll mul(ll a, ll b, ll mod)
{
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
 
    ll ret = 0;
    while(b)
    {
        if(b&1)
        {
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        b >>= 1;
        a <<= 1;
        if(a >= mod) a -= mod;
    }
    return ret;
}
 const int maxm=20;
ll m0[maxm];
ll b[maxm];
ll china(ll n)
{
    ll M = 1,d,y,x= 0;
    for(int i = 1; i <= n; i++)
    {
        M *= m0[i];
    }
    for(int i = 1; i <= n; i++)
    {
        ll w = M/m0[i];
        ex_gcd(m0[i],w,d,y);
        x = (x + mul(mul(y, w, M), b[i], M));//可能超范围
    }
    return (x+M) % M;
}
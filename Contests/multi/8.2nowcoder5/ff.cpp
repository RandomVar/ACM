#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
typedef long long ll;
const int maxn=1e5+10;
const ll mod=998244353;
ll sum[maxn*4];
ll lazy[maxn*4];
int N;
ll d[maxn],p[maxn];
ll fastpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
void pushup(int rt)
{
    sum[rt]=(sum[lson]+sum[rson])%mod;
}
void pushdown(int rt)
{
    if(lazy[rt]!=1)
    {
        lazy[lson]=lazy[lson]*lazy[rt]%mod;
        lazy[rson]=lazy[rson]*lazy[rt]%mod;
        sum[lson]=sum[lson]*lazy[rt]%mod;
        sum[rson]=sum[rson]*lazy[rt]%mod;
        lazy[rt]=1;
    }
}
void build(int L,int R,int rt)
{
    lazy[rt]=1;
    if(L==R)
    {
        if(L==0)
            sum[rt]=1;
        else
            sum[rt]=0;
        return ;
    }
    int mid=(L+R)>>1;
    build(Lson);
    build(Rson);
    pushup(rt);
}
void update(int l,int r,ll val,int L,int R,int rt)
{
    if(l<=L&&r>=R)
    {
        lazy[rt]=lazy[rt]*val%mod;
        sum[rt]=sum[rt]*val%mod;
        return ;
    }
    pushdown(rt);
    int mid=(L+R)>>1;
    if(l<=mid)
        update(l,r,val,Lson);
    if(r>mid)
        update(l,r,val,Rson);
    pushup(rt);
}
void up(int p,ll val,int L,int R,int rt)
{
    if(L==R)
    { 

        sum[rt]=(sum[rt]+val)%mod;
        return ;
    }
    int mid=(L+R)>>1;
    if(p<=mid)
        up(p,val,Lson);
    else
    up(p,val,Rson);
    pushup(rt);
}
ll query(int l,int r,int L,int R,int rt)
{
    if(l<=L&&r>=R)
    {
        return sum[rt];
    }
    pushdown(rt);
    ll res=0;
    int mid=(L+R)>>1;
    if(l<=mid)
        res=(res+query(l,r,Lson))%mod;
    if(r>mid)
        res=(res+query(l,r,Rson))%mod;
    return res;
}
vector<ll> all;
int getid(ll x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%lld%lld",&p[i],&d[i]);
        all.push_back(d[i]);
    }
    all.push_back(0);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    int n=all.size();
    ll ans=0;
    build(0,n-1,1);
    ll inv=fastpow(100,mod-2);
    for(int i=1;i<=N;i++)
    {
        int q=getid(d[i]);
        //cout<<query(0,max(0,q-1),0,n-1,1)<<endl;
        ll k=(1LL*query(0,max(0,q-1),0,n-1,1)*p[i]%mod*inv%mod+mod)%mod;
        ans=(ans+k)%mod;
        up(q,k,0,n-1,1);
        update(0,max(0,q-1),1LL*(100-p[i])*inv%mod,0,n-1,1);
    }
    printf("%lld\n",ans%mod);
   //int x;
   // cin>>x;
}
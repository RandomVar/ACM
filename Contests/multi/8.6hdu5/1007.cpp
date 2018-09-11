#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
typedef long long ll;
const int maxn=1e5+10;
const int mod=(1<<30);
const int INF=0x3f3f3f3f;
struct node
{
    int l;
    int r;
    int val;
}a[5000008];
int N,M;
unsigned x,y,z,w;
unsigned f[15000008];
int sum[maxn*4];
unsigned func()
{
    x=x^(x<<11);
    x=x^(x>>4);
    x=x^(x<<5);
    x=x^(x>>14);
    w=x^(y^z);
    x=y;
    y=z;
    z=w;
    return z;
}
ll ans;
void pushup(int rt)
{
    sum[rt]=min(sum[lson],sum[rson]);
}
void build(int L,int R,int rt)
{
    if(L==R)
    {
        sum[rt]=0;
        return;
    }
    int mid=(L+R)>>1;
    build(Lson);
    build(Rson);
    pushup(rt);
}
void update(int l,int r,int val,int L,int R,int rt)
{
    if(val<=sum[rt])
        return;
    if(L==R)
    {
        sum[rt]=max(val,sum[rt]);
        return ;
    }
    int mid=(L+R)>>1;
    if(l<=mid)
        update(l,r,val,Lson);
    if(r>mid)
        update(l,r,val,Rson);
    pushup(rt);
}
void query(int L,int R,int rt)
{
    if(L==R)
    {
        ans=ans^(1LL*L*sum[rt]);
        return ;
    }
    int mid=(L+R)>>1;
    query(Lson);
    query(Rson);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%u%u%u",&N,&M,&x,&y,&z);
        for(int i=1;i<=M*3;i++)
            f[i]=func();
        build(1,N,1);
        for(int i=1;i<=M;i++)
        {
            int l=min(f[3*i-2]%N+1,f[3*i-1]%N+1);
            int r=max(f[3*i-2]%N+1,f[3*i-1]%N+1);
            int val=f[i*3]%mod;
            update(l,r,val,1,N,1);
        }
        ans=0;
        query(1,N,1);
        printf("%lld\n",ans);
    }
    return 0;
}
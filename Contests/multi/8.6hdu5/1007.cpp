#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
typedef long long ll;
const int maxn=1e5+10;
const int mod=(1<<30);
struct node
{
    int l;
    int r;
    int val;
    bool operator<(const node &b)const
    {
        return val>b.val;
    }
}a[5000008];
int N,M;
unsigned x,y,z,w;
unsigned f[15000008];

int cnt[maxn*4];
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
    cnt[rt]=cnt[lson]+cnt[rson];
}

void build(int L,int R,int rt)
{
    cnt[rt]=0;
    if(L==R)
    {
        return ;
    }
    int mid=(L+R)>>1;
    build(Lson);
    build(Rson);
}
void update(int l,int r,int val,int L,int R,int rt)
{
    if(cnt[rt]==(R-L+1))
        return ;
    if(L==R)
    {
        ans=ans^(1LL*L*val);
        cnt[rt]=1;
        return ;
    }
    int mid=(L+R)>>1;
    if(l<=mid)
        update(l,r,val,Lson);
    if(r>mid)
        update(l,r,val,Rson);
    pushup(rt);
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
            a[i].l=min(f[3*i-2]%N+1,f[3*i-1]%N+1);
            a[i].r=max(f[3*i-2]%N+1,f[3*i-1]%N+1);
            a[i].val=f[i*3]%mod;
        }
        sort(a+1,a+1+M);
        ans=0;
        for(int i=1;i<=M;i++)
        {
            update(a[i].l,a[i].r,a[i].val,1,N,1);
            if(cnt[1]==N)
            break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
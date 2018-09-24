ll tree[maxn<<2];
ll seg[maxn<<2];
void pushup(int rt)
{
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void build(int l,int r,int rt)
{
    seg[rt]=0;
    if(l==r)
    {
        scanf("%lld", &tree[rt]);
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void pushdown(int len,int rt)
{
   if(seg[rt])
   {
       tree[rt<<1]=(len-len/2)*seg[rt];
        tree[rt<<1|1]=(len/2)*seg[rt];
       seg[rt<<1|1]=seg[rt<<1]=seg[rt];
      seg[rt]=0;
   }
}

void update(int l,int r,int L,int R,ll val,int rt)
{
    if(l>=L&&r<=R)
    {
        tree[rt]=(r-l+1)*val;
        seg[rt]=val;
        return;
    }
    pushdown(r-l+1,rt);
    int mid=(l+r)/2;
    if(L<=mid) update(l,mid,L,R,val,rt<<1);
    if(R>mid) update(mid+1,r,L,R,val,rt<<1|1);
    pushup(rt);
}
ll query(int l,int r,int L,int R,int rt)
{
    if(l>=L&&r<=R)
    {
        return tree[rt];
    }
    pushdown(r-l+1.rt);
    int mid=(l+r)/2;
    ll ans=0;
    if(L<=mid)   ans+=query(l,mid,L,R,rt<<1);
    if(R>mid) ans+=query(mid+1,r,L,R,rt<<1|1);
    return ans;
}

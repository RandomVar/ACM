int root,cnt;
struct node{
   int l,r;
   ll sum;
}T[maxn];
void init()
{
    root=0;
    T[0].l=T[0].r=T[0].sum;
    cnt=0;
}
void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y];
    x=cnt;
    T[x].sum++;
    if(l==r) return;
    int mid=(l+r)/2; 
    if(mid>=pos) update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos-sum);
}
int query(int l,int r,int x,int y,int pos)
{
     if(l==r) return l;
     int mid=(l+r)/2;
     int sum=T[T[y].l].sum-T[T[x].l].sum;
     if(sum>=pos) 
       return query(l,mid,T[x].l,T[y].l,pos);
    else
     return query(mid+1,r,T[x].r,T[y].r,pos);
}

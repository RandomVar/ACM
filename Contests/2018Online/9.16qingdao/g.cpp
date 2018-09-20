#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
typedef long long ll;
map<ll,int>mp;
map<ll,int>::reverse_iterator rit;
set<ll>::iterator it,pit;
ll big[maxn],sma[maxn];
/**主席树 区间第k小 POJ 2104*/
int n,m,cnt;
int root[maxn],a[maxn];
int p[maxn];
ll pv[maxn];
int x,y,k;
struct node{
  int l,r,sum;
}T[maxn*40];

void init()
{
    cnt=0;
    root[0]=0;
    T[0].l = T[0].r = T[0].sum = 0;
    // v.clear();
}

void update(int l,int r,int &x,int y,int pos){

  T[++cnt]=T[y];
  T[cnt].sum++;
  x=cnt;
  if(l==r) return ;
  int mid=(l+r)/2;
  if(mid>=pos) update(l,mid,T[x].l,T[y].l,pos);
  else update(mid+1,r,T[x].r,T[y].r,pos);

}
ll query1(int l,int r,int y,int key){
  if(l>key) return T[y].sum;
  if(l==r) return 0;
  int mid=(l+r)/2;
  ll ans=0;
  ans+=query1(mid+1,r,T[y].r,key);
  if(mid>key)
    ans+=query1(l,mid,T[y].l,key);
  return ans;
}
ll query2(int l,int r,int y,int key)
{
    if(r<key) return T[y].sum;
    if(l==r) return 0;
    ll ans=0;
    int mid=(l+r)/2;
    ans=query2(l,mid,T[y].l,key);
    if(mid+1<key)
     ans+=query2(mid+1,r,T[y].r,key);
     return ans;
}



void solve(int l,int m,int r)
{
    int nl=m-l;
    int nr=r-m;
    ll ans1=0;ll ans2=0;
    if(nl>1||nr>1)
    {
    if(nl<=nr)
    {
        for(int i=l+2;i<m;i++)
        {
            ans1+=big[i]-query1(1,n,root[l],a[i]);
        }
        if(nl>1) mp[ans1]++;
        for(int i=l+1;i<=m;i++)
        {
            ans2+=query2(1,n,root[r-1],a[i])-sma[i];
        }
        mp[pv[l]-ans2]++;
        ans2=pv[l]-ans2;
    }
    else 
    {
        for(int i=m+2;i<r;i++)
          ans2+=big[i]-query1(1,n,root[m],a[i]);
        if(nr>1) mp[ans2]++;

       for(int i=m;i<r;i++)
        ans1+=big[i]-query1(1,n,root[l],a[i]);
        mp[pv[l]-ans1]++;
        ans1=pv[l]-ans1;
    }
    }
    if(mp[pv[l]]==1)
     mp.erase(pv[l]);
    else
       mp[pv[l]]--;
    
    pv[l]=ans1;pv[m]=ans2;
}

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n;
       scanf("%d",&n);
       for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
      for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
       init();
       mp.clear();
       mp[0]++;
       ll ans=0;
        for(int i=1;i<=n;i++)
        {
          update(1,n,root[i],root[i-1],a[i]);
          big[i]=query1(1,n,root[i-1],a[i]);
          sma[i]=query2(1,n,root[i-1],a[i]);
          ans+=big[i];
        }
        mp[ans]++;
        pv[0]=ans;
        set<ll>st;
        st.insert(0);st.insert(n+1);
        for(int i=1;i<=n;i++)
        {
            rit=mp.rbegin();
            ll ans=rit->first;
             printf("%lld\n",ans);
            if(ans==0) continue;
            ll m=p[i]^ans;
            cout<<"*"<<m<<endl;
            it=st.lower_bound(m);
            pit=it;
            solve(*(--it),m,*pit);
            st.insert(m);
        }
  
     
   }
}
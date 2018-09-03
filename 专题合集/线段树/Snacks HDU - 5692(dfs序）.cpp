#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100010;
LL st[maxn],ed[maxn];
LL dis[maxn];
LL a[maxn];
LL biao[maxn];
vector<LL>edge[maxn];
LL tol;
void dfs(LL x,LL pre){
  st[x]=tol;
  biao[tol]=x;
  for(LL i=0;i<edge[x].size();i++){
    LL t=edge[x][i];
    if(t==pre) continue;
    tol++;
    dis[t]=dis[x]+a[t];
    dfs(t,x);
  }
  ed[x]=tol;
}

LL tree[maxn<<2];
LL seg[maxn<<2];
void pushup(LL rt){
 tree[rt]=max(tree[rt*2],tree[rt*2+1]);
 return;
}

void pushdown(LL rt){
  if(seg[rt]){
    seg[rt*2]+=seg[rt];
    seg[rt*2+1]+=seg[rt];
    tree[rt*2]+=seg[rt];
    tree[rt*2+1]+=seg[rt];
    seg[rt]=0;
  }
  return;
}

void build(LL l,LL r,LL rt){
  seg[rt]=0;
  if(l==r) {
    tree[rt]=dis[biao[l]];
    return;}
  LL mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}

void update(LL l,LL r,LL ll,LL rr,LL val,LL rt){//l,r为当前区间，ll,rr为更新的区间
  if(l>=ll&&r<=rr) {
    seg[rt]+=val;tree[rt]+=val;
    return;
  }
  pushdown(rt);
  LL mid=(l+r)/2;
  if(ll<=mid) {
    update(l,mid,ll,rr,val,rt*2);
  }
  if(rr>mid){
    update(mid+1,r,ll,rr,val,rt*2+1);
  }
  pushup(rt);
}

LL query(LL l,LL r,LL ll,LL rr,LL rt){//ll,rr为查询的区间
  if(l>=ll&&r<=rr){
     return tree[rt];
  }
  LL ans=-INF;
  pushdown(rt);
  LL mid=(l+r)/2;
  if(ll<=mid) ans=max(ans,query(l,mid,ll,rr,rt*2));
  if(rr>mid) ans=max(ans,query(mid+1,r,ll,rr,rt*2+1));
  return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  LL t;
  cin>>t;LL k=0;
  while(t--){
    for(LL i=0;i<maxn;i++)
     edge[i].clear();
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<n;i++){
        LL x,y;
        cin>>x>>y;
        x++;y++;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    dis[1]=a[1];
    tol=1;
    dfs(1,-1);
    build(1,n,1);
    cout<<"Case #"<<++k<<":"<<endl;
    for(LL i=0;i<m;i++){
        LL op;
        cin>>op;
        if(op==0) {
            LL x,y;cin>>x>>y;
            x++;
            update(1,n,st[x],ed[x],y-a[x],1);
            a[x]=y;
        }
        else {
            LL x;
            cin>>x;
            x++;
            cout<<query(1,n,st[x],ed[x],1)<<endl;
        }
    }
  }
  return 0;
}

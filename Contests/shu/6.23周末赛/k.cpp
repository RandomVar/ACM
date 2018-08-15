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
typedef long long LL;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=4*1e5+100;
LL tree[maxn<<2];
LL seg[maxn<<2];
int a[maxn],b[maxn];
int st[maxn],ed[maxn];
int tot;
vector<int>edge[maxn];
int cnt(LL x){
  int ans=0;
  while(x){
     if(x%2) ans++;
    x/=2;
  }
return ans;
}
void pushup(int rt){
 tree[rt]=tree[rt*2]|tree[rt*2+1];

}
void pushdown(int rt){
  if(seg[rt]){
    seg[rt*2]=seg[rt];
    seg[rt*2+1]=seg[rt];
    tree[rt*2]=seg[rt];
    tree[rt*2+1]=seg[rt];
    seg[rt]=0;
  }
}
void build(int l,int r,int rt){
  seg[rt]=0;
  if(l==r) {
     tree[rt]=((LL)1<<b[l]);
     //cout<<rt<<endl;
    //  cout<<tree[rt]<<" "<<b[l]<<endl;
     return;
  }

  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}
void update(int l,int r,int ll,int rr,int add,int rt){//l,r为当前区间，ll,rr为更新的区间
  if(l>=ll&&r<=rr) {
    seg[rt]=((LL)1<<add);tree[rt]=((LL)1<<add);
    return;
  }
  pushdown(rt);
  int mid=(l+r)/2;
  if(ll<=mid) {
    update(l,mid,ll,rr,add,rt*2);
  }
  if(rr>mid){
    update(mid+1,r,ll,rr,add,rt*2+1);
  }
  pushup(rt);
}

LL query(int l,int r,int ll,int rr,int rt){//ll,rr为查询的区间
  if(l>=ll&&r<=rr){
       // cout<<rt<<endl;
     return tree[rt];
  }
  LL ans=0;
  pushdown(rt);
  int mid=(l+r)/2;
  if(ll<=mid) ans|=query(l,mid,ll,rr,rt*2);
  if(rr>mid) ans|=query(mid+1,r,ll,rr,rt*2+1);
  return ans;
}
void dfs(int u,int pre){
 st[u]=++tot;
 for(int i=0;i<edge[u].size();i++)
 {
     int t=edge[u][i];
     if(t==pre) continue;
     dfs(t,u);
 }
  ed[u]=tot;
}
int main(){
   int n,m;
   while(scanf("%d%d",&n,&m)==2){
        memset(tree,0,sizeof(tree));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
          scanf("%d",&a[i]);
          for(int i=0;i<=n;i++)
            edge[i].clear();
           for(int i=0;i<n-1;i++){
            int x,y;
            scanf("%d%d",&x,&y);
             edge[x].pb(y);
             edge[y].pb(x);
           }
        tot=0;
        dfs(1,0);
        //cout<<tot<<endl;
        for(int i=1;i<=n;i++){
            b[st[i]]=a[i];
            //cout<<st[i]<<" "<<b[st[i]]<<endl;
        }
        build(1,n,1);
        for(int i=0;i<m;i++){
          int op;
          scanf("%d",&op);
          if(op==1){
              int a,b;
              scanf("%d%d",&a,&b);
              update(1,n,st[a],ed[a],b,1);
          }
          if(op==2){
              int a;
              scanf("%d",&a);
              LL ans=query(1,n,st[a],ed[a],1);
              //cout<<ans<<endl;
              printf("%d\n",cnt(ans));
          }

        }
   }
}

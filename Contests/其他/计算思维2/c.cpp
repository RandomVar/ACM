#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100100;
int tree[maxn<<2];
int seg[maxn<<2];
void pushup(int rt){
 tree[rt]=tree[rt*2]+tree[rt*2+1];

}
void pushdown(int len,int rt){
  if(seg[rt]){
    seg[rt*2]+=seg[rt];
    seg[rt*2+1]+=seg[rt];
    tree[rt*2]+=(len-len/2)*seg[rt];
    tree[rt*2+1]+=len/2*seg[rt];
    seg[rt]=0;
  }
}
void build(int l,int r,int rt){
  seg[rt]=0;
  if(l==r) {
    tree[rt]=0;return;}
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}
void update(int l,int r,int ll,int rr,int add,int rt){//l,r为当前区间，ll,rr为更新的区间
  if(l>=ll&&r<=rr) {
    seg[rt]+=add;tree[rt]+=(r-l+1)*add;
    return;
  }
  pushdown(r-l+1,rt);
  int mid=(l+r)/2;
  if(ll<=mid) {
    update(l,mid,ll,rr,add,rt*2);
  }
  if(rr>mid){
    update(mid+1,r,ll,rr,add,rt*2+1);
  }
  pushup(rt);
}

int query(int l,int r,int ll,int rr,int rt){//ll,rr为查询的区间
  if(l>=ll&&r<=rr){
     return tree[rt];
  }
  int ans=0;
  pushdown(r-l+1,rt);
  int mid=(l+r)/2;
  if(ll<=mid) ans+=query(l,mid,ll,rr,rt*2);
  if(rr>mid) ans+=query(mid+1,r,ll,rr,rt*2+1);
  return ans;
}
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  build(1,n,1);
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    update(1,n,a,b,c,1);
  }
  for(int i=1;i<n;i++)
    printf("%d ",query(1,n,i,i,1));
   printf("%d\n",query(1,n,n,n,1));
}

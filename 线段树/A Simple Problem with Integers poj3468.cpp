#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=100010;
const int INF=0x3f3f3f3f;
LL tree[maxn<<2];
LL seg[maxn<<2];
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
    scanf("%lld",&tree[rt]);return;}
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

LL query(int l,int r,int ll,int rr,int rt){//ll,rr为查询的区间
  if(l>=ll&&r<=rr){
     return tree[rt];
  }
  LL ans=0;
    pushdown(r-l+1,rt);
  int mid=(l+r)/2;
  if(ll<=mid) ans+=query(l,mid,ll,rr,rt*2);
  if(rr>mid) ans+=query(mid+1,r,ll,rr,rt*2+1);
  return ans;
}

int main(){
  int n,m;
  while(scanf("%d%d",&n,&m)==2){
    build(1,n,1);

  for(int i=0;i<m;i++){
    getchar();
    char a;
    scanf("%c",&a);
    //cout<<a;
    int x,y;
    scanf("%d%d",&x,&y);
    if(a=='Q'){
        printf("%lld\n",query(1,n,x,y,1));
    }
    if(a=='C'){
        int z;
       scanf("%d",&z);
       update(1,n,x,y,z,1);
    }}

  }
  return 0;
}

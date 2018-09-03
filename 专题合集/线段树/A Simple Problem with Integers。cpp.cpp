#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int maxn=100010;
LL sum[maxn<<2];
LL seg[maxn<<2];
void pushup(int rt){
  sum[rt]=sum[rt*2]+sum[rt*2+1];
}
void pushdown(int len,int rt){
  if(seg[rt]==0) return;
  seg[rt*2]+=seg[rt];
  seg[rt*2+1]+=seg[rt];
  sum[rt*2]+=seg[rt]*(len-len/2);
  sum[rt*2+1]+=seg[rt]*(len/2);
  seg[rt]=0;
}
void build(int l,int r,int rt){
  if(l==r) {
    scanf("%lld",&sum[rt]);return;
  }
  int m=(l+r)/2;
  build(l,m,rt*2);
  build(m+1,r,rt*2+1);
  pushup(rt);
}
void update(int ll,int rr,int l,int r,int val,int rt){
  if(ll<=l&&rr>=r) {
     sum[rt]+=val*(r-l+1);seg[rt]+=val;
     return;
  }
  pushdown(r-l+1,rt);
  int m=(l+r)/2;
  if(ll<=m) update(ll,rr,l,m,val,rt*2);
  if(rr>m) update(ll,rr,m+1,r,val,rt*2+1);
  pushup(rt);
}
LL query(int ll,int rr,int l,int r,int rt){
  if(ll<=l&&rr>=r) return sum[rt];
  int m=(l+r)/2;
  LL ans=0;
  pushdown(r-l+1,rt);
  if(ll<=m) ans+=query(ll,rr,l,m,rt*2);
  if(rr>m) ans+=query(ll,rr,m+1,r,rt*2+1);
  return ans;
}
int main(){
   int n,m;
   while(scanf("%d%d",&n,&m)==2){
       build(1,n,1);
      memset(seg,0,sizeof(seg));
      for(int i=1;i<=m;i++){
        char a[2];
        scanf("%s",a);
       if(a[0]=='Q') {
         int x,y;scanf("%d%d",&x,&y);
         printf("%lld\n",query(x,y,1,n,1));
  }
   if(a[0]=='C'){
     int x,y,z;scanf("%d%d%d",&x,&y,&z);
     update(x,y,1,n,z,1);
   }}
}
return 0;
}


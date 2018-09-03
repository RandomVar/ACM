#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100010;
int tree[maxn<<2];
int seg[maxn<<2];
void pushup(int rt){
 tree[rt]=tree[rt*2]|tree[rt*2+1];

}
void pushdown(int len,int rt){
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
    tree[rt]=1;return;}
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}
void update(int l,int r,int ll,int rr,int add,int rt){//l,r为当前区间，ll,rr为更新的区间
  if(l>=ll&&r<=rr) {
    seg[rt]=1<<add;tree[rt]=1<<add;
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
  if(ll<=mid) ans|=query(l,mid,ll,rr,rt*2);
  if(rr>mid) ans|=query(mid+1,r,ll,rr,rt*2+1);
  return ans;
}
int Count(int t){
  int cnt=0;
  while(t){
    if(t&1) cnt++;
    t>>=1;
  }
  return cnt;
}
int main(){
  int x,t,p;
  while(scanf("%d%d%d",&x,&t,&p)==3){
    memset(tree,0,sizeof(tree));
    memset(seg,0,sizeof(seg));
    build(1,x,1);
    for(int i=0;i<p;i++){
        getchar();
        char ch;
        scanf("%c",&ch);
        if(ch=='C') {
            int a,b,c;

            scanf("%d%d%d",&a,&b,&c);
               if(a>b) swap(a,b);
            update(1,x,a,b,c-1,1);
        }
        if(ch=='P'){
            int a,b;

            scanf("%d%d",&a,&b);
             if(a>b) swap(a,b);
            int c=query(1,x,a,b,1);
            printf("%d\n",Count(c));
        }
    }
  }
  return 0;
}

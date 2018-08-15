#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=131072;
int tree[maxn<<2];
int rev[maxn<<2];
int cov[2*maxn+10];
void tr(int rt){
  if(tree[rt]!=-1){
    tree[rt]^=1;
  }
  else rev[rt]^=1;
}
void pushdown(int rt){
  if(tree[rt]!=-1){
    tree[rt*2]=tree[rt*2+1]=tree[rt];
    rev[rt*2]=rev[rt*2+1]=0;
    tree[rt]=-1;
  }
  if(rev[rt]==1){
    tr(rt*2);
    tr(rt*2+1);
    rev[rt]=0;
  }
}
void update(int l,int r,int ll,int rr,int op,int rt){
 if(l>=ll&&r<=rr) {
  if(op==0||op==1){
    rev[rt]=0;tree[rt]=op;}
  else tr(rt);
    return;
  }
  pushdown(rt);
  int mid=(l+r)/2;
  if(ll<=mid) {
    update(l,mid,ll,rr,op,rt*2);
  }
  if(rr>mid){
    update(mid+1,r,ll,rr,op,rt*2+1);
  }

}


void query(int l,int r,int rt){//ll,rr为查询的区间
 if(tree[rt]==1){
    for(int i=l;i<=r;i++)
        cov[i]=1;
    return ;
 }
  else if(tree[rt]==0) return;
  if(l==r) return ;
  pushdown(rt);
  int mid=(l+r)/2;
  query(l,mid,rt*2);
  query(mid+1,r,rt*2+1);

}


int main(){
    //freopen("in.txt","r",stdin);
	//freopen("data.out","w",stdout);
  char op,lc,rc;
  int a,b;
  while(scanf("%c %c%d,%d%c",&op,&lc,&a,&b,&rc)!=EOF){
   getchar();
  a<<=1;
  b<<=1;
  if(lc=='(') a+=1;
  if(rc==')') b-=1;
  if(a>b){
    if(op=='I'||op=='C'){
        update(0,maxn,0,maxn,0,1);
    }
  }
  else{
    if(op=='U') update(0,maxn,a,b,1,1);
    if(op=='I') { if(a>0) update(0,maxn,0,a-1,0,1);
    if(b<maxn) update(0,maxn,b+1,maxn,0,1);}
    if(op=='D') update(0,maxn,a,b,0,1);
    if(op=='C'){
        if(a>0) update(0,maxn,0,a-1,0,1);
        if(b<maxn) update(0,maxn,b+1,maxn,0,1);
        update(0,maxn,a,b,2,1);
    }
    if(op=='S') update(0,maxn,a,b,2,1);
  }
  }
   memset(cov,0,sizeof(cov));
   query(0,maxn,1);
  int t;
  int flag=1;
   for(int i=0;i<maxn;i++){
        if(cov[i]==1&&(i==0||cov[i-1]==0)) t=i;
        if(cov[i]==1&&(i==maxn-1||cov[i+1]==0)){
            if(flag) flag=0;
            else printf(" ");
            if(t%2) printf("(");
            else printf("[");
            printf("%d,",t/2);
            printf("%d",(i+1)/2);
            if(i%2)printf(")");
            else printf("]");

        }
   }
   if(flag) printf("empty set");
    printf("\n");
}

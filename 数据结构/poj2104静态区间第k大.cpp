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
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=100010;
const int M=MAXN*30;
int n,q,m,tot;
int a[MAXN],t[MAXN];
int T[MAXN],lson[M],rson[M],c[M];
void init_hash(){
   for(int i=1;i<=n;i++)
      t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}

int build(int l,int r){
   int root=tot++;
   c[root]=0;
   if(l!=r){
      int mid=(l+r)>>1;
      lson[root]=build(l,mid);
      rson[root]=build(mid+1,r);
   }
return root;
}

int myhash(int x){

return lower_bound(t+1,t+1+m,x)-t;
}

int update(int root,int pos,int val){
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(pos<=mid){
            lson[newroot]=tot++;
            rson[newroot]=rson[root];
            newroot=lson[newroot];
            root=lson[root];
            r=mid;
        }
        else{
            rson[newroot]=tot++;
            lson[newroot]=lson[root];
            newroot=rson[newroot];
            root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
return tmp;
}

int query(int leftroot,int rightroot,int k){
   int l=1,r=m;
   while(l<r){
      int mid=(l+r)>>1;
      if(c[lson[leftroot]]-c[lson[rightroot]]>=k){
          r=mid;
          leftroot=lson[leftroot];
          rightroot=lson[rightroot];
      }
     else{
        l=mid+1;
        k-=c[lson[leftroot]]-c[lson[rightroot]];
        leftroot=rson[leftroot];
        rightroot=rson[rightroot];
     }
   }
return l;
}
int main(){
  while(scanf("%d%d",&n,&q)==2){
    tot=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init_hash();
    T[n+1]=build(1,m);
    for(int i=n;i;i--){
        int pos=myhash(a[i]);
        T[i]=update(T[i+1],pos,1);
    }
    while(q--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",t[query(T[l],T[r+1],k)]);
    }
  }
return 0;
}


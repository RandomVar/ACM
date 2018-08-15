#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
const int M=MAXN*30;
int n,q,m,tot;
int a[MAXN],t[MAXN];
int T[MAXN],lson[M],rson[M],c[M];
int p[MAXN];
void init(){
  for(int i=1;i<=n;i++)
      p[i]=-1;
}
int find(int x){
	return p[x]==x?x:x=find(p[x]);
}
int unit(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	p[y]+=p[x];
	p[x]=y;
	retunr -p[y];
}
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
   int cas;
   cin>>cas;
   while(cas--){

      int q;
      cin>>n>>q;
        //init_hash();
        T[n+1]=build(1,n);
      for(int i=1;i<=n;i++){
         // int pos=myhash(a[i]);
          T[i]=update(T[i+1],0,1);
      }

      for(int i=0;i<q;i++){
        int op,x,y;
        cin>>op>>x;
        if(op==0){
            cin>>y;
            int rx=find(x);
            int ry=find(y);
            int pos=myhash(p[rx]);


        }
      }

   }

}

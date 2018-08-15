#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
struct node{
 int l;int r;
 ll lazy;
 ll sum;

}T[maxn*40];
int cnt;
int root[maxn];
void pushup(int x,int len){
   T[x].sum=T[T[x].l].sum+T[T[x].r].sum+T[x].lazy*len;

}

void build(int l,int r,int &x){
   x=++cnt;
   if(l==r) {
    T[x].lazy=0;
      scanf("%lld",&T[x].sum);
      return ;
   }
   int mid=(l+r)/2;
   build(l,mid,T[x].l);
   build(mid+1,r,T[x].r);
   pushup(x,r-l+1);
}

void update(int l,int r,int L,int R,int &x,int y,int val){
   T[++cnt]=T[y];
   x=cnt;
   if(l>=L&&r<=R){
      T[x].lazy+=val;
      T[x].sum+=(r-l+1)*val;
      return;
   }
   int mid=(l+r)/2;
   if(mid>=L)   update(l,mid,L,R,T[x].l,T[y].l,val);
   if(mid<R) update(mid+1,r,L,R,T[x].r,T[y].r,val);
  pushup(x,r-l+1);

}
ll query(int l,int r,int L,int R,ll adv,int x){
 if(l>=L&&r<=R){
    return T[x].sum+adv*(r-l+1);

 }
  adv+=T[x].lazy;
  int mid=(l+r)/2;
  ll sum=0;
  if(L<=mid) sum+=query(l,mid,L,R,adv,T[x].l);
   if(R>mid) sum+=query(mid+1,r,L,R,adv,T[x].r);
 return sum;
}


int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(scanf("%d%d",&n,&m)==2){
        cnt=0;
       build(1,n,root[0]);
       int vs=0;
       for(int i=0;i<m;i++){
          char op[5];
          scanf("%s",op);
          if(op[0]=='Q'){
              int a,b;

              scanf("%d%d",&a,&b);
              printf("%lld\n",query(1,n,a,b,0,root[vs]));

          }
          if(op[0]=='C'){
                vs++;
              int a,b,d;
             scanf("%d%d%d",&a,&b,&d);
              update(1,n,a,b,root[vs],root[vs-1],d);

          }
          if(op[0]=='H'){

              int a,b,t;
              scanf("%d%d%d",&a,&b,&t);
              printf("%lld\n",query(1,n,a,b,0,root[t]));

          }
          if(op[0]=='B'){
              int t;
              scanf("%d",&t);
              vs=t;

          }

       }


   }


}

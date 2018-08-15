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

/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
ll lastans;
int block;
ll cnt[maxn];
ll ans[maxn];
int a[maxn],b[maxn];
struct node{
 int l,r,id;
 int pos;//分块
 void init(){
  pos=l/block;
 }
 bool operator<(const node &a)const{
   if(pos==a.pos) return r<a.r;
   return pos<a.pos;
 }
}h[maxn];

ll calc(ll x){
return x*x*x;
}
void update(int pos,int x){
  lastans-=calc(cnt[a[pos]]);
  lastans+=calc(cnt[a[pos]]+=x);
}

int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(scanf("%d",&n)==1){
    for(int i=1;i<=n;i++)
      {
          scanf("%d",&a[i]);b[i]=a[i];
      }
      sort(b+1,b+n+1);
        int sz=unique(b+1,b+n+1)-b;
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(b+1,b+sz+1,a[i])-b;
        }

      block=sqrt(n+0.5);
      int m;
      scanf("%d",&m);
      for(int i=1;i<=m;i++){
          scanf("%d%d",&h[i].l,&h[i].r);
          h[i].id=i;
          h[i].init();
      }
      sort(h+1,h+m+1);

     int lastl=2,lastr=1;
     lastans=0;
     mem(cnt,0);
     for(int i=1;i<=m;i++){
        while(lastl>h[i].l) update(--lastl,1);
        while(lastr<h[i].r) update(++lastr,1);
        while(lastl<h[i].l) update(lastl++,-1);
        while(lastr>h[i].r) update(lastr--,-1);
       ans[h[i].id]=lastans;
     }
  for(int i=1;i<=m;i++)
    printf("%I64d\n",ans[i]);

  }


}

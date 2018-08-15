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
  ll l;ll r;ll v;
  bool operator<(const node &b)const{

  return l<b.l;
  }

}a[maxn];
ll sum[maxn];
ll s2[maxn];
int main(){
 // ios_base::sync_withn_stdio(false);cin.tie(NULL);cout.tie(NULL);
 int t;
 scanf("%d",&t);
 while(t--){
  ll m,k;
  scanf("%lld%lld",&m,&k);
  for(int i=1;i<=m;i++){
    scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].v);

  }
    sort(a+1,a+m+1);
    sum[0]=0;
    a[m+1].l=a[m+1].r=a[m+1].v=0;
    a[0].l=a[0].r=a[0].v=0;
   for(int i=1;i<=m;i++){
       sum[i]=sum[i-1]+(a[i-1].r-a[i-1].l+1)*a[i-1].v;

   }
   ll cnt=0;
   for(int i=1;i<=m;i++){
      node x;
      x.l=a[i].l+k-1;
      int p=upper_bound(a+1,a+1+m,x)-a-1;
      ll ans=0;
      if(p==m)
         ans=sum[m]+(min(a[m].r,x.l)-a[m].l+1)*a[m].v-sum[i];

      else ans=sum[p]+(min(x.l,a[p].r)-a[p].l+1)*a[p].v-sum[i];
      cnt=max(ans,cnt);
   /*   ll ans=0;
      if(p==m)
        ans=sum[m]+(a[m].r-a[m].l+1)*a[m].v-sum[i];
      else if(x.l<a[p].r)
        ans=sum[p]+(x.l-a[p].l+1)*a[p].v-sum[i];
       else
        ans=sum[p]+(a[p].r-a[p].l+1)*a[p].v-sum[i];
        //cout<<p<<" "<<ans<<endl;
       cnt=max(ans,cnt);
   */

   }
   //cout<<cnt<<endl;
   s2[m+1]=0;
   for(int i=m;i>=1;i--){
      s2[i]=s2[i+1]+(a[i+1].r-a[i+1].l+1)*a[i+1].v;
     //cout<<s2[i]<<" ";
   }
   for(int i=m;i>=1;i--){
      node x;
      x.l=a[i].r-k+1;
      int p=upper_bound(a+1,a+1+m,x)-a-1;
      ll ans=0;
      if(p==0)
        ans=s2[1]+(a[1].r-a[1].l+1)*a[1].v-s2[i];
       else ans=s2[p]+(a[p].r-max(x.l,a[p].l)+1)*a[p].v-s2[i];
      cnt=max(ans,cnt);
     // cout<<ans<<endl;
      //cout<<x.l<<" ";
      //cout<<p<<endl;
     /* if(p==0)
            ans=s2[1]+(a[1].r-a[1].l+1)*a[1].v-s2[i];
      else if(a[p].r<x.l) ans=s2[p]-s2[i];
      else ans=s2[p]+(a[p].r-x.l+1)*a[p].v-s2[i];
       cnt=max(ans,cnt);*/
      // cout<<ans<<endl;
   }
   cout<<cnt<<endl;
 }
  }
/*

5
2 5
1 10 11
16 45 3
*/

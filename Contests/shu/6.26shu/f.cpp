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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
ll m;
map<ll,int>mp1;
map<ll,int>mp2;
ll a[10000];
int n;
int dfs1(int pos,ll ans){
   if(pos==n/2+1) return 0;
   //mp[ans]=1;
   if(dfs1(pos+1,ans)) return 1;
   ll t=(ans+a[pos])%m;
   //if(mp1.find(t)!=mp1.end()) return 0;
    if(t==m-1) return 1;
    mp1[t]=1;
   if(dfs1(pos+1,t)) return 1;
}
int dfs2(int pos,ll ans){
   if(pos==n) return 0;
   //mp[ans]=1;
   if(dfs2(pos+1,ans)) return 1;
   ll t=(ans+a[pos])%m;
  // if(mp2.find(t)!=mp2.end()) return 0;
    mp2[t]=1;
   if(dfs2(pos+1,t)) return 1;
}

int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  // int n;//ll m;
   while(scanf("%d%lld",&n,&m)==2){
        mp1.clear();
         mp2.clear();
      for(int i=0;i<n;i++){
        //cin>>a[i];
        scanf("%lld",&a[i]);
         a[i]=a[i]%m;
      }
      mp1[0]=1;
      mp2[0]=1;
      if(dfs1(0,0)) {cout<<m-1<<endl;continue;}
      if(dfs2(n/2+1,0)) {cout<<m-1<<endl;continue;}
      map<ll,int>::iterator it;
       map<ll,int>::iterator p1;
       ll ans=0;
      for(it=mp1.begin();it!=mp1.end();it++){
           ll t=m-it->first;
           p1=mp2.lower_bound(t);
         if(p1!=mp2.begin()) {
             p1--;
            ans=max(ans,(p1->first+it->first)%m);
         }
         else {
                p1=mp2.end();
               p1--;
                ans=max(ans,it->first);
                ans=max(ans,(it->first+p1->first)%m);
      }
      }
      printf("%lld\n",ans);
     // cout<<ans<<endl;
   }

}

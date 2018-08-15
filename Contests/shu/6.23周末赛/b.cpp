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
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll h[5000];
int k;
void dfs(int pos,int id){
  if(pos==10) return;
  if(h[id]>1e9) return;
  h[++k]=h[id]*10+4;
  dfs(pos+1,k);
  h[++k]=h[id]*10+7;
  dfs(pos+1,k);
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   h[0]=0;k=0;
   dfs(0,0);
   sort(h,h+k+1);
  // cout<<k<<endl;
  // for(int i=0;i<=k;i++) cout<<h[i]<<endl;
   ll l,r;
   while(cin>>l>>r){
        int p1=lower_bound(h,h+k+1,l)-h;
        int p2=lower_bound(h,h+k+1,r)-h;
        ll pre=l;
        ll ans=0;
        //if(p1==p2) {ans=h[p1]*(r-l+1);cout<<ans<<endl;continue;}
        for(int i=p1;i<p2;i++){
            ans+=h[i]*(h[i]-pre+1);
            pre=h[i]+1;
        }
       ans+=h[p2]*(r-pre+1);
        cout<<ans<<endl;
   }
}

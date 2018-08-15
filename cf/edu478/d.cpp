#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=2*1e5+10;
struct node{
  ll x,vx,vy;
  ll p;
  bool operator<(const node& b)const{
   if(p==b.p) return vx<b.vx;
   return p<b.p;
  }
}g[maxn];
vector<ll>cnt[maxn];
int main(){
  ll n;ll a,b;
  while(cin>>n>>a>>b){
        for(ll i=0;i<=n;i++)
           cnt[i].clear();
    for(ll i=0;i<n;i++){
        cin>>g[i].x;
        cin>>g[i].vx>>g[i].vy;
        g[i].p=g[i].vy-a*g[i].vx;
    }
    sort(g,g+n);
    int k=0;
    for(ll i=0;i<n;i++){
        if(i&&g[i].p==g[i-1].p) cnt[k].pb(i);
        else {cnt[++k].pb(i);}
    }
    ll ans=0;
    for(ll i=1;i<=k;i++){
            ll len=cnt[i].size();
          //  cout<<len<<endl;
    if(len>1){
              ans+=(len-1)*len;
        ll pre=cnt[i][0];
        ll aa=0;
        for(ll j=1;j<cnt[i].size();j++){
            ll t=cnt[i][j];
            if(g[t].vx==g[pre].vx) aa++;
            else if(aa){
                ans-=aa*(aa+1);
                aa=0;
            }
              pre=t;
        }
        if(aa){
            ans-=aa*(aa+1);
        }
    }
  }
    cout<<ans<<endl;
}}

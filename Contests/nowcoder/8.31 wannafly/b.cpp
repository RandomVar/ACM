/*
https://www.nowcoder.com/acm/contest/161/B
*/
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
int gr[maxn];
int vis[maxn];
vector<int>g[maxn];
int pre[maxn];
int suf[maxn];
int a[maxn];
void init()
{
    mem(vis,0);
    gr[0]=0;
    for(int i=1;i<maxn;i++)
        for(int j=i;j<maxn;j+=i)
           g[j].pb(i);
   for(int i=1;i<maxn;i++)
    {
        for(int j=0;j<g[i].size();j++)
          vis[gr[i-g[i][j]]]=i;
        
        for(gr[i]=0;vis[gr[i]]==i;gr[i]++);
    }
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   init();
   int n;
   while(cin>>n)
   {
     for(int i=1;i<=n;i++)
      cin>>a[i];
      pre[0]=suf[n+1]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]^gr[a[i]];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]^gr[a[i]];
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
       int ans=pre[i-1]^suf[i+1];
      // cout<<a[i]<<" "<<endl;
       for(int j=0;j<g[a[i]].size();j++)
       {
          //  cout<<g[a[i]][j]<<" ";
          if(ans==gr[a[i]-g[a[i]][j]]) cnt++;
       }
   }
    cout<<cnt<<endl;
   }
 return 0;
  }

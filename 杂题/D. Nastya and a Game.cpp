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
const ll INF= 1e18+100;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=2*1e5+100;
ll f[maxn];
ll a[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;int k;
  while(cin>>n>>k){
     for(int i=1;i<=n;i++)
        cin>>a[i];
        f[n]=n+1;
     for(int i=n-1;i>=1;i--){
         if(a[i]!=1) f[i]=i+1;
         else f[i]=f[i+1];
     }
     ll ans=0;

     for(int i=1;i<=n;i++){
        ll p=a[i];ll s=a[i];
        if(p==s*k) ans++;
        int x=i;
        while(f[x]!=n+1&&a[f[x]]<=INF/p){
           p*=a[f[x]];
           s+=f[x]-x-1+a[f[x]];
           x=f[x];
           int w=-1;
           if(p%k==0) w=p/k;
           ll y=f[x]-x-1;
           if(s<=w&&w<=s+y)
             ans++;
           /* if(p<=(s+f[x]-x-1)&&p>s*k)
               ans++;
            p*=a[f[x]];
            s+=f[x]-x-1+a[f[x]];
            x=f[x];
            if(p==s*k)
                ans++;*/
        }

     }
     cout<<ans<<endl;


    }
return 0;
  }


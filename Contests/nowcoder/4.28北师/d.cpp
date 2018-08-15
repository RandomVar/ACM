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
const ll INF=1e18;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=100010;
ll a[maxn],b[maxn],c[maxn];
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<k;i++)
        cin>>c[i];
        ll ans=INF;
    for(int i=0;i<m;i++){
        int p1=lower_bound(a,a+n,b[i])-a;//>=b[i]
        int p2=lower_bound(c,c+k,b[i])-c;
        ll x1=INF;
        if(p1<n) x1=(ll)abs(b[i]-a[p1]);
        if(p1) x1=min(x1,(ll)abs(b[i]-a[p1-1]));
        ll x2=INF;
        if(p2<k) x2=(ll)abs(b[i]-c[p2]);
        if(p2) x2=min(x2,(ll)abs(b[i]-c[p2-1]));
        ans=min(ans,x1+x2);
    }
    ans+=3;
    cout<<ans<<endl;
  }
}

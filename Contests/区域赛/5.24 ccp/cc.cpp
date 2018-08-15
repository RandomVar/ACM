#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
long long a[maxn];
ll g1[maxn];
ll g2[maxn];
ll gcd(ll a,ll b){
         if(a < b){
                   swap(a,b);
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    g1[1]=a[1];
    for(int i=2;i<=n;i++)
        g1[i]=gcd(g1[i-1],a[i]);
    g2[n]=a[n];
    for(int i=n-1;i>=1;i--)
        g2[i]=gcd(g2[i+1],a[i]);

    ll ans=g2[2];
    ans=max(ans,g1[n-1]);
    for(int i=2;i<n;i++)
        ans=max(ans,gcd(g1[i-1],g2[i+1]));
    cout<<ans<<endl;
    }

return 0;
}

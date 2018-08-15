#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
ll a[maxn];
int main(){
  ll n,m,l;
  while(cin>>n>>m>>l){
    for(int i=1;i<=m*n;i++)
        cin>>a[i];
    sort(a+1,a+m*n+1);
    int p1=upper_bound(a+1,a+m*n+1,l+a[1])-a;//>
    p1--;
    //cout<<p1<<endl;
    ll ans=0;
    if(p1<n) cout<<0<<endl;
    else{
        ans+=a[1];
        int p2=1;
        int cnt=1;
        while(p2+m-1+n-cnt<=p1&&cnt<n){
            p2=p2+m;
            ans+=a[p2];
            cnt++;
        }
       // cout<<cnt<<endl;
        while(cnt<n&&p2+n-cnt<=p1){
            cnt++;
            p2=p1-(n-cnt);
            ans+=a[p2];

        }
        cout<<ans<<endl;
    }
  }


}

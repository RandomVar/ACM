#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll s[3100];
ll c[3100];
int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){

    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    ll ans=INF;
    int flag=-1;
    for(int i=2;i<=n-1;i++){
            ll co1=INF;ll co2=INF;
        for(int j=1;j<i;j++)
            if(s[j]<s[i]) co1=min(co1,c[j]);
        for(int j=i+1;j<=n;j++)
            if(s[j]>s[i]) co2=min(co2,c[j]);
            if(co1==INF||co2==INF) continue;
            ans=min(ans,c[i]+co1+co2);
            flag=0;
    }
    if(flag==-1) cout<<-1<<endl;
    else cout<<ans<<endl;
  }


}

#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
ll a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;ll cas=0;
    ll n,k;
    while(t--){
            cas++;
            ll ans=0;
            cin>>n>>k;
        ll sum=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        cout<<"Case #"<<cas<<": ";
        if(sum%k) cout<<"-1"<<endl;
        else{
            sum/=k;ll pre=0;
            for(ll i=1;i<=n;i++){

                ll now=a[i]+pre;
                if(pre) ans++;
                //cout<<now<<endl;
                while(now>sum) {
                   ans++;
                   now-=sum;
            }
            if(now==sum) {pre=0;continue;}
            pre=now;
            //cout<<ans<<endl;
        }

    cout<<ans<<endl;
}}

}

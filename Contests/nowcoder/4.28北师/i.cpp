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
ll a[1000010];
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll len=s.size();
    ll k=0;ll ans=0;ll ji=0;
    for(ll i=0;i<len;i++)
    {
        if(s[i]=='D') ji++;
     else if(s[i]=='M') {a[k++]=ji;
        ans+=ji;}
    }
    ll cnt=0;
    ll flag=0;
   if(k*ji<p) cout<<-1<<endl;
   else cout<<abs(ans-p)<<endl;
   /*else{
   if(ans<p){
        ll po=0;
    while(ans<p&&po<k){
        ans+=ji-a[po++];
        ans+=k-po;
        cnt++;
        }
        //if(ans<p) flag=1;
        }
    else if(ans>p){
        ll po=k-1;
    while(ans>p&&po>=0){
        ans-=a[po--];
        ans-=k-po;
       cnt++;
    }
      //if(ans>p) flag=1;
    }
   cout<<cnt<<endl;
        }*/
    }}



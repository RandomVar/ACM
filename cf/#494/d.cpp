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
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
ll mp[40];
ll mp1[40];
int cal(ll x){
    int i;
    ll ans=1;
    if(x==1) return 0;
    for(i=1;;i++)
    {
        ans*=2;
        if(ans==x) return i;
    }

}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,q;
  while(cin>>n>>q){
       mem(mp,0);
       mem(mp1,0);
     for(int i=1;i<=n;i++){
        //cin>>a[i];5 4
       ll t;
       cin>>t;
       mp1[cal(t)]++;
     // cout<<cal(t)<<endl;
     }
     //cout<<mp[3]<<endl;
     for(int i=1;i<=q;i++){
        ll t;
        cin>>t;
        int flag=0;
        ll cnt=0;
        int k=0;
        for(int j=0;j<=32;j++)
            mp[j]=mp1[j];
        while(t){
            if(t%2) {
                ll c=1;
                int x=k;
               // ll num=t;
               while(c&&x>=0){
                 while(mp[x]<=0){
                   x--;
                   if(x<0) break;
                   c*=2;
               }
                //cout<<k<<" "<<x<<" "<<mp[x]<<endl;
              if(x<0) {flag=1;break;}
                if(mp[x]>0)
                {
                   if(mp[x]>=c) {mp[x]-=c;cnt+=c;c=0;}
                   else {cnt+=mp[x];c-=mp[x];mp[x]=0;}
               }
               }

            }
            if(flag) break;
           // cout<<k<<" "<<cnt<<endl;
            t/=2;
            k++;
        }
        if(flag) cout<<-1<<endl;
        if(!flag) cout<<cnt<<endl;




     }


  }
return 0;

}

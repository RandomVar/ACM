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
const int maxn=1e5+100;

struct node{
   ll cnt;ll p;
}a[maxn];
ll base=1e8+100;
ll z=1e8+1;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m){
    int ans=1;
    mem(a,0);
    map<ll,int>mp;
    for(int i=0;i<m;i++){
       int t,p;
       cin>>t>>p;
       ll precnt=a[t].cnt;
       ll prep=a[t].p;
            a[t].cnt++;
            a[t].p+=p;
  //          mp[t]=node{a[t].cnt,a[t].p};
        if(t!=1){
         // cout<<a[1].cnt<<" "<<a[1].p<<" "<<precnt<<" "<<prep<<" "<<a[t].cnt<<" "<<a[t].p<<endl;
        if(precnt>a[1].cnt||(precnt==a[1].cnt&&prep<a[1].p)) {
           // cout<<1<<endl;
            ll x=precnt*base+(z-prep);
            mp[x]--;
           if(mp[x]==0) mp.erase(x);       
           x=a[t].cnt*base+z-a[t].p;
           mp[x]++;
            cout<<ans<<endl;continue;
            }
        if(precnt<a[1].cnt||(precnt==a[1].cnt&&prep>=a[1].p)){
            //cout<<1<<endl;
              if(a[t].cnt>a[1].cnt||(a[t].cnt==a[1].cnt&&a[t].p<a[1].p))
               { 
                 //  cout<<1<<endl;    
                   ll  x=a[t].cnt*base+z-a[t].p;
                    mp[x]++;
                   ans++;cout<<ans<<endl;continue;
                
                   }
              else {cout<<ans<<endl;continue;}
        }
        else cout<<ans<<endl;
        }
        else{
            map<ll,int>::iterator it;
            ll x=a[1].cnt*base+z-a[1].p;
            if(mp.size()==0) {cout<<ans<<endl;continue;}
          for(it=mp.begin();it!=mp.end();it++)
             { 
               //  cout<<it->first<<" "<<it->second<<" "<<x<<endl;
                 if(it->first<=x) {
                     ans-=it->second;
                     //ll t=it->first;
                     //mp.erase(it);
                 }
                 else break;
             }
             mp.erase(mp.begin(),it);
             cout<<ans<<endl;

        }
    }
  }

  }




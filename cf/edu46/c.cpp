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
const int maxn=4*1e5+100;

ll ans[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n){
        map<ll,ll>a;
        mem(ans,0);
    for(int i=1;i<=n;i++){
        ll x,y;
       cin>>x>>y;
       y++;
        a[x]++;
        a[y]--;
    }
    int pre=0;ll s;x
    map<ll,ll>::iterator it;
   // it=a.begin();

    for(it=a.begin();it!=a.end();it++)
    {
        if(it==a.begin()) {s=it->first;pre=it->second;continue;}
        ans[pre]+=(it->first-s);
        //cout<<pre<<" "<<ans[pre]<<endl;
        pre=(it->second+pre);
        s=it->first;
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

   }


}

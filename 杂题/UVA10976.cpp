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
typedef pair<ll,ll> p;
int main(){
 // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll k;
 
  while(cin>>k){ 
      vector<p>ans;

     for(ll i=k+1;i<=2*k;i++){
         if((k*i)%(i-k)==0) 
           ans.push_back(make_pair((k*i)/(i-k),i));
     }
     printf("%d\n",ans.size());
    // cout<<ans.size()<<endl;
     for(int i=0;i<ans.size();i++)
{
      printf("1/%lld = 1/%lld + 1/%lld\n",k,ans[i].first,ans[i].second);
}

  }


  }


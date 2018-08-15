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
int n,k;
int from,to;
ll dp[30][5100];
int cnt[30];
ll f(int c,int pos){
  return (ll)c*(c-1LL)/2*(pos+'a');

}
ll cal(int pos,int res){
   if(pos==from||pos==to) return cal(pos+1,res);
   if(pos==26){
         int t=min(cnt[from],res);
         //ans=f(t,from);
         res-=t;
        return f(cnt[from]-t,from)+f(k-res+cnt[to],to);
   }
   ll & ans=dp[pos][res];
   if(ans!=-1)
    return ans;
    ans=f(cnt[pos],pos)+cal(pos+1,res);
    if(res-cnt[pos]>=0)
      ans=max(ans,cal(pos+1,res-cnt[pos]));
   // dp[pos][res]=ans;
     return ans;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--){
      cin>>n>>k;
      string s;
      cin>>s;
      int len=s.size();
      mem(cnt,0);
   
      for(int i=0;i<len;i++){
         cnt[s[i]-'a']++;
      }
      ll ans=0;
      for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            if(i==j) continue;
            from=i;to=j;
               mem(dp,-1);
            ans=max(ans,cal(0,k));
         //   cout<<i<<" "<<j<<" "<<ans<<endl;
        }
          cout<<ans<<endl;

   }


  }


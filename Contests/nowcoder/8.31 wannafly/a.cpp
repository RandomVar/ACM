#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
string s;
int len;
int cnt[30];
int check(int mid)
{
    mem(cnt,0);
    int ans=0;
    for(int i=0;i<mid;i++)
    {
        cnt[s[i]-'a']++;
       if(cnt[s[i]-'a']==1)
         ans++;
    }
    if(ans==26) return 1;
    for(int i=mid;i<len;i++)
    {
      cnt[s[i-mid]-'a']--;
      if(cnt[s[i-mid]-'a']==0)
        ans--;
      cnt[s[i]-'a']++;
      if(cnt[s[i]-'a']==1)
      ans++;
      if(ans==26) return 1;
    }
    return 0;
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(cin>>s)
  {
      len=s.size();
      int l=0;int r=len;
      int ans=-1;
      while(l<=r)
      {
          int mid=(l+r)/2;
          if(check(mid))
           r=mid-1,ans=mid;
        else l=mid+1;
      }
     cout<<ans<<endl;
  }
 return 0;
  }


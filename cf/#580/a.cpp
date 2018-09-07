#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
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
int cnt[30];
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k )
 {
     string s;
     cin>>s;
     mem(cnt,0);
     for(int i=0;i<s.size();i++)
     {
         cnt[s[i]-'A']++;
     }
     int ans=inf;
     for(int i=0;i<k;i++)
       ans=min(ans,cnt[i]);
   cout<<ans*k<<endl;
 }
 return 0;
  }


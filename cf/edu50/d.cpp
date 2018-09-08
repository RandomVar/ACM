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
const int maxn=3*1e5+100;
ll a[maxn],b[maxn];
ll sa[maxn],sb[maxn];
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       sa[0]=sb[0]=0;
       for(int i=1;i<=n;i++)
         cin>>a[i],sa[i]=sa[i-1]+a[i];
        
        int m;cin>>m;
        for(int i=1;i<=m;i++)
         cin>>b[i],sb[i]=sb[i-1]+b[i];
        if(sa[n]!=sb[m])
           {cout<<-1<<endl;continue;}
      int i=1,j=1;
      int cnt=0;
      while(i<=n&&j<=m)
      {
          if(sa[i]==sb[j]) i++,j++,cnt++;
          else if(sa[i]>sb[j])
            j++;
          else if(sa[i]<sb[j])
           i++;
      }
      cout<<cnt<<endl;
          

   }
 return 0;
  }


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
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int q;
   while(cin>>q)
   {
       for(int i=1;i<=q;i++)
       {
           ll n,m,k;
          cin>>n>>m>>k;
          if(max(n,m)>k)
            {
                cout<<-1<<endl;
                continue;
            }
        int x=(n+k)%2;
        int y=(m+k)%2;
        if(x^y!=0)
          cout<<k-1<<endl;
        else if(x!=0)
         cout<<k-2<<endl;
        else cout<<k<<endl;
      /*    ll a1=min(n,m);
          ll b=max(n,m)-a1;
        ll ans=0;
        if(k<(a1+b)) 
        {
            cout<<-1<<endl;
            continue;
        }
        else if((k-(a1+b))%2==0)
            ans=(k-(a1+b))/2+a1;
        else if((k-(a1+b))%2==1)
        {
            
          if(b>0)  ans=(k-(a1+b-1))/2+a1+1;
          else ans=(k-(a1+b-1))/2+a1;
        }
        cout<<ans<<endl;*/
       }
   }
 return 0;
  }


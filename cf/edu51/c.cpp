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
int a[120];
int cnt[120];
int f[120];
int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n)
  {
    mem(cnt,0);
    for(int i=1;i<=n;i++)
     cin>>a[i],cnt[a[i]]++;
     int flag=0;
     int c=0;int biao=0;
     for(int i=1;i<=100;i++)
      if(cnt[i]==1)
      {
        f[i]=flag;
        flag^=1;
        c++;
      }
      else if(cnt[i]%2)
      {
        biao=i;
      }

      if(c%2==0)
      {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
          if(cnt[a[i]]!=1)
           cout<<"A";
           else {
             if(f[a[i]]==0) cout<<"A";
             else cout<<"B";
           }
        }
        cout<<endl;
      }
      else if(biao==0)
       cout<<"NO"<<endl;
       else
       {
         cout<<"YES"<<endl;
         int flag=0;
         for(int i=1;i<=n;i++)
         {
           if(cnt[a[i]]!=1&&biao!=a[i])
            cout<<"A";
            else if(cnt[a[i]]==1)
              {
                if(f[a[i]]==0) cout<<"A";
                else cout<<"B";
              }
            else if(biao==a[i]&&flag==0)
              {cout<<"B";flag=1;}
            else if(biao==a[i])
             cout<<"A";
         }
         cout<<endl;
       }

  }
 return 0;
}

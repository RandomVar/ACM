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
  int n;
  while(cin>>n)
  {
      if(n%4==0||n%4==3)
      {
          cout<<"Yes"<<endl;
          cout<<1<<" "<<2<<endl;
          cout<<n-1;
          for(int i=1;i<=n;i++)
          {
              if(i!=2) cout<<" "<<i;
          }
          cout<<endl;
      }
      else if(n==1) cout<<"No"<<endl;
      else if(n==2) cout<<"No"<<endl;
       else if(n%2==0)  
       {
           cout<<"Yes"<<endl;
           cout<<1<<" "<<n/2<<endl;
           cout<<n-1;
           for(int i=1;i<=n;i++)
             if(i!=n/2) cout<<" "<<i;
             cout<<endl;
       }
     else
     {
         cout<<"Yes"<<endl;
         cout<<1<<" "<<(n+1)/2<<endl;
         cout<<n-1;
         for(int i=1;i<=n;i++)
           if(i!=n/2+1) cout<<" "<<i;
           cout<<endl;
     }
          /*int flag=0;
          int N=n*(n+1)/2;
          for(int i=2;i<N;i++)
          {
              if(N%i==0)
              {
                  flag=i;break;
              } 
          }
          if(!flag) cout<<"No"<<endl;
          else
          {
              cout<<"Yes"<<endl;
*/
            /*  if(flag<=n) 
              {
                  cout<<1<<" "<<flag;
                  cout<<n-1;
               for(int i=1;i<=n;i++)
                  if(i!=flag) cout<<" "<<i;
                cout<<endl;
              } 
              else
              {
                  
              }*/
          }
 
 return 0;
  }


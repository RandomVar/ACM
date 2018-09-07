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
      priority_queue<int>q1,q2;
      int x;
      for(int i=1;i<=n;i++)
        cin>>x,q1.push(x);
      for(int i=1;i<=n;i++)
        cin>>x,q2.push(x);
    ll ans=0;
    int flag=0;
      while(!q1.empty()&&!q2.empty())
      {
          if(q1.top()>q2.top())
          {
              if(flag==0)
              {
              ans+=q1.top();
              q1.pop();
              }
              else
              {
                //   ans-=q1.top();
                  q1.pop();
              }
          }
          else
          {
              if(flag==0)
              {
                //   ans+=q2.top();
                  q2.pop();
              }
              else
              {
                  ans-=q2.top();
                  q2.pop();
              }
          }
          flag^=1;
      }
      while(!q1.empty())
      {
          if(flag==0)
        ans+=q1.top(),q1.pop(),flag^=1;
        else 
          q1.pop(),flag^=1;
      }
       
        while(!q2.empty())
        {
          if(flag==0)
            q2.pop(),flag^=1;
        else 
        ans-=q2.top(),q2.pop(),flag^=1;
       
       }
       cout<<ans<<endl;
  }
 return 0;
  }

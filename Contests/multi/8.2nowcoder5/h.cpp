#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n,k;
   while(cin>>n>>k)
   {
       for(int i=1;i<=n;i++)
        cin>>a[i].v,a[i].id=i;
  
        sort(a+1,a+1+n);
        int k=1;
        b[a[1].id]=1;
       for(int i=2;i<=n;i++)
       {
           if(a[i].v==a[i-1].v) 
                b[a[i].id]=k;
            else b[a[i].id]=++k;
       }  

       for(int i=n;i>=1;i--)
       {
           ll k=sum(n)-sum(b[i]);
           dp[i]=1+k;
           update(b[i],dp[i]);
       }
       ll tmp=k;
       int i=1;
       while(i<=n)
       {
         if(dp[i]>=tmp)
           ans.pb(i),tmp-=1,i=nex[i];
        else
          tmp-=dp[i],i++;
       }
    }

 return 0;
  }


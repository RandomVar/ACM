#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<ctime>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
ll mul(ll x,ll y,ll Z)//大数相乘取模
{
    ll tmp=x/(long double)Z*y+1e-3;
    return (x*y+Z-tmp*Z)%Z;
}
ll MUL(ll x,ll p,ll Z)
{
    ll y=1;
    while(p)
    {
        if(p&1)y=mul(y,x,Z);
        x=mul(x,x,Z);
        p>>=1;
    }
    return y;
}
bool miller_rabin(ll n)
{
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    ll p=n-1;
    srand(time(NULL));
    int TIMES=8;
    for(int i=1;i<=TIMES;i++)
    {
        ll x=rand()%(n-1)+1;
        if(MUL(x,p,n)!=1)return 0;
    }
    return 1;
}
ll gcd(ll a,ll b){
         if(a < b){
                   swap(a,b);
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}
int a[400],c[400];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while(cin>>n){
        map<int,int>dp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
       // int t=cal(a[i]);
       // cout<<t<<endl;


         if(dp.find(a[i])==dp.end()) dp[a[i]]=c[i];
          else dp[a[i]]=min(dp[a[i]],c[i]);


    }
     map<int,int>::iterator it;
      for(int i=0;i<n;i++){
     for(it=dp.begin();it!=dp.end();it++){

            ll t=gcd(it->first,a[i]);
            if(dp.find(t)==dp.end()) dp[t]=c[i]+it->second;
            else dp[t]=min(dp[t],c[i]+it->second);
         }
     }
     if(dp.find(1)!=dp.end())
       cout<<dp[1]<<endl;
    else cout<<-1<<endl;
  }
}

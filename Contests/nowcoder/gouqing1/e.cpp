#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v;
int main()
{
 
    int n;ll m;
    ll x;
    while(scanf("%d%lld",&n,&m)==2)
    {
      
    for(int i=1;i<=n;i++)
     scanf("%lld",&x),v.push_back(x);
    
     sort(v.begin(),v.end());
     ll pre=-1e9-10;
     int cnt=0;
     for(int i=0;i<v.size();i++)
     {
         if(v[i]-pre>m)
          cnt++;
          pre=v[i];
     }
   printf("%d\n",cnt);   
}
}
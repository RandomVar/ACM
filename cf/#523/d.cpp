#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
const ll mod=1e9+7; 
struct node
{
    ll l,r;
    bool operator<(const node &b)const
    {
        if(l==b.l) return r<b.r;
        return l<b.l;
    }
}a[maxn];
int main()
{
   int n;ll x,y;
   while(cin>>n>>x>>y)
   {
       for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
      sort(a+1,a+1+n);
      map<ll,int>mp;
      map<ll,int>::reverse_iterator rit;
      map<ll,int>::iterator it;
      ll ans=0;
      for(int i=1;i<=n;i++)
      {
          int flag=0;
          if(mp.size())
          {
            it=mp.lower_bound(a[i].l);
            if(it!=mp.begin())
            {
               it--;
              if(a[i].l>it->first&&y*(a[i].l-it->first)<x)
             {
                 ans=(ans+y*(a[i].r-it->first)%mod)%mod;
                 it->second--;
                 if(it->second==0)
                   mp.erase(it);
                mp[a[i].r]++;
               flag=1;
             }
            }
          }
        if(!flag)
        {
           ans=((ans+x)%mod+y*(a[i].r-a[i].l)%mod)%mod;
           mp[a[i].r]++;
        }
        //cout<<ans<<endl;
       }
      cout<<ans<<endl;
   } 
  
}
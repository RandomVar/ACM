#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
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
const int maxn=6*1e5+100;
int l[maxn],r[maxn];
int cnt[maxn];
vector<int>v;
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       int l,r;
       int latel2=-1,latel=-1;
       int firstr2=1e9+10,firstr=1e9+10;
       int flag=0;
      for(int i=1;i<=n;i++)
        {
            cin>>l>>r;
            if(latel<l)
            {
                latel2=latel;
                latel=l;
              flag=0;
            }
            else if(latel2<l)
            latel2=l;
            if(firstr>r)
            {
                firstr2=firstr;
                firstr=r;
              flag=0;
            }
            else if(firstr2>r)
             firstr2=r;
          if(latel==l&&firstr==r)
           flag=1;
        }
      //  cout<<firstr2<<" "<<latel2<<endl;
      int ans=0;
      ans=max(ans,firstr2-latel);
      ans=max(ans,firstr-latel2);
      if(flag) ans=max(ans,firstr2-latel2);
      cout<<ans<<endl;
    //  mem(cnt,0);
  /*  v.clear();
       for(int i=1;i<=n;i++)
         {
            cin>>l[i]>>r[i];
            v.pb(l[i]);v.pb(r[i]);
         }
         sort(v.begin(),v.end());
         v.erase(unique(v.begin(),v.end()),v.end());
         int m=v.size();
        /* for(int i=1;i<=n;i++)
         {
             cnt[getid(l[i])]++;
             cnt[getid(r[i])]--;
         }
         int ans=0;
         int pre=-1;
         int ge=0;
         for(int i=1;i<=m;i++)
         {
             ge+=cnt[i];
             if(ge>=n-1)
              {
                 
                    // if(pre==-1) pre=v[i-1];
              }
            else {
                if(pre!=-1) ans=max(ans,v[i-1]-pre);
                cout<<v[i-1]<<" "<<pre<<endl;
                pre=-1;
             }
         }*/
        // printf("%d\n",ans);
   }
 return 0;
  }


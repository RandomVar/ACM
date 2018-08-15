#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
ll a[110];
int cnt[45][45];
int l;
ll ona;
void init()
{
    int tot=0;
    for (int i = 0;i<=2*l;++i) {
      for (int j = 0; j <= i; ++j) { 
         cnt[j][i - j] =tot;
        tot = (tot  + 1) % l;
    }
    }
    ona=0;
    for(int i=0;i<l;i++)
      for(int j=0;j<l;j++)
        ona+=a[cnt[i][j]];
}

ll sovle(int x,int y)
{
    ll ans=0;
    int x1=x/l;
    int y1=y/l;
    ans+=1LL*x1*y1*ona;
   // cout<<ona<<endl;
    int x2=x%l+1;
    int y2=y%l+1;
   // cout<<ans<<endl;
    if(x2)
    {
        ll c=0;
        for(int i=0;i<x2;i++)
          for(int j=0;j<l;j++)
            c+=a[cnt[i][j]];
        ans+=1LL*y1*c;
    }
   // cout<<ans<<endl;
    if(y2)
    {
        ll c=0;
      for(int i=0;i<l;i++)
        for(int j=0;j<y2;j++)
           c+=a[cnt[i][j]];
      ans+=1LL*x1*c;
    }
  //  cout<<ans<<endl;
    if(x2&&y2)
    {
        for(int i=0;i<x2;i++)
          for(int j=0;j<y2;j++)
            ans+=a[cnt[i][j]];
    }
  //  cout<<ans<<endl;
    return ans;
}

int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l;
        for(int i=0;i<l;i++)
          cin>>a[i];
        for(int i=l;i<2*l;i++)
        a[i]=a[i-l];
        l*=2;
          init();
          int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int x0,y0,x1,y1;
            cin>>x0>>y0>>x1>>y1;
            ll a1=0,a2=0,a3=0,a4=0;
            a1=sovle(x1,y1);
           // cout<<a1<<endl;
            if(x0) a2=sovle(x0-1,y1);
            if(y0) a3=sovle(x1,y0-1);
            if(x0&&y0) a4=sovle(x0-1,y0-1);
             cout<<a1-a3-a2+a4<<endl; 
      
        }

    }

 return 0;
  }


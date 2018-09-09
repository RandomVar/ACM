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
const int maxn=5e4+100;
struct node
{
  int x,y;
}a[maxn];
int cmp1(node &a,node &b)
{
  if(a.x>b.x) return 1;
  if(a.x<b.x) return 0;
  if(a.y>=b.y) return 1;
  return 0;
}
int cmp2(node &a,node &b)
{
  if(a.y>b.y) return 1;
  if(a.y<b.y) return 0;
  if(a.x>=b.x) return 1;
  return 0;
}

int main(){
  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(scanf("%d",&n)==1)
  {
    for(int i=1;i<=n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].y);//,v.pb(a[i].x);
    }
    ll ans=0;
    ans=a[n].x+a[n].y;
    map<int,int>sx;
    map<int,int>sy;
    map<int,int>::iterator it;
    sx[a[n].x]=a[n].y;
    sy[a[n].y]=a[n].x;
    for(int i=n-1;i>=1;i--)
    {
      it=sx.lower_bound(a[i].x);
     if(it==sx.end())
        ans+=a[i].y;
     else
       ans+=max(0,a[i].y-it->sec);
      sx[a[i].x]=max(sx[a[i].x],a[i].y);
      it=sy.lower_bound(a[i].y);
      if(it==sy.end())
          ans+=a[i].x;
      else
         ans+=max(0,a[i].x-it->sec);
      sy[a[i].y]=max(sy[a[i].y],a[i].x);
    }
    printf("%lld\n",ans);


  }
 return 0;
  }

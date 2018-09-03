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
const int maxn=1e5+100;
struct node
{
    ll s,v;
    bool operator<(const node &b)const
    {
        return s<b.s;
    }
}a[maxn];
int st[maxn];
int uppbound(int n,int x)
{
    int l=0;int r=n;
  /*while(l<=r)  
 {
   int mid=(l+r)/2;
   if(a[st[mid]].v>=a[x].v)  l=mid+1;
   else  r=mid-1;
 }
  return l;*/
  while(l<=r)  
  {
   int mid=(l+r)/2;
   if(ok)  l=mid+1;
   else  r=mid-1;
  }
  return l;
	 

}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
         scanf("%lld%lld",&a[i].s,&a[i].v);
        sort(a+1,a+1+n);
        int top=0;
        st[top]=n;
        double ans=0;
        for(int i=n-1;i>=1;i--)
        {
            // if(i==1) cout<<pre.s<<" "<<a[i].v<<" "<<pre.v<<endl;
          if(a[i].v<a[st[top]].v)
            {
                st[++top]=i;
            }
        else if(a[i].v==a[st[top]].v)
          continue;
            else
            {
                int p=uppbound(top,i);
                //cout<<i<<" "<<st[p]<<endl;
            double  xx=(((a[st[p]].s-a[i].s)*1.0)/(double(a[i].v-a[st[p]].v)));
            //   cout<<i<<" "<<xx<<endl;
              ans=max(ans,xx);
            //   cout<<ans<<" "<<pre.s<<" "<<a[i].s<<endl;
            //   pre=a[i];

            }
        }
        printf("%.6lf\n",ans);
    }
 return 0;
  }


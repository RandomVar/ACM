/*
TLE
复杂度为o(佛系)
*/

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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
struct node{
    ll c;int x;int y;
    bool operator<(const node &b)const{
        return c<b.c;
    }
};
const int maxn=5e5+100;
ll a[maxn];
ll b[maxn];
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n;ll l;
       scanf("%d%lld",&n,&l);
       priority_queue<node>que;

       for(int i=1;i<=n;i++)
       {
           scanf("%lld",&a[i]);
       }
       for(int i=1;i<=n;i++)
            scanf("%lld",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for(int i=1;i<=n;i++)
        {
          ll c=(a[i]-b[i]+l)%l;
          if(c>l/2) c=l-c;
          que.push(node{c,i,i});
        }
        while(1)
        {
            node t1=que.top();
            que.pop();
            node t2=que.top();
            que.pop();
            if(t1.c+t2.c<=l/2) 
            {
                que.push(t1);
                que.push(t2);
                break;
            }
            ll x=(a[t1.x]-b[t2.y]+l)%l;
            if(x>l/2) x=l-x;
            ll y=(a[t2.x]-b[t1.y]+l)%l;
            if(y>l/2) y=l-y;
            que.push(node{x,t1.x,t2.y});
            que.push(node{y,t2.x,t1.y});
        }
        ll ans=0;
        while(!que.empty())
        {
            node t=que.top();
            que.pop();
            ans+=t.c;
        }
        printf("%lld\n",ans);

   }
 return 0;
  }


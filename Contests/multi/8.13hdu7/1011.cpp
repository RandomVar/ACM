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
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int j=1;j<=k;j++)
         scanf("%lld",&c[j]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
              scanf("%lld",&s[j][i].a);
           
            for(int j=1;j<=k;j++)
              scanf("%lld",&s[j][i].b);
         s[j][i].id=i;
        }
        for(int j=1;j<=k;j++)
        {
            sort(s[j]+1,s[j]+n+1);
            pre[j]=0;
        }
        while(1)
        {
             for(int j=1;j<=k;j++)
             {
              int p=upper_bound(s[j]+pre[j]+1,s[j]+n+1,c[j])-s[j];
              for(int i=pre[j]+1;i<p;i++)
                b[j].set(s[j][i].id);
                pre[j]=p-1;
             }
            for(int j=1;j<=k;j++)
            {
                xx=xx&b[j];
            }
            

            for(int j=1;j<=k;j++)
            {
                b[j]&=(~xx);
            }

        }
    
    }
 return 0;
  }

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
char s[(1<<18)+10];
ll dfs(int n,int *s)
{
    if(n==0&&s[0]==1) return 1;
    if(n==0&&s[0]==0) return 0;
    int b[(1<<(n-1))+10];
    int flag=0;
    ll ans=0;
    for(int i=0;i<(1<<n);i+=2)
        b[i/2]=(s[i]&s[i+1]),flag|=b[i/2];
    if(flag)  ans+=dfs(n-1,b);

    flag=0;
    for(int i=0;i<(1<<n);i+=2)
        b[i/2]=(s[i]|s[i+1]),flag|=b[i/2];
    if(flag)  ans+=dfs(n-1,b);

    flag=0;
    for(int i=0;i<(1<<n);i+=2)
         b[i/2]=(s[i]^s[i+1]),flag|=b[i/2];
    if(flag)  ans+=dfs(n-1,b);
     return ans;
}
int main(){

  // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1)
   {
       scanf("%s",s);
       int a[(1<<n)+10];
       for(int i=0;i<(1<<n);i++)
        a[i]=s[i]-'0';
       printf("%lld\n",dfs(n,a));
   }


 return 0;
  }


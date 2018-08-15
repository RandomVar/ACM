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
const int maxn=1000010;
char s[maxn];
int ans[3][maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(scanf("%d%d",&n,&m)==2)
  {
      mem(ans,-1);
      scanf("%s",s);
      int k=0;int k2=0;
      for(int i=0;i<n;i++)
      {
          if(s[i]=='R') ans[0][++k]=i+1;
          else ans[1][++k2]=i+1;
      }
      char q[5];int d;
      for(int i=1;i<=m;i++)
      {
          scanf("%s",q);
          scanf("%d",&d);
          if(q[0]=='R')
          {
              printf("%d\n",ans[0][d]);
          }
          else printf("%d\n",ans[1][d]);
      }
  }
 return 0;
  }

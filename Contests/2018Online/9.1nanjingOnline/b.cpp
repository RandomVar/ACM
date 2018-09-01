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
const int maxn=1e5+10;
int mp[105][maxn];
int you[105][maxn];
pair<int,ll>st[105];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  int cas=0;
  while(t--)
  {
      mem(mp,0);
      mem(you,0);
      int n,m,k;
      scanf("%d%d%d",&m,&n,&k);
      for(int i=1;i<=k;i++)
      {
          int x,y;
          scanf("%d%d",&y,&x);
          mp[x][y]=1;
      }
      ll ans=0;
      for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        {
           if(mp[i][j]==0) 
              you[i][j]=you[i][j+1]+1;
        }
   for(int j=1;j<=m;j++)
  {
      ll sum=0;
      int top=-1;
     for(int i=n;i>=1;i--)
    {
       if(mp[i][j]==1) {top=-1;sum=0;continue;}
       ll cnt=0;
       while(top!=-1&&st[top].fir>=you[i][j])
         cnt+=st[top].sec,sum-=st[top].sec*st[top].fir,top--;
         //cout<<"*"<<sum<<endl;
       st[++top].fir=you[i][j];
       st[top].sec=cnt+1;
       sum+=you[i][j]*(cnt+1);
      // cout<<i<<" "<<j<<" "<<sum<<" "<<you[i][j]<<endl;
       ans+=sum;
    }
  }


printf("Case #%d: %lld\n",++cas,ans);
      
  }
 return 0;
  }

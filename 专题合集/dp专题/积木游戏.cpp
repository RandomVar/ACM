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
const int maxn=120;
struct node
{
    int a,b,c;
}s[maxn];
int dp[maxn][maxn][maxn][4];
int ok(int x,int a,int y,int b)
{
    int xx,xy;int yx,yy;
    if(a==1)
       xx=s[x].a,xy=s[x].b;
     if(a==2)
       xx=s[x].a,xy=s[x].c;
    if(a==3)
      xx=s[x].c,xy=s[x].b;
     
      if(b==1)
       yx=s[y].a,yy=s[y].b;
     if(b==2)
       yx=s[y].a,yy=s[y].c;
    if(b==3)
      yx=s[y].c,yy=s[y].b;

    //   if(xx>xy) swap(xx,xy);
    //   if(yx>yy) swap(yx,yy); 
    
    if(xx>=yx&&xy>=yy) return 1;
    if(xx>=yy&&xy>=yx) return 1;
    return 0;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
        }
        mem(dp,0);
        for(int i=m;i>=1;i--)
         for(int j=n;j>=1;j--)
            for(int k=j;k>=1;k--)
              for(int a=1;a<=3;a++)
            {
                int c;
                if(a==1) c=s[j].c;
                if(a==2) c=s[j].b;
                if(a==3) c=s[j].a;
                dp[i][j][k][a]=max(dp[i][j][k][a],dp[i][j+1][k][a]);
                for(int b=1;b<=3;b++)
                  {
                     dp[i][j][k][a]=max(dp[i][j][k][a],dp[i+1][j+1][j+1][b]+c);
                  if(ok(k,a,j+1,b))  
                      dp[i][j][k][a]=max(dp[i][j][k][a],dp[i][j+1][j+1][b]+c);
                  }
            }
        int ans=0;
    //  for(int j=1;j<=n;j++)
        for(int i=1;i<=3;i++)
         ans=max(ans,dp[1][1][1][i]);
        printf("%d\n",ans);
    }
 return 0;
  }


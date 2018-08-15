/*
https://blog.csdn.net/cqbzwja/article/details/50916994

n个人排队要乘艘船。若ij在同一艘船中，i对j有不满意度U(i,j)
问，如何安排使得总不满度最小。n<=4000

dp有单调性，可用四边形不等式优化
https://blog.csdn.net/noiau/article/details/72514812

四边形不等式优化DP证明
https://wenku.baidu.com/view/c44cd84733687e21af45a906.html

四边形不等式优化DP：
形如 dp(i,j)=min{dp(i,k)+dp(k,j)+w(i,j)}
只需证明
w为满足四边形不等式,即w(i,j)+w(i+1,j+1)<=w(i+1,j)+w(i,j+1)
即证明 f(j)=w(i+1,j)-w(i,j) 单调递减
即证明 w(i2,j)<=w(i,j2) i<=i2<j<=j2

可以证明若w满足四边形不等式，则dp也满足四边形不等式，则
定义s(i,j)=max{dp(i,j)},s(i,j)具有单调性
即 s(i,j)<=s(i,j+1)<=s(i+1,j+1)
也写为 s(i,j-1)<=s(i,j)<=s(i+1,j)

四边形不等式优化可以将复杂度从o(n^3)降为o(n^2)

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
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
template <class T> inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9'))
        c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9')
        ret=ret*10+(c-'0');
    ret*=sgn;
    return 1; }

inline void out(ll x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
   }
const int maxn=4010;
int a[maxn][maxn],w[maxn][maxn];
int dp[maxn][maxn],s[maxn][maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(scan_d(n))
  {
      scan_d(m);
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
     scan_d(a[i][j]);
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
       a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i=1;i<=n;i++)
     for(int j=i;j<=n;j++)
      w[i][j]=(a[j][j]-a[j][i-1]-a[i-1][j]+a[i-1][i-1])/2;
    mem(dp,0x3f);
    for(int i=1;i<=n;i++)
      dp[1][i]=w[1][i],s[1][i]=0;
    for(int i=2;i<=m;i++)
    {
        s[i][n+1]=n;
      for(int j=n;j>=i;j--)
        for(int k=s[i-1][j];k<=s[i][j+1];k++)
        {
            if(dp[i-1][k]+w[k+1][j]<dp[i][j])
            dp[i][j]=dp[i-1][k]+w[k+1][j],s[i][j]=k;
        }
    }
    out(dp[m][n]);
   putchar('\n');
  }
 return 0;
  }


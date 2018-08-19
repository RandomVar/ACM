/*
http://www.cnblogs.com/zhouzhendong/p/NowCoder-2018-Summer-Round4-B.html

给出n个带权区间，选择若干区间，覆盖[1,m]，使得每个位置被覆盖权值和的最大值最小 n, m <= 2000

可知 任何一个点最多被两个线段覆盖
dp（i,j）表示最右端的一条线段为 i，上一个线段的结尾的坐标不大于j,[1, j]覆盖权值和最大值的最小值 
o（n^2)dp

带优化的
https://www.nowcoder.com/discuss/88842?type=101&order=0&pos=4&page=1

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
const int maxn=2e3+100;
int dp[maxn][maxn];
struct node{
    int l,r,w;
    bool operator<(const node &b)const{
        if(l==b.l) return r<b.r;
        return l<b.l;
    }
}a[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
       for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
        }
        sort(a+1,a+1+n);
        mem(dp,0x3f);
        mem(dp[0],0);
        int ans=inf;
        a[0].l=a[0].r=a[0].w=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j].r+1<a[i].l||a[i].r<=a[j].r)
                  continue;
                int v=dp[j][a[i].l-1];
                if(a[j].r+1==a[i].l) 
                  v=max(v,a[i].w);
                else v=max(v,a[i].w+a[j].w);
                 dp[i][a[j].r]=min(dp[i][a[j].r],v);
            }
    
           for(int j=1;j<=m;j++)
             dp[i][j]=min(dp[i][j],dp[i][j-1]);//cout<<dp[i][j]<<endl;
            if(a[i].r==m)
              ans=min(ans,dp[i][m]);
         }
         if(ans==inf) printf("-1\n");
         else printf("%d\n",ans);

    }
 return 0;
  }


/*
长为n的字符串删除m个字符后的不同序列数 m<=10

dp[i][j]为前i个删除j个字符后的不同序列种数
dp[i][j]=dp[i-1][j]+dp[i-1][j-1]
删去重复的字符串:
dp[i][j]-=dp[pre[i]-1][pre[i]+j-i]//从上一个与s[i]相同的字符开始转移

初始值需要思考一下

方法二:
https://www.nowcoder.com/discuss/87183?type=101&order=0&pos=12&page=0
dp[j][i]为长度为j，以字母i结尾的不同序列种数
sum[j]为长度为i的序列种数
dp[j][i]等于长度为j-1的所有序列种数之和(sum[j-1])//最后一个字母限定
sum[j]每次等于前一轮的sum[j]（不取s[i]），加上前一轮的sum[j-1]（取s[i])，
取了s[i]之后需要去重，重复的个数就是之前长度为j，以s[i]结尾的种类数（dp[j][s[i]]）

for(int i=1;i<=n;i++){//每次增加一个字符
    for(int j=i;j>=1&&j>=i-m-1;j--){//从长到短枚举子序列长度，这里只需要维护最后m个就行了，保险起见我多维护了一个数。
        sum[j]+=(sum[j-1]-dp[j][s[i]])%mod;
        sum[j]%=mod;
        dp[j][s[i]]=sum[j-1];
    }
}
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int mod=1e9+7;
const int maxn=1e5+100;
ll dp[maxn][15];
int mp[15];
int pre[maxn];
int s[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m,k;
   while(scanf("%d%d%d",&n,&m,&k)==3)
   {
       fill(pre,pre+n+1,0);
       mem(mp,0);
       for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
         if(mp[s[i]])
           pre[i]=mp[s[i]];
        mp[s[i]]=i;
       }

    for(int i=0;i<=n;i++)
       mem(dp[i],0);
     dp[1][1]=1;
     for(int i=0;i<=n;i++)
       dp[i][0]=1;
  
      for(int i=2;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
             if(j)
              dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
               if(pre[i]&&pre[i]+j-i>=0)
                   dp[i][j]=(dp[i][j]-dp[pre[i]-1][pre[i]+j-i]+mod)%mod;
           //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
         }
      }
      printf("%lld\n",dp[n][m]);
   }

 return 0;
  }

  /**
   3 2 2
   1 2 2
   4 2 2
   1 2 1 2


2 1 2
2 2 1
3 1 3
3 2 3
4 1 4
4 2 5
  */


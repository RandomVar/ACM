/*http://www.cnblogs.com/kuangbin/archive/2011/08/04/2127085.html
滚动数组，用prevdp保存前一状态的最大值
Status[i][j]表示前i个数在选取第i个数的前提下分成j段的最大值，
状态转移方程为：
Status[i][j]=Max(Status[i-1][j]+Num[i]，Max(Status[0][j-1]~Status[i-1][j-1])+Num[i])
其中Max(Status[0][j-1]~Status[i-1][j-1])就保存在predev中*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000010];
int dp[2][1000010];
int pre[1000010];
#define MIN 0x80000000//32位int的最小值
int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)==2){

		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		int maxsum=MIN;
		for(int i=1;i<=n;i++)
           for(int j=1;j<=min(i,m);j++){
              dp[n%2][j]=max(dp[(n%2)&1][j]+a[i],pre[i-1]+a[i]);
              pre[i-1]=max(pre[i-1],dp[n%2][j]);
              maxsum=max(dp[n%2][j],maxsum);
        }
		/*for(int i=1;i<=m;i++){
		   maxsum=MIN;
			for(j=i;j<=n;j++){
				currdp[j]=max(currdp[j-1],prevdp[j-1])+a[j];
				prevdp[j-1]=maxsum;
				maxsum=max(maxsum,currdp[j]);
			}
			prevdp[j-1]=maxsum;
		}*/
		printf("%d\n",maxsum);
	}
	return 0;
}

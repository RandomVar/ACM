/*http://www.cnblogs.com/kuangbin/archive/2011/08/04/2127085.html
�������飬��prevdp����ǰһ״̬�����ֵ
Status[i][j]��ʾǰi������ѡȡ��i������ǰ���·ֳ�j�ε����ֵ��
״̬ת�Ʒ���Ϊ��
Status[i][j]=Max(Status[i-1][j]+Num[i]��Max(Status[0][j-1]~Status[i-1][j-1])+Num[i])
����Max(Status[0][j-1]~Status[i-1][j-1])�ͱ�����predev��*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000010];
int dp[2][1000010];
int pre[1000010];
#define MIN 0x80000000//32λint����Сֵ
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

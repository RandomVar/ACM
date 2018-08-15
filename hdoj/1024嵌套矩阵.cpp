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
int currdp[1000010];
int prevdp[1000010];
#define MIN 0x80000000//32位int的最小值 
int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)==2){
		int maxsum;int j;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(currdp,0,sizeof(currdp));
		memset(prevdp,0,sizeof(prevdp));
		for(int i=1;i<=m;i++){
		   maxsum=MIN;
			for(j=i;j<=n;j++){
				currdp[j]=max(currdp[j-1],prevdp[j-1])+a[j];
				prevdp[j-1]=maxsum;
				maxsum=max(maxsum,currdp[j]);
			}
			prevdp[j-1]=maxsum;
		}
		printf("%d\n",maxsum);
	}
	return 0;
}

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
int currdp[1000010];
int prevdp[1000010];
#define MIN 0x80000000//32λint����Сֵ 
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

//dp[i][j]=max dp[k][j-1]+w[j]*x[i]
//���ڵ�i������j������ 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int c;int g;int count;
	int x[25];int w[25];
	int dp[25][25];
	while(cin>>c>>g){
		count=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=c;i++) cin>>x[i];
		for(int i=1;i<=g;i++)  cin>>w[i];
		for(int j=1;j<=g;j++){
			for(int i=1;i<=c;i++){
				int min=0x3f3f3f3f;
				for(int k=1;k<=c;k++){
				  int y=dp[k][j-1]+w[j]*x[i]-0;
				  if(abs(y)<min) min=y;
			}
			  dp[i][j]=min;
			}
		} 
	/*	for(int i=1;i<=c;i++) {//��һ���ŵ�λ��Ϊi 
		   if(dp[i][g]==0) {
			for(int j=1;j<=g;j++) //�Ӻ���ǰ��j�� 
			  for(int k=1;k<=c;k++)//��ǰ����ŵ�λ��Ϊk 
			       if(dp[k][g-j]+w[g-j+1]*x[i]==dp[i][g-j+1]) t++;
	}}*/
	for(int i=1;i<=c;i++)if(dp[i][g]==0) count++;
	cout<<dp[1][g]<<dp[2][g];
		cout<<count<<endl;
	}
	return 0;
} 



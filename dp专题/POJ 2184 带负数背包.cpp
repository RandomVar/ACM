/*
�������Ĺؼ������㣺һ�ǽ�smartness�������ѡ���funness������ֵ��
�Ӷ�ת��Ϊ01���������ǶԸ�ֵ�Ĵ�������һ��shift����ʾ��0������
���shiftһ��Ҫ����ÿһ��smartness�ľ���ֵ����
���ڱ���cost[]��ʱ�����cost[i]>0����Ȼʱ�ӿ�����������ֵmaxm ��ʼ���¼���
���cost[i]<0�����Ǵ�0����0������shift����ʼ�������ӡ���
��0����������뵽��С��0������ȽϷѽ⣬��Ҫ��ϸ˼����
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2e5+2e4;
const int shitf=1e4+10;
int s[110];
int f[110]; 
int dp[maxn+10];
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
		  cin>>s[i]>>f[i];
		fill(dp,dp+maxn,-INF);
		dp[shitf]=0;
		for(int i=1;i<=n;i++){
			if(s[i]>0){
		     for(int j=maxn-1;j>=s[i];j--)
		       dp[j]=max(dp[j],dp[j-s[i]]+f[i]);}
		    else{
		    	for(int j=0;j<maxn+s[i];j++)
		    	  dp[j]=max(dp[j],dp[j-s[i]]+f[i]);}
			}
		int ans=0;
		for(int i=shitf;i<maxn;i++){
			if(dp[i]>0) ans=max(ans,i-shitf+dp[i]);
		}
		cout<<ans<<endl;    
	}
}

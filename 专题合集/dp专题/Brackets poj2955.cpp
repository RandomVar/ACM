/*�����������dp��dp[i][j]��ʾ i~j �����ڵ����ƥ������
���ȼ���s[i]��s[j]��ƥ��,s[i][j]=s[i+1][j],
Ȼ��������k(i+1~j)֮��Ѱ��s[i]��s[k]ƥ�䣬
״̬ת�� dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k+1][j]+2);*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int dp[110][110]; 
int main(){
	string s;
	while(1){
		getline(cin,s);
		int len=s.size();
		if(s.compare("end")==0) break;
		memset(dp,0,sizeof(dp));
		for(int i=len-2;i>=0;i--){
			for(int j=i+1;j<len;j++){
				dp[i][j]=dp[i+1][j];
			  for(int k=i+1;k<=j;k++){
			  	if(s[i]=='('&&s[k]==')'||s[i]=='['&&s[k]==']')
			  	dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k+1][j]+2);
			  }
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
} 

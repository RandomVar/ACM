/* dp[n][m]��ʾ���� n �Ļ����У�ÿ���������� m �Ļ�������
           �򻮷������Է�Ϊ�������:
           a. ������ÿ������С�� m�� �൱��ÿ���������� m- 1, ��
              ������Ϊ dp[n][m-1].
           b. ��������һ����Ϊ m. �Ǿ��� n�м�ȥ m , ʣ�µľ��൱
              �ڰ� n-m ���л��֣� �ʻ�����Ϊ dp[n-m][m];
������д���ƴ��
http://www.cnblogs.com/kuangbin/archive/2012/09/20/2695165.html
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll a[1010][110];
ll b[1010][110];
int main(){
	int n,k;
	cin>>n>>k;
	ll inf=1;
	for(int i=0;i<18;i++) inf*=10;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<=k;i++)
		  a[0][i]=1;
		for(int j=1;j<=k;j++)
	      for(int i=1;i<=n;i++)
	      {
	        if(i>=j) {
			  a[i][j]=(a[i-j][j]+a[i][j-1])%inf;
			  b[i][j]=b[i-j][j]+b[i][j-1]+(a[i-j][j]+a[i][j-1])/inf;
		    }
	        else { a[i][j]=a[i][j-1];
			       b[i][j]=b[i][j-1];}}
		if(b[n][k]!=0) cout<<b[n][k];
		cout<<a[n][k]<<endl;
}

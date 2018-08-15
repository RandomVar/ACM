/* dp[n][m]表示整数 n 的划分中，每个数不大于 m 的划分数。
           则划分数可以分为两种情况:
           a. 划分中每个数都小于 m， 相当于每个数不大于 m- 1, 故
              划分数为 dp[n][m-1].
           b. 划分中有一个数为 m. 那就在 n中减去 m , 剩下的就相当
              于把 n-m 进行划分， 故划分数为 dp[n-m][m];
还需进行大数拼接
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

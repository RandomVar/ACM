#include<iostream>
#include<cstring>
using namespace std;
int dp[20][2];
int a[20];
int dfs(int pos,int pre,int sta,bool limit)
{
	if(pos == -1)
		return 1;
	if(!limit && dp[pos][sta] != -1)
		return dp[pos][sta];
	int up = limit ? a[pos] : 9;
	int ans = 0;
	for(int i =0;i<=up;i++)
	{
		if(pre == 6 && i == 2)
			continue;
		if(i==4) continue;
		ans += dfs(pos-1,i,i==6,limit&&i==a[pos]);
	}
	if(!limit)
		dp[pos][sta] = ans;
	return ans;
}
int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	memset(a,0,sizeof(a));
	int cnt = 0;
	while(n)
	{
		a[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt-1,-1,0,1);
}
int main()
{
	int n,m;
	while(cin >> n>>m&&n+m)
	{
		cout << solve(m)-solve(n-1) << endl;
	}
	return 0;
}

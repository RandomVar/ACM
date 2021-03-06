#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
int b[22];
int a[22][22];
int dp[1<<22];
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			cin>>b[i];
			for(int j=1;j<=b[i];j++)
			  cin>>a[i][j];
		}
		int cnt=0;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		/*背包计数，s在内层循环，一个个放；需要前面i-1个都放过，才为有效的
		最终输出的是放了n个时所有情况的总和*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=b[i];j++){
			 int t=a[i][j]-1;
		   for(int s=0;s<(1<<m);s++){
		   	 if(__builtin_popcount(s)==i-1&&(s&(1<<t))){
					 dp[s|(1<<t)]+=dp[s];
				}
			}
		}}
		int ans=0;  
        for(int i=0;i�(1<<m)�;i++)  
        if(__builtin_popcount(i)==n)  //用的内置函数，判断二进制中1的个数         
        ans+=dp[i];  
        printf("%d\n",ans);
	}
} 

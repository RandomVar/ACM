#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<cstring>
using namespace std;
int car[2][110];
int dp[510][510];
int dp2[510][510];
int w1,w2,w3,s1,s2,s3,d1,d2,d3,d4,c1,c2,c3;
int compute(int a,int b,int c){    //计算防御能力
     int minnum;
     minnum = min(min(a/c1,b/c2),c/c3);
    return (minnum * d4 + (a- minnum*c1)*d1 + (b- minnum*c2)*d2 + (c- minnum*c3)*d3);
}
int main(){
	int n;//n辆马车
	cin>>n;
	cin>>w1>>s1>>d1;
	cin>>w2>>s2>>d2;
	cin>>w3>>s3>>d3;
	cin>>c1>>c2>>c3>>d4;
	for(int i=0;i<n;i++)  cin>>car[0][i]>>car[1][i];
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	dp[0][0]=0;
	int curr_a=0;int curr_b=0;
	int k=n;
	while(k--){
		for(int i=0; i<= curr_a; i++)
        for(int j=0; j<=curr_b; j++){
           dp[i][j] = dp2[i][j];
              dp2[i][j] = -1;
                     }
		int r_a=min(car[0][k]/w1,car[1][k]/w2);
	for(int i=0;i<=curr_a;i++){
		int r_aw=car[0][k]-i*w1;//装了a之后剩下的 
		int r_as=car[1][k]-i*s1;
		int r_b=min(r_aw/w2,r_as/s2);//剩余装b 
		for(int j=0;j<=curr_b;j++){
			int r_bw=r_aw-j*w2;
			int r_bs=r_as-j*s2;
			int r_c=min(r_bw/w3,r_bs/s3);
			for(int x=0;x<=curr_a;x++){
				for(int y=0;y<=curr_b;y++){
					if(dp[x][y]>=0&&dp[x][y]+r_c>dp2[x+i][y+j])
					   dp2[x+i][y+j]=dp[x][y]+r_c;
				}
			}
			curr_a=min(car[0][k]/w1,car[1][k]/s1);
			curr_b=min(car[0][k]/w2,car[1][k]/s2);
			k++;
		}}}
		int ans=0;
		for(int i=0;i<=curr_a;i++){
			for(int j=0;j=curr_b;j++)
			  if(dp[i][j]!=-1) {
			  	int temp=compute(i,j,dp2[i][j]);
			  	if(temp>ans) ans=temp;
			  }
		}
	printf("Case %d: ",k);
		cout<<ans;
return 0;}

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int dp[100010][15];
int main(){
   int n;
   while(scanf("%d",&n)==1&&n){
        int maxt=0;
        memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        int x,t;
        scanf("%d%d",&x,&t);
        if(t==1&&x!=4&&x!=5&&x!=6) dp[t][x]=0;
        else dp[t][x]+=1;
        maxt=max(maxt,t);
    }
    for(int i=2;i<=maxt;i++){
        for(int x=0;x<=10;x++)
            dp[i][x]+=max(max(dp[i-1][x],dp[i-1][x+1]),x==0?0:dp[i-1][x-1]);
    }
    int ans=0;
     for(int x=0;x<=10;x++)
       ans=max(ans,dp[maxt][x]);
    printf("%d\n",ans);
   }
return 0;
}

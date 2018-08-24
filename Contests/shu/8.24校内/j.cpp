#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int n,m,k,x,y;
map<int,ll>dp[1005][1005];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
ll dfs(int stx,int sty,int k)
{
    if(dp[stx][sty][k]!=0) return dp[stx][sty][k];
    if(k == 0) return 1;
    ll ans = 0;
    for(int i = 0;i<4;i++)
    {
        int tox = stx+dx[i];
        int toy = sty+dy[i];
        if(tox <= 0 || toy<=0 || tox > n || toy>m) continue;
        ans +=dfs(tox,toy,k-1);
    }
    return dp[stx][sty][k] = ans%mod;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&n,&m,&k,&x,&y);
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
                dp[i][j].clear();
        }
        printf("%lld\n",dfs(n,m,k));
    }

}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+100;
ll dp[30][maxn];
int cnt[30];
char s[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        // cout<<1<<endl;
        scanf("%s",s);
        for(int i=0;i<k;i++)
        {
            cnt[s[i]-'A'+1]++;
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=26;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int c=0;c<=min(j,cnt[i]);c++)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-c]+1LL*c*(cnt[i]-c));
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        printf("%lld\n",dp[26][n]);
    }
}
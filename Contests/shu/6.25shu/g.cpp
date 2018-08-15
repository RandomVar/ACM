#include<bits/stdc++.h>
using namespace std;
char s[1100][1100];
int dp[1100][1100];
int main()
{
    int n, x, y, ans;
    while(scanf("%d", &n)==1&&n)
    {
        ans=0;

        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%s", s[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0||j==n-1)
                    dp[i][j]=1;
                x=i;y=j;
                while(x>=0&&j<n && s[x][j]==s[i][y])
                {
                    x--;
                    y++;
                }
                int m=i-x;
                if(m > dp[i-1][j+1])
                    dp[i][j] = dp[i-1][j+1] + 1;
                else
                    dp[i][j] = m;
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

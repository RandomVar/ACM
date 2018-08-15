#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[37][37][37][37];
int w[40];
ll pre[37][37][37][37];
int p[40],a[40],c[40],m[40],q[40];
int vis[40];
#define INF 0x3f3f3f3f
int main()
{
    int n;
    std::ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    while(cin>>n)
    {
        memset(dp,-1,sizeof(dp));
        memset(pre,0,sizeof(pre));
        vector<int>sta;
        for(int i = 1;i<=n;i++)
        {
            cin>>p[i]>>a[i]>>c[i]>>m[i]>>q[i];
            if(p[i] == 0 && a[i] == 0 && c[i] == 0 && m[i] == 0) vis[i] = 1,sta.push_back(i);
            else vis[i] = 0;
            //int sum = 0;
        }
        int P,A,C,M;
        cin>>P>>A>>C>>M;
        dp[0][0][0][0] = 0;
        for(int i = 1;i<=n;i++)
        {
            if(vis[i]) continue;
            for(int j = P;j>=p[i];j--)
            {
                for(int k = A;k>=a[i];k--)
                {
                    for(int o = C;o>=c[i];o--)
                    {
                        for(int l = M;l>=m[i];l--)
                        {
                             if(pre[j-p[i]][k-a[i]][o-c[i]][l-m[i]]&(1LL<<i)) continue;
                            if(dp[j-p[i]][k-a[i]][o-c[i]][l-m[i]] == -1) continue;
                            if(dp[j-p[i]][k-a[i]][o-c[i]][l-m[i]] + q[i] > dp[j][k][o][l])
                            {
                               
                                dp[j][k][o][l] = dp[j-p[i]][k-a[i]][o-c[i]][l-m[i]] + q[i];
                                pre[j][k][o][l] = pre[j-p[i]][k-a[i]][o-c[i]][l-m[i]]|(1LL<<i);
                            }
                        }
                    }
                }
            }
        }
        int a1 = 0,a2 = 0,a3 = 0,a4 = 0;
        for(int i = P;i>=0;i--)
        {
            for(int j = A;j>=0;j--)
            {
                for(int k = C;k>=0;k--)
                {
                    for(int l = M;l>=0;l--)
                    {
                        if(dp[i][j][k][l] > dp[a1][a2][a3][a4])
                        {
                            a1 = i,a2 = j,a3 = k,a4 = l;
                        }
                    }
                }
            }
        }

       /* while(pre[a1][a2][a3][a4]!=-1)
        {
            int i = pre[a1][a2][a3][a4];
            sta.push_back(pre[a1][a2][a3][a4]);
            a1-=p[i],a2-=a[i],a3-=c[i],a4-=m[i];
        }*/
        for(int i=1;i<=n;i++)
        {
            if(pre[a1][a2][a3][a4]&(1LL<<i))
              sta.push_back(i);
        }
        cout<<sta.size()<<endl;
        for(int i = 0;i<sta.size();i++)
        {
            if(i == sta.size()-1)
            cout<<sta[i]-1<<endl;
            else
            cout<<sta[i]-1<<" ";
        }
        //cout<<endl;
 
    }
}
/*
2
1 0 2 1 10
1 0 2 1 21
1 0 2 1
1
2 1 1 0 31
1 0 2 1
 
 
*/
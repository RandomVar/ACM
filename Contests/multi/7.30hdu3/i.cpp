/*
给定一个正整数序列 a[1..n]，每个数在 [1,m] a[i]=0表示a[i]未知。 
在未知数在 [1,m] 之间随机的情况下，求 v[gcd(ai,ai+1,ai+2,ai+3)]连乘的期望  1<=i<=n-3
4≤n≤100,1≤m≤100

设 f[i][x][y][z] 表示考虑前 i 个位置，ai=x, gcd(ai, ai−1)=y, gcd(ai, ai−1, ai−2)=z 时的期望积。 
枚举 ai+1 的值转移即可。 
时间复杂度 O(nmS)，其中 S 表示 (x, y, z) 的状态数。 
显然合法状态中 y|x, z|y，当 m = 100 即状态数最多时 S = 1471

*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod=1e9+7;
const int maxn=110;
ll g[maxn][maxn];
ll dv[maxn][maxn];
int cnt[maxn];
ll f[2][maxn][maxn][maxn];
ll a[maxn];
ll v[maxn];
ll inv[maxn];


void init()
{
  for(int i=1;i<maxn;i++)
    for(int j=1;j<maxn;j++)
      g[i][j]=__gcd(i,j);

 for(int i=1;i<maxn;i++) g[i][0]=g[0][i]=i;

 inv[1]=1;
 for(int i=2;i<maxn;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;


  for(int i=1;i<maxn;i++)
  {
    cnt[i]=0;
    for(int j=1;j<=i;j++)
    {
      if(i%j==0) dv[i][++cnt[i]]=j;
    }
  }

}

int main()
{
  init();
  //for(int i=1;i<=4;i++)
  // cout<<cnt[i]<<endl;
     int t;
     scanf("%d",&t);
     while(t--)
     {
         int n,m;
         scanf("%d%d",&n,&m);
         for(int i=1;i<=n;i++)
          scanf("%lld",&a[i]);
         for(int i=1;i<=m;i++)
          scanf("%lld",&v[i]);

      
        memset(f,0,sizeof(f));
        if(a[1]) f[1][a[1]][a[1]][a[1]]=1;
        else{
          for(int i=1;i<=m;i++)
            f[1][i][i][i]=inv[m];
        }
      //  cout<<f[1][1][1][1]<<endl;
        for(int i=2;i<=n;i++)
        {
           for(int x=1;x<=m;x++)
              for(int k=1;k<=cnt[x];k++)
                for(int e=1;e<=cnt[dv[x][k]];e++)
                {
                  int y=dv[x][k];
                   int z=dv[y][e];
                  // cout<<y<<z<<(i&1)<<endl;
                   f[(i&1)][x][y][z]=0;
                }

            for(int x=1;x<=m;x++)
              for(int k=1;k<=cnt[x];k++)
                for(int e=1;e<=cnt[dv[x][k]];e++)
                 {
                   int y=dv[x][k];
                   int z=dv[y][e];
                   ll tmp=f[1^(i&1)][x][y][z];
                //  cout<<x<<y<<z<<(1^(i&1))<<endl;
                 // cout<<tmp<<endl;
                   if(a[i]==0) 
                   {
                     tmp=tmp*inv[m]%mod;
                    for(int c=1;c<=m;c++)
                    {
                      f[i&1][c][g[x][c]][g[y][c]]+=(i<=3)?tmp:(tmp*v[g[c][z]]%mod);
                      f[i&1][c][g[x][c]][g[y][c]]%=mod;
                    // cout<<f[i&1][c][g[x][c]][g[y][c]]<<endl;
                    }

                   }
                   else
                   {
                     f[i&1][a[i]][g[x][a[i]]][g[y][a[i]]]+=(i<=3)?tmp:(tmp*v[g[a[i]][z]]%mod);
                     f[i&1][a[i]][g[x][a[i]]][g[y][a[i]]]%=mod;
                   }               
                 }
                        
        }

        ll ans=0;
         for(int x=1;x<=m;x++)
              for(int k=1;k<=cnt[x];k++)
                for(int e=1;e<=cnt[dv[x][k]];e++)
                 {
                   int y=dv[x][k];
                   int z=dv[y][e];
                   ans=(ans+f[n&1][x][y][z])%mod;
                 }
            printf("%lld\n",ans);
     }
}
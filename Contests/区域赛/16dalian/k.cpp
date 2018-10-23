#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e6+100;
const int N=4002;
const ll mod=100000073;
ll sum[N][N];
int f[maxn];

void init()
{
    int pre=1;
    for(int i=1;i<maxn;i++)
  {
      while((pre*pre+pre)/2<i)
        pre++;
      f[i]=pre;
  }
  for(int i=0;i<N;i++)
    sum[i][0]=sum[i][i]=1;

       for(int i=1;i<N;i++)
          for(int j=1;j<i;j++)
           sum[i][j]=(sum[i][j-1]+sum[i-1][j])%mod;
}

int main()
{
    int a,b;
    init();
    while(scanf("%d%d",&a,&b)==2)
    {
        int x=b-a+1;
        int y=(f[x]*f[x]+f[x])/2-x;
        printf("%d %lld\n",f[x],sum[f[x]][y]);
    }
    return 0;
}
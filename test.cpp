#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5010;
ll a[maxn];
int pos[maxn];
int f[maxn];
int mp[maxn];
int judge(int s,int t)
{
    ll x=a[s]*a[t];
    if(x<0) return 0;
    ll c=sqrt(x);
    if(c*c!=x) return 0;
 
 return 1;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(f,0,sizeof(f));
        memset(pos,0,sizeof(pos));
        for(int i=1;i<=n;i++)
         scanf("%lld",&a[i]);
        int k=0;
        for(int i=1;i<=n;i++)
         {
             if(pos[i]) continue;
            pos[i]=++k;
           for(int j=i+1;j<=n;i++)
           {
             if(judge(i,j))
               pos[j]=k;
           }
         }
       for(int i=1;i<=n;i++)
       {
           int cnt=0;
           memset(mp,0,sizeof(int)*(k+3));
        for(int j=i;j<=n;j++)
        {
            if(!mp[pos[j]])
              {
                  cnt++;
                  mp[pos[j]]=1;
              }
            f[cnt]++;
         }
       }
        for(int i=1;i<=n;i++)
          printf("%d%c",f[i],i==n?'\n':' ');

    }
}
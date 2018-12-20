#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int cnt[maxn];
void init()
{
      ll ans=1;
        cnt[0]=0;
        for(int i=1;i<maxn;i++)
        {
          ans=(ans*2)%7;
          cnt[i]=cnt[i-1];
          if((ans+6)%7==0)
          {
            cnt[i]++;
          }
        }
}
int main()
{
    int t;int cas=0;
    scanf("%d",&t);
    init();
    while(t--)
    {
        int n;
        scanf("%d",&n);
       printf("Case #%d: %d\n",++cas,cnt[n]);
    }
}
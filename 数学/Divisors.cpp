#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define ll unsigned long long
using namespace std;
const int MAXN=500;

map<int,ll>::iterator it;

bool has[MAXN+1];
int prime[MAXN+1];
ll mp[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    memset(has,false,sizeof(has));
    for(int i=2;i<=MAXN;i++)
    {
        if(!has[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            has[prime[j]*i]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}

void cal1(int n)
{
    for(int i=1;i<=prime[0];i++)
    {
        int x=prime[i];
        while(n/x>0)
        {
            mp[i]+=n/x;
            x*=prime[i];
        }
    }
}
void cal2(int n)
{
    for(int i=1;i<=prime[0];i++)
    {
        int x=prime[i];
        while(n/x>0)
        {
            mp[i]-=n/x;
            x*=prime[i];
        }
    }
}
int main()
{
    int n,k;
    getPrime();
    while(scanf("%d%d",&n,&k)==2)
    {
       memset(mp,0,sizeof(mp));
        cal1(n);
        cal2(n-k);
        cal2(k);
        ll ans=1;
       for(int i=1;i<=prime[0];i++)
       {
           ans*=(1+mp[i]);
       }
       printf("%lld\n",ans);
       //cout<<ans<<endl;
    }
}
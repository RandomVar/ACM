/*TLE*/
#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
typedef long long ll;
const int maxn=1e5+10;
const int mod=(1<<30);

int N,M;
unsigned x,y,z,w;
unsigned f[15000008];
map<int,int>mp;
vector<int>v1[100008],v2[100008];
int cnt[maxn*4];
unsigned func()
{
    x=x^(x<<11);
    x=x^(x>>4);
    x=x^(x<<5);
    x=x^(x>>14);
    w=x^(y^z);
    x=y;
    y=z;
    z=w;
    return z;
}
ll ans;
void init()
{
    mp.clear();
    for(int i=1;i<=N;i++)
    {
        v1[i].clear();v2[i].clear();
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d%u%u%u",&N,&M,&x,&y,&z);
        for(int i=1;i<=M*3;i++)
            f[i]=func();
        //build(1,N,1);
        for(int i=1;i<=M;i++)
        {
            int t=f[i*3]%mod;
            v1[min(f[3*i-2]%N+1,f[3*i-1]%N+1)].push_back(t);
            v2[max(f[3*i-2]%N+1,f[3*i-1]%N+1)].push_back(t);
        }
       
        ans=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<v1[i].size();j++)
              mp[v1[i][j]]++;
            ans=ans^(1LL*i*mp.rbegin()->first);
            for(int j=0;j<v2[i].size();j++)
            {
                mp[v2[i][j]]--;
                if(mp[v2[i][j]]==0)
                  mp.erase(v2[i][j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
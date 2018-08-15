/*
TLE……
多一个  单调队列求max-min<=m的最大长度

*/
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
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e6+100;
int n;ll m;
typedef pair<int,ll> P;
vector<P>edge[maxn];
ll f[maxn][2];
ll ans[maxn];
int st1[maxn];int st2[maxn];
void dfs1(int u,int pre)
{
   for(int i=0;i<edge[u].size();i++)
   {
       int v=edge[u][i].fir;
       ll l=edge[u][i].sec;
       if(v==pre) continue;
       dfs1(v,u);
       ll x=f[v][0]+l;
       if(x>f[u][0])
       {
           f[u][1]=f[u][0];
           f[u][0]=x;
       }
       else if(x>f[u][1])
       {
           f[u][1]=x;
       }
   }
}
void dfs2(int u,int pre)
{
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i].fir;
        ll l=edge[u][i].sec;
        if(v==pre) continue;
        ans[v]=max(ans[u],(f[v][0]+l==f[u][0]?f[u][1]:f[u][0]))+l;
        dfs2(v,u);
    }
    ans[u]=max(ans[u],f[u][0]);
}
void init()
{
    for(int i=0;i<=n;i++)
     {
         edge[i].clear();
         f[i][0]=f[i][1]=ans[i]=0;
     }
}

int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(scanf("%d%lld",&n,&m)==2)
    {
        init();
        for(int i=2;i<=n;i++)
        {
            int u;ll l;
            scanf("%d%lld",&u,&l);
            //cin>>u>>l;
            edge[i].push_back(mpr(u,l));
            edge[u].push_back(mpr(i,l));
        }
        dfs1(1,0);
        dfs2(1,0);
       // for(int i=1;i<=n;i++)
         //cout<<ans[i]<<" ";
        // cout<<endl;
        int daan=0;
        int t1=-1;int s1=0;
        int t2=-1;int s2=0;
        int ss=1;
        for(int i=1;i<=n;i++)
        {
            while(t1>=s1&&ans[i]>=ans[st1[t1]])
               t1--;
            while(t2>=s2&&ans[i]<=ans[st2[t2]])
              t2--;
            st1[++t1]=i;
            st2[++t2]=i;
            if(ans[st1[s1]]-ans[st2[s2]]>m)
            {
                daan=max(daan,i-ss);
                if(st1[s1]<st2[s2])//尺取，不缩短长度
                  {
                      ss=st1[s1]+1;//从去掉这个之后的长度开始算
                      s1++; 
                  }
                else{
                    ss=st2[s2]+1;
                    s2++;
                }
            }
        }
       daan=max(daan,n+1-ss);
        printf("%d\n",daan);
        //cout<<daan<<endl;
    }
 return 0;
  }

/*

*/
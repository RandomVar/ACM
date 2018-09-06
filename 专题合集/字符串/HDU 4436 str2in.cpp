#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int mod=2012;
const int maxn = 1e5+100;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        mem(ch[sz], -1);
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p;
        for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
      }

    int topcnt[maxn], topsam[maxn << 1];
    void sort()
    { // 加入串后拓扑排序
        mem(topcnt, 0);
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < maxn - 1; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
    }
    int dp[maxn<<1];int sum[maxn<<1];
   int solve()
    {
        int ans=0;
        mem(dp,0);mem(sum,0);
         dp[rt]=1;
       for(int i=0;i<sz;i++)
       {
           int u=topsam[i];
           for(int c=0;c<10;c++)
           {
               if(c==0&&u==0) continue;
               if(ch[u][c]!=-1)
               {
                   int v=ch[u][c];
                   dp[v]=(dp[v]+dp[u])%mod;
                   sum[v]=(sum[v]+sum[u]*10%mod+dp[u]*c%mod)%mod;
               }
           }
           ans=(ans+sum[u])%mod;
       }
       return ans;
    }

};
SAM sam;
char buf[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1)
   {
       sam.init();
       for(int i=0;i<n;i++)
       {
        scanf("%s",buf);
        int len=strlen(buf);
       for(int j=0;j<len;j++)
         sam.extend(buf[j]-'0');
         sam.last=0;
        }
        sam.sort();
        printf("%d\n",sam.solve());

   }
 return 0;
  }

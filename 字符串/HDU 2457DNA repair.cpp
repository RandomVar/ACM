#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
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
const int maxn=1e3+100;
char aa[]={'A','G','C','T'};
int id(char a)
{
    for(int i=0;i<4;i++)
      if(aa[i]==a) return i;
}
struct trie{
    int root;
    int cnt;
    int next[maxn][4],fail[maxn],ed[maxn];
    int dp[maxn][maxn*50];
    int newroot()
    {
         for(int j=0;j<4;j++)
            next[cnt][j]=-1;

        ed[cnt]=0;
        cnt++;
     return cnt-1;
    }
   void init()
   {
       cnt=0;
       root=newroot();
   }
    void inser(char *buf)
    {
        int now=root;
        int len=strlen(buf);
        for(int i=0;i<len;i++)
        {
          if(next[now][id(buf[i])]==-1)
            next[now][id(buf[i])]=newroot();
          now=next[now][id(buf[i])];
        }
        ed[now]++; 
    }
    void build()
    {
        queue<int>que;
        fail[root]=root;
       
        for(int i=0;i<4;i++)
          if(next[root][i]!=-1)
          {
             fail[next[root][i]]=root;
              que.push(next[root][i]);
          }
          else{
              next[root][i]=root;
          }
        
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            for(int i=0;i<4;i++)
            {
                if(next[now][i]!=-1)
                  {
                     fail[next[now][i]]=next[fail[now]][i];
                      que.push(next[now][i]);
                  }
                else{
                    next[now][i]=next[fail[now]][i];
                }
            }
        }
    }
   int solve(char *buf)
   {
       dp[0][0]=1;
       for(int i=1;i<cnt;i++)
         dp[0][i]=0;
       int len=strlen(buf);
    for(int t=0;t<len;t++)
    {
        for(int i=0;i<cnt;i++)
          dp[t+1][i]=inf;
       for(int i=0;i<cnt;i++)
       {
          if(ed[i]) continue;     
            for(int j=0;j<4;j++)
           {
               int k=next[i][j];
               dp[t+1][k]=min(dp[t+1][k],dp[t][i]+(id(buf[t])==j?0:1));
           }
       }
    }
    int  ans=inf;
     for(int i=0;i<cnt;i++)
     {
       if(ed[i]) continue;
      ans=min(ans,dp[len][i]);
     }
     return ans;
   }
};

trie ac;

char buf[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    int cas=0;
    while(scanf("%d",&n)==1&&n)
    {
        ac.init();
        for(int i=0;i<n;i++)
          {
              scanf("%s",buf);
              ac.inser(buf);
          }
        ac.build();
        scanf("%s",buf);
        int ans=ac.solve(buf);
        printf("Case %d: ",++cas);
        if(ans==inf) printf("-1\n");
        else printf("%d\n",ans);
    }

 return 0;
  }
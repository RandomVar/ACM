#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e3+100;
char aa[]={'A','G','C','T'};
int id(char a)
{
    for(int i=0;i<4;i++)
      if(aa[i]==a) return i;
}
struct trie{
     int next[maxn][4],fail[maxn],ed[maxn];
   int root,cnt;
   int newnode(){
      for(int i=0;i<4;i++)
        next[cnt][i]=-1;
      ed[cnt++]=0;
      return cnt-1;
   }
   
   void init(){
      cnt=0;
      root=newnode();
   }

   void inser(char* buf){
     int len=strlen(buf);
     int now=root;
     for(int i=0;i<len;i++){
         if(next[now][id(buf[i])]==-1)
             next[now][id(buf[i])]=newnode();
         now=next[now][id(buf[i])];
     }
     ed[now]++;
   }

   void build(){
     queue<int>que;
     fail[root]=root;
     for(int i=0;i<4;i++){
        if(next[root][i]==-1)
             next[root][i]=root;
        else{
            fail[next[root][i]]=root;
            que.push(next[root][i]);
        }}
        while(!que.empty()){
            int now=que.front();
            que.pop();
            for(int i=0;i<4;i++){
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
        }
     }
   int dp[maxn][maxn];
   int query(char *buf)
   {
       memset(dp,0x3f,sizeof(dp));
     //  for(int i=0;i<cnt;i++)
           dp[0][0]=0;
          // cout<<cnt<<endl;
        int len=strlen(buf);
      for(int t=0;t<len;t++)
     {
         for(int i=0;i<cnt;i++)
          {
              if(dp[t][i]==inf) continue;
            for(int j=0;j<4;j++)
            {
                int k=next[i][j];
                if(ed[k]) continue;
                if(id(buf[t])==j) dp[t+1][k]=min(dp[t+1][k],dp[t][i]);
               else dp[t+1][k]=min(dp[t+1][k],dp[t][i]+1);
             }
        }
     }
     int ans=inf;
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
int main()
{
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
        int ans=ac.query(buf);
        printf("Case %d: ",++cas);
        if(ans==inf) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
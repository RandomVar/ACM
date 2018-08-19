#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e3+100;
map<char,int>mp;
/*
以now节点结尾的后缀 与 root-fail[now]所表示的字符串 相同
*/
struct trie{
     int Next[maxn][4],fail[maxn],ed[maxn];
   int root,cnt;
   int newnode(){
      for(int i=0;i<4;i++)
        Next[cnt][i]=-1;
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
         if(Next[now][mp[buf[i]]]==-1)
             Next[now][mp[buf[i]]]=newnode();
         now=Next[now][mp[buf[i]]];
     }
     ed[now]=1;
   }

   void build(){
     queue<int>que;
     fail[root]=root;
     for(int i=0;i<4;i++){
        if(Next[root][i]==-1)
             Next[root][i]=root;
        else{
            fail[Next[root][i]]=root;
            que.push(Next[root][i]);
        }}
        while(!que.empty()){
            int now=que.front();
            que.pop();
            cout<<now<<": ";
            ed[now]|=ed[fail[now]];//now是fail[now]的后缀，所以若fail[now]不能匹配，那么now也不能匹配
            for(int i=0;i<4;i++){
                if(Next[now][i]==-1)
                    Next[now][i]=Next[fail[now]][i];
                else{
                    fail[Next[now][i]]=Next[fail[now]][i];
                    cout<<"**"<<Next[now][i]<<" "<<fail[Next[now][i]]<<endl;;
                    que.push(Next[now][i]);
                }
                cout<<i<<"+"<<Next[now][i]<<" ";
            }
            cout<<endl;
        }
     }
  
   int dp[maxn][maxn];
   int query(char *buf)
   {
         int res = inf;
    int len = strlen(buf);
    for (int i = 0; i <= len; i++)
        for (int j = 0; j < cnt; j++)
            dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= len; i++)
        for (int j = 0; j < cnt; j++)
            for (int k = 0; k < 4; k++)
                if (!ed[Next[j][k]]) {
                    if (mp[buf[i - 1]]== k)
                        dp[i][Next[j][k]] = min(dp[i][Next[j][k]], dp[i - 1][j]);
                    else
                        dp[i][Next[j][k]] = min(dp[i][Next[j][k]], dp[i - 1][j] + 1);
                }
    for (int i = 0; i < cnt; i++)
        res = min(res, dp[len][i]);
   if(res==inf)
    res=-1;
    return res;
   }
};
trie ac;
char buf[maxn];
int main()
{
      int n;
    int cas=0;
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
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
        // printf("Case %d: ",++cas);
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
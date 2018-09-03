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
const int maxnode=1e5+100;
const int maxn=1e4+100;
vector<int>vec[maxn];
struct trie{
    int next[maxnode][129],fail[maxnode],ed[maxnode];
    int cnt,root;
    int newnode()
    {
        for(int i=0;i<129;i++)
         next[cnt][i]=-1;
         ed[cnt++]=0;
       return cnt-1;
    }
    void init()
    {
        cnt=0;
        root=newnode();
    }
    void inser(char *s,int id)
    {
        int now=root;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(next[now][s[i]]==-1)
               next[now][s[i]]=newnode();
            now=next[now][s[i]];
        }
        ed[now]=id;
    }
    void build()
    {
        queue<int>que;
        for(int i=0;i<129;i++)
        {
          if(next[root][i]==-1)
             next[root][i]=root;
          else 
           {
               fail[next[root][i]]=root;
                que.push(next[root][i]);
             }
         }
         while(!que.empty())
         {
             int now=que.front();
             que.pop();
             for(int i=0;i<129;i++)
             {
                 if(next[now][i]==-1)
                   next[now][i]=next[fail[now]][i];
                else
                {
                   fail[next[now][i]]=next[fail[now]][i];
                   que.push(next[now][i]);
                }
             }
         }
    }
    void query(char *s,int id)
    {
      //  cout<<cnt<<endl;
      //  for(int i=0;i<cnt;i++)
      //   cout<<ed[i]<<" ";
      //   cout<<endl;
        int len=strlen(s);
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][s[i]];
            if(ed[now]) vec[id].pb(ed[now]); 
           // cout<<now<<" "<<ed[now]<<endl;
        }
    }

};
void init(int m)
{
    for(int i=0;i<=m;i++)
     vec[i].clear();
}
char buf[maxn];
trie ac;
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
       
        ac.init();
        for(int i=1;i<=n;i++)
         scanf("%s",buf),ac.inser(buf,i);
        ac.build();
        int m;
        scanf("%d",&m);
         init(m);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",buf);
            ac.query(buf,i);
        }
       
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            if(vec[i].size())
            {
                printf("web %d:",i);
                sort(vec[i].begin(),vec[i].end());
              for(int j=0;j<vec[i].size();j++)
                printf(" %d",vec[i][j]);
                printf("\n");
              cnt++;
            }
        }
        printf("total: %d\n",cnt);
    }
 return 0;
  }

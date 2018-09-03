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
const int maxnode=5e4+100;
const int maxn=2e6+100;
int ans[1005];
struct trie{
    int next[maxnode][27],fail[maxnode],ed[maxnode];
    int cnt,root;
    int newnode()
    {
        for(int i=0;i<27;i++)
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
        int len=strlen(s);
        int now=root;
        for(int i=0;i<len;i++)
        {
           if(next[now][s[i]-'A']==-1)
             next[now][s[i]-'A']=newnode();
            now=next[now][s[i]-'A'];
        }
        ed[now]=id;
    }
    void build()
    {
        queue<int>que;
        fail[root]=root;
        for(int i=0;i<27;i++)
        {
            if(next[root][i]==-1)
              next[root][i]=root;
            else{
                fail[next[root][i]]=root;
                que.push(next[root][i]);
            }
        }
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            for(int i=0;i<27;i++)
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
    void query(int *s,int len)
    {
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][s[i]];
            if(ed[now])
            {
                ans[ed[now]]++;
                now=fail[now];
            }
        }
    }
};
trie ac;
char buf[1005][60];
char ss[maxn];
int s[maxn];
void init()
{
    mem(ans,0);

}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1)
   {
       ac.init();
       init();
       for(int i=1;i<=n;i++)
       {
           scanf("%s",buf[i]);ac.inser(buf[i],i);
       }
       ac.build();
       scanf("%s",ss);
       int len=strlen(ss);
       int k=0;
       for(int i=0;i<len;i++)
       {
           if(ss[i]>'Z'||ss[i]<'A')
             s[i]=26;
            else s[i]=ss[i]-'A';
       }
       ac.query(s,len);
       for(int i=1;i<=n;i++)
       {
           if(ans[i])
           {
               printf("%s:",buf[i]);
                printf(" %d\n",ans[i]);
           }
       }
   }
 return 0;
  }

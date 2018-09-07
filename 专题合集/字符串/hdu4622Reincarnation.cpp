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
const int maxn = 2010;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int pos[maxn<<1];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        mem(ch[sz], -1);
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void extend(int c,int pp)
    {
        int np = newnode(len[last] + 1);
        pos[np]=pp;
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
                pos[nq]=pos[q];
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
      }

    int topcnt[maxn], topsam[maxn << 1];
    int ans[maxn<<1][maxn<<1];
    void sort()
    { // 加入串后拓扑排序
        mem(topcnt, 0);
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < maxn - 1; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
    }
  void solve(char *s)
   {
      int l=strlen(s);
      mem(ans,0);
         for(int i=0;i<l;i++)
        {
            init();
          for(int j=i;j<l;j++)
          {
              extend(s[j]-'a',j);
          }
        //   sort();
          for(int j=0;j<sz;j++)
          {
              int pre=0;
              if(link[j]!=-1) pre=len[link[j]]; 
               ans[i][pos[j]]+=len[j]-pre;
            //  cout<<i<<" "<<ans[i][pos[j]]<<endl;
          }
          for(int j=i+1;j<l;j++)
            ans[i][j]+=ans[i][j-1];
        }
    }
   

};
SAM sam;
char s[maxn];

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
    
        scanf("%s",s);
    
     
        sam.solve(s);
        int m;
        scanf("%d",&m);

        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",sam.ans[l-1][r-1]);
        }

    }
 return 0;
  }


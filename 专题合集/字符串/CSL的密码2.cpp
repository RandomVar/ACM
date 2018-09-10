#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,x) memset(a,x,sizeof(a)) 
const int maxn =1e6+100;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][2];
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
    ll dp[maxn<<1][5];
    ll solve()
    {
       sort();
        mem(dp,0);
      
       if(ch[rt][1]!=-1) dp[ch[rt][1]][1]=1;
       for(int i=0;i<sz;i++)
       {
           int u=topsam[i]; 
           for(int c=0;c<2;c++)
           {
               int v=ch[u][c];
               if(v==-1) continue;
               for(int j=0;j<3;j++)
               {
                   int x=(j*2%3+c)%3;
                 //if(flag[u]||c!=0)  
                    dp[v][x]+=dp[u][j];
               }
           }
       }
       ll ans=0;
       for(int i=0;i<sz;i++)
         ans+=dp[i][0];
        return ans;
    }

};
SAM sam;
char s[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s);
        sam.init();
        for(int i=0;i<len;i++)
          sam.extend(s[i]-'0');
    
        printf("%lld\n",sam.solve());
    }
}
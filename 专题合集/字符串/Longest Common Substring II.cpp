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
const int maxn = 1e5+100;
struct node{
    int fir,sec,thir;
};
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int mi[maxn<<1],ma[maxn<<1];
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
        for(int i=0;i<sz;i++) mi[i]=len[i];
    }
   
    void biao(char *s)
    {
        int l=strlen(s);
        int v=0;
        int llen=0;
        mem(ma,0);
       for(int i=0;i<l;i++)
        {
            while(v&&ch[v][s[i]-'a']==-1) v=link[v],llen=len[v];
            
            if(ch[v][s[i]-'a']!=-1) 
            {
                v=ch[v][s[i]-'a']; 
                llen++;
                ma[v]=max(ma[v],llen);
                
            }
        }
        for(int i=sz-1;i>=0;i--)
        {
            int u=topsam[i];
            mi[u]=min(mi[u],ma[u]);
            ma[link[u]]=max(ma[u],ma[link[u]]);
        }
    }

    int solve()
    {
        int ret=0;
        for(int i=0;i<sz;i++)
        {
           ret=max(ret,mi[i]);
        }
        return ret;
    }

};
SAM sam;
char s[maxn];
int main(){
    // freopen("data.in","r",stdin);
    //  freopen("data.out","w",stdout);
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(scanf("%s",s)!=EOF)
    {
        sam.init();
        int len=strlen(s);
        
        for(int i=0;i<len;i++)
        {
            sam.extend(s[i]-'a');
        }
        int n=0;
        sam.sort();
        while(scanf("%s",s)!=EOF)
        {
             n++;
            sam.biao(s);
        }
        printf("%d\n",sam.solve());
    }
 return 0;
  }


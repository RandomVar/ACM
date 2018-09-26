/*
https://blog.csdn.net/wchhlbt/article/details/78512917
复杂度线性
加完特殊字符后，最长子串的长度是半径减1，起始位置是中间位置减去半径再除以2。
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+50;
struct Manacher
{
    char p[maxn];
    char temp[maxn<<1];
    int f[maxn<<1];
    void init(char *p,char *temp)
    {
        int n=strlen(p);
        temp[0]='*';
        for(int i=0;i<=n;i++)
        {
            temp[i*2+1]='#';
            temp[i*2+2]=p[i];
        }
        temp[2*n+2]='\0';
    }
    void getlen(char *p,int *f)
    {
        int mx=0,po=0;
        int n=strlen(p);
        f[0]=0;
        for(int i=2;i<n;i++)
        {
            if(mx>i)
                f[i]=min(mx-i,f[2*po-i]);
            else
                f[i]=1;
            while(p[i-f[i]]==p[i+f[i]])
                f[i]++;
            if(f[i]+i>mx)
            {
                po=i;
                mx=f[i]+i;
            }
        }
    }
}ans;
int bit[maxn];
int N;
int lowbit(int x)
{
  return x&(-x);
}
void add(int x,ll d)
{
  if(x<0) return;
  while(x<=N)
  {
   bit[x]+=d;
   x+=lowbit(x);
  }
}
ll sum(int x)
{
  ll res=0;
   while(x>0)
   {
     res+=bit[x];
     x-=lowbit(x);
   }
   return res;
}


vector <int> vec[maxn];
int np[maxn];
int main()
{
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
      memset(bit,0,sizeof(bit));
        scanf("%s",&ans.p);
        N=strlen(ans.p);
        ans.init(ans.p,ans.temp);
        ans.getlen(ans.temp,ans.f);
         int n=strlen(ans.temp);
        ll res=0;
       int k=0;
       for(int i=0;i<=n;i++)
        vec[i].clear();
        for(int i=2;i<n;i+=2)
        {
          np[++k]=ans.f[i]/2-1;
          vec[k-np[k]].push_back(k);
        }
      for(int i=1;i<=N;i++)
       {
         for(int j=0;j<vec[i].size();j++)
           add(vec[i][j],1);

            res+=sum(min(N,i+np[i]))-sum(i);
       }
        printf("%lld\n",res);
    }
    return 0;
}

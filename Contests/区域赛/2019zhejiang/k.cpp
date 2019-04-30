#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100;
struct Manacher
{
    
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
}mh;
char s[maxn],t[maxn];
int main()
{

  int cas;
  scanf("%d",&cas);
  while(cas--)
  {
    scanf("%s",s);
    scanf("%s",t);
    int len=strlen(s);
    int l=-1;int r=-1;
    for(int i=0;i<len;i++)
    {
      if(l==-1&&s[i]!=t[i])
      {
          l=i;r=i;
      }
      else if(s[i]!=t[i]) r=i;
    }
    if(l==-1)
    {
        mh.init(s,mh.temp);
        mh.getlen(mh.temp,mh.f);
        int n=strlen(mh.temp);
        long long ans=0;
        for(int i=2;i<n;i++)
        {
          ans+=(mh.f[i]-1)/2;
        }
        ans+=len;
        printf("%lld\n",ans);
     continue;
    }
    int flag=1;
    for(int i=0;i<=r-l;i++)
    {
      if(s[i+l]!=t[r-i])
      {
          flag=0;break;
      }
    }
    if(flag==0)
    {
     printf("0\n");
      continue;
    }
    else
    {
      int x=l-1;int y=r+1;
      int ans=1;
      while(x>=0&&y<len)
      {
        if(s[x]==s[y]) {
          ans++;
          x--;y++;
        }
        else break; 
      }
    printf("%d\n",ans);
    }
    
  }
}
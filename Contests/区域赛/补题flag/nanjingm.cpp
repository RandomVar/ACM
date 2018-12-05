#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+100;
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
struct exKMP
{
    char p[maxn];
    int f[maxn];
    int extend[maxn];
    void getfail(char *p,int *f)
    {
        int m=strlen(p);
        f[0]=m;
        int i=0;
        while(i<m-1&&p[i]==p[i+1])
            i++;
        f[1]=i;
        int po=1;
        for(i=2;i<m;i++)
        {
            if(f[i-po]+i<po+f[po])
                f[i]=f[i-po];
            else
            {
                int j=po+f[po]-i;
                if(j<0)
                    j=0;
                while((i+j<m)&&p[i+j]==p[j])
                    j++;
                f[i]=j;
                po=i;
            }
        }
    }
    void getextend(char *t,char *p,int *f,int *extend)
    {
        int n=strlen(t);
        int m=strlen(p);
        getfail(p,f);
        int i=0;
        while(t[i]==p[i]&&i<n&&i<m)
            i++;
        extend[0]=i;
        int po=0;
        for(int i=1;i<n;i++)
        {
            if(f[i-po]+i<extend[po]+po)
                extend[i]=f[i-po];
            else
            {
                int j=extend[po]+po-i;
                if(j<0)
                    j=0;
                while(i+j<n&&j<m&&t[i+j]==p[j])
                    j++;
                extend[i]=j;
                po=i;
            }
        }
    }
}exx;
char s1[maxn],s2[maxn];
ll res[maxn];
int bit[maxn];
int ji[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int d,int n)
{
    if(x<=0) return;
    while(x<=n)
    {
         bit[x]+=d;
         x+=lowbit(x);
    }
}
int sum(int x)
{
    ll a=0;
    while(x>0)
    {
        a+=bit[x];
        x-=lowbit(x);
    }
    return a;
}
int main()
{
    while(scanf("%s",ans.p)!=EOF)
    {
        scanf("%s",s2);
        int n=strlen(ans.p);
        for(int i=0;i<n;i++)
          exx.p[i]=ans.p[n-i-1];

        ans.init(ans.p,ans.temp);
        ans.getlen(ans.temp,ans.f);
        int len=strlen(ans.temp);
        // cout<<ans.temp<<endl;
      memset(ji,0,sizeof(int)*(len+10));
        for(int i=2;i<len;i++)
        {
            ji[(i-ans.f[i])/2]++;
            ji[i/2]--;
            // add(+1,1,len);
            // add(i/2+1+1,-1,len);
           // res[i/2]=(i-ans.f[i])/2;
            // cout<<ans.f[i]<<" "<<(i-ans.f[i])/2<<" "<<i/2<<endl;
        }
        // cout<<endl;
        exx.getextend(exx.p,s2,exx.f,exx.extend);
        // cout<<exx.p<<endl;
        for(int i=0;i<n;i++)
        {
            res[i]=exx.extend[n-i-1];
        //  cout<<exx.extend[i]<<endl;
        }
        ll cnt=0;
        ll shu=ji[0];
        for(int i=0;i<n-1;i++)
        {
            shu+=ji[i+1];
            cnt+=res[i]*shu;
            // cout<<i<<" "<<shu<<" "<<res[i]<<endl;
        }
        printf("%lld\n",cnt);
        
    }
}
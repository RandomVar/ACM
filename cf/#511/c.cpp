#include<bits/stdc++.h>
using namespace std;
const int maxn =1.5e7+100;

bool has[maxn+1];
int prime[maxn/10+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    memset(has,false,sizeof(has));
    for(int i=2;i<=maxn;i++)
    {
        if(!has[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            has[prime[j]*i]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}

const int maxm=3e5+100;
int a[maxm];
int v[maxn];
int main()
{
    getPrime();
   // cout<<prime[0]<<endl;
    //cout<<1<<endl;
    int n;
    while(scanf("%d",&n)==1)
    {
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    // cin>>a[i];
    int g=a[1];
    for(int i=2;i<=n;i++)
      g=__gcd(a[i],g);
    for(int i=1;i<=n;i++)
     a[i]/=g;
     int mm=0;
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=prime[0]&&1LL*prime[j]*prime[j]<=a[i];j++)
         {
             //cout<<a[i]<<" "<<prime[j]<<endl;
             if(a[i]%prime[j]==0)
               {
               v[prime[j]]++;
               while(a[i]%prime[j]==0)
                a[i]/=prime[j];
                mm=max(mm,prime[j]);
               }         
         }
          if(a[i]>1) v[a[i]]++;
          mm=max(mm,a[i]);
     }
  //  cout<<g<<endl;
     int ans=0;
     for(int i=2;i<=mm;i++)
       ans=max(ans,v[i]);
     if(ans==0) 
       printf("-1\n");
       //cout<<-1<<endl;
     else printf("%d\n",n-ans);  
    //  cout<<n-ans<<endl;
}
}
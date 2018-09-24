#include<bits/stdc++.h>
#define ll long long
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int maxn=1e6+100;
int a[maxn],b[maxn],c[maxn];
int f[maxn];
int main()
{
    ios_close;
   int n,m,k;
   while(cin>>n>>m>>k)
   {
     memset(f,0,sizeof(f));
     for(int i=1;i<=m;i++)
      cin>>b[i],f[b[i]]=1;
     for(int i=1;i<=k;i++)
      cin>>c[i];
    if(b[1]==0&&m!=0) {
      cout<<-1<<endl;
      continue;
    }
    b[0]=-1;
    int jv=0;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
      if(b[i]==b[i-1]+1)
      {
        cnt++;
      }
      else
      {
        jv=max(jv,cnt);
        cnt=1;
      }
    }
    jv=max(jv,cnt);
    jv++;
    if(jv>k)
    {
      cout<<-1<<endl;
      continue;
    }
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
      if(f[i])
        a[i]=a[i-1];
      else a[i]=i;
      //  cout<<i<<" "<<a[i]<<endl;
    }
     ll ans=1e16;
    for(int i=jv;i<=k;i++)
    {
      int now=0;
      cnt=1;int flag=1;
      while(now<n)
      {
        if(now+i>=n)
        {
          //cnt++;
          break;
        }
        // cout<<"*"<<i<<" "<<now<<endl;
        if(now==a[now+i])
        { flag=0;break;}
        now=a[now+i];
        cnt++;
      }
    if(flag)  ans=min(ans,1LL*cnt*c[i]);
    }

    printf("%lld\n",ans);

   }
  return 0;
}

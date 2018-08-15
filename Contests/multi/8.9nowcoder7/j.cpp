
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;

char s[maxn][maxn];
int a[maxn][maxn];
int last[60];
ll used[maxn];
int notd[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
         scanf("%s",s[i]);
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         {
          if(s[i][j]>='A'&&s[i][j]<='Z') a[i][j]=s[i][j]-'A';
          else a[i][j]=s[i][j]-'a'+26;
         }
     ll ans=0;
        for(int i=0;i<n;i++)
        {
            memset(notd,-1,sizeof(notd));
            memset(used,0,sizeof(used));
            for(int c=0;c<=52;c++)
            {
                int x=i+c;
                if(x>=n) break;
                for(int j=0;j<m;j++)
                {
                      if(used[j]&(1LL<<a[x][j]))
                         notd[j]=j;
                       used[j]|=(1LL<<a[x][j]);
                }
                memset(last,-1,sizeof(last));
                for(int j=0;j<m;j++)
                {
                   notd[j]=max(notd[j],last[a[x][j]]);
                   last[a[x][j]]=j;
                }
                for(int l=-1,r=0;r<m;r++)
                  l=max(l,notd[r]),ans+=r-l;
            }
        }
        printf("%lld\n",ans);
          //cout<<ans<<endl;
      }
}
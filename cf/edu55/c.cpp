#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
ll sum[maxn];
vector<int>v[maxn];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
        for(int i=1;i<=m;i++)
         {
             sort(v[i].begin(),v[i].end());
             int x=v[i].size();
             ll pre=0;
             for(int j=x-1;j>=0;j--)
             {
                 pre+=v[i][j];
               if(pre>=0) 
               {
               sum[x-j]+=pre;
               }
               else break;
             }
         }
         ll ans=0;
         for(int i=1;i<=n;i++)
        //   cout<<sum[i]<<endl,
          ans=max(ans,sum[i]);
          cout<<ans<<endl;
    }
}
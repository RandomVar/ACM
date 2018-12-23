#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int cnt[maxn];

int main()
{
    int n,x,c,m;
    while(cin>>n>>x>>c>>m)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            cnt[x]=1;
        }
        int ji=0;
        for(int i=1;i<=x;i++)
        {
           if(cnt[i]) ji++;
        }
        int i=x;
        int ans=0;
        while(i<=n)
        {
             if(ji<c)
             {
                int j=i;
                while(ji<c)
                {
                   // if(j<i-x) break;
                  if(!cnt[j])
                  {
                      cnt[j]=1;
                       ji++;
                       j--;
                       ans++;
                  }
                  else j--;
                }
             }
             ji-=cnt[i-x+1];
             i++;
             ji+=cnt[i];
        }
        cout<<ans<<endl;

    }
}
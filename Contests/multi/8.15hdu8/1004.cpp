#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;

int shu[205][205];
int main()
{
  int t;
  ios_close;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int a = n&1,b = m&1;
    if(b && a)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          shu[i][j] = 1;
        }
      }
    }
    if(b && !a)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          shu[i][j] = i%2;
        }
      }
    }
    if(!b && a)
    {
      for(int i = 1;i<=n;i++)
      {
        for(int j = 1;j<=m;j++)
        {
          shu[i][j] = j%2;
        }
      }
    }
    if(!b && !a)
    {
      if(n>=m)
      {
        for(int i = 1;i<=n;i++)
        {
          for(int j = 1;j<=m;j++)
          {
            if(i % 2 == 1)
            {
                if(j%4 == 2 || j%4 == 1)
                {
                  shu[i][j] = 1;
                }
                else
                shu[i][j] = 0;
            }
            else
            shu[i][j] = j%2;
          }
        }
      }
      else
      {
        for(int j = 1;j<=m;j++)
        {
          for(int i = 1;i<=n;i++)
          {
            if(j % 2 == 1)
            {
                if(i%4 == 1 || i%4 == 2)
                {
                  shu[i][j] = 1;
                }
                else
                shu[i][j] = 0;
            }
            else
            shu[i][j] = i%2;
          }
        }
      }
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        if(shu[i][j]) cout<<"(";
        else cout<<")";
      }
      cout<<endl;
    }
  }
  return 0;
}
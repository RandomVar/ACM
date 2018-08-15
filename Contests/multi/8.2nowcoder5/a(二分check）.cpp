/*
很经典的二分check啊orz
*/
#include<bits/stdc++.h>
using namespace std;
 
#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-7;
struct Node
{
  double s,c;
 
}node[100005];
double ko[100005];
int n,k;

int check(double d)
{
  double ans=0;
  for(int i=1;i<=n;i++)
   ko[i]=node[i].s*(node[i].c-d);
  sort(ko+1,ko+1+n);
  for(int i=n;i>k;i--)
  {
    ans+=ko[i];
  }
  return ans>=0;
}

int main()
{

  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  while(scanf("%d%d",&n,&k) == 2)
  {
    for(int i = 1;i<=n;i++)
    {
      scanf("%lf",&node[i].s);
    }
    for(int i = 1;i<=n;i++)
    {
      scanf("%lf",&node[i].c);
    }

   
     double  l=0;double  r= 1010;
     double ans=0;
     for(int i=0;i<50;i++)
     {
       double mid=(l+r)/2;
       if(check(mid))
         l=mid;
        else r=mid;
     }
    printf("%.7lf\n",l);
  }
  return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
#define ll long long
const int maxn=1000100;
int datebase1[maxn],datebase2[maxn],pro[maxn];
int n;
int main()
{
  while(cin>>n)
  {
    memset(datebase1,0,sizeof(datebase1));
    memset(datebase2,0,sizeof(datebase2));
    memset(pro,0,sizeof(pro));
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&datebase1[i]);
    }
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&datebase2[i]);
      pro[i]=datebase1[i]-datebase2[i];
      pro[i+n]=pro[i];
    }
    int ans,flag=-1;
    for(ans=1;ans<=n;ans++)
    {
      if(flag!=-1) break;
      pro[ans-1]=0;
      for(int i=ans;i<=ans+n-1;i++)
      {
        pro[i]=pro[i]+pro[i-1];
        if(pro[i]<0)
        {
          ans=i;
          break;
        }
        if(i==ans+n-1) {
          flag=ans;
          break;
        }
      }
    }
    cout<<flag-1<<endl;
  }
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
int c[200];
int main()
{
  int t;
  scanf("%d",&t);
  int k=0;
  for(int i=7;i<=200;i+=7)
    if(i%4) c[k++]=i;
  while(t--)
  {
    int n;
    scanf("%d",&n);
    int ans=lower_bound(c,c+k,n)-c;
    printf("%d\n",c[ans]);
  }
}
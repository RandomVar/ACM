#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int p[maxn];
int val[maxn];
int cnt[maxn];
int main()
{
  int n;
  while(cin>>n)
  {
    int flag=0;
    for(int i=1;i<=n;i++)
     {
        cin>>p[i]>>val[i];
    if(val[i]==0&&p[i]!=-1)   cnt[p[i]]++;
     }
     for(int i=1;i<=n;i++)
     {
       if(val[i]&&!cnt[i])
           flag=1,cout<<i<<" ";
     }
     if(!flag) cout<<-1;
     cout<<endl;
  }

}
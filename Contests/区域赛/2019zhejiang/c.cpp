#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
map<int,int>mp;
map<int,int>::iterator it;
int a[maxn];
int ans[maxn];
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    int cnt=0;
    mp.clear();
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      mp[a[i]]++;
      cnt=max(cnt,mp[a[i]]);
    }
    if(cnt>n/2)
    {
      printf("Impossible\n");
      continue;
    }
    int j=n;
    priority_queue<int,vector<int>,greater<int> >que;
    for(int i=1;i<=n;i++)
    {
      it=mp.begin();
      int x=it->first;
       cout<<"??"<<i<<" "<<it->first<<" "<<a[i]<<endl;
      if(it->first==a[i])
      {
       
        it++;
        if(it!=mp.end())
        {
          ans[i]=it->first;
           it->second--;
           if(it->second==0)
             mp.erase(it);
        }
        else
        {
          for(j=min(j,i-1);j>=1;j--)
          {
            if(a[j]!=x&&ans[j]!=x) break;
          }
          que.push(ans[j]);
          cout<<i<<" "<<j<<" "<<ans[j]<<endl;
          ans[i]=-1;
          ans[j]=x;
          j--;
        }
      }
      else 
      {
        ans[i]=it->first;
        it->second--;
        if(it->second==0)
        mp.erase(it);
      }
    }
    for(int i=1;i<n;i++)
     {
      // cout<<"ans"<<ans[i]<<endl;
       if(ans[i]==-1) 
       {
         printf("%d ",que.top());
         que.pop();
       }
       else printf("%d ",ans[i]);
     }
     if(ans[n]==-1) 
       {
         printf("%d\n",que.top());
         que.pop();
       }
    else printf("%d\n",ans[n]);
  }
}
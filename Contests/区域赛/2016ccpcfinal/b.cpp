/*
预处理出洗衣时间最早的l件衣服
最迟洗完的衣服用最快的烘干机
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,int>P;
const int inf=0x3f3f3f3f;
// set<P>mp;
// set<P>::iterator it;
vector<ll>vec;
const int maxn=1e5+100;
int d[maxn];
int w[maxn];
int l,n,m;


int main()
{
  int t;
  scanf("%d",&t);int cas=0;
  while(t--)
  {
     ll sum=0;
     int x1=inf,x2=inf;
      scanf("%d%d%d",&l,&n,&m);
      for(int i=1;i<=n;i++)
       scanf("%d",&w[i]),x1=min(x1,w[i]);
      for(int i=1;i<=m;i++)
        scanf("%d",&d[i]),x2=min(x2,d[i]);
      sum=1LL*l*(x1+x2);

      priority_queue<P,vector<P>,greater<P> > que;
     vec.clear();
      for(int i=1;i<=n;i++)
       que.push(make_pair(w[i],w[i]));
        int k=0;
       while(k<l)
       {
           P t=que.top();
           vec.push_back(t.first);
           k++;
           que.pop();
           que.push(make_pair(t.first+t.second,t.second));
       }
      priority_queue<P,vector<P>,greater<P> >q2;
    for(int i=1;i<=m;i++)
      q2.push(make_pair(d[i],d[i]));
      ll ans=0;
     for(int i=l-1;i>=0;i--)
     {
       P t=q2.top();
       q2.pop();
       ans=max(ans,t.first+vec[i]);
       q2.push(make_pair(t.first+t.second,t.second));
     }
       printf("Case #%d: %lld\n",++cas,ans);
  }

}

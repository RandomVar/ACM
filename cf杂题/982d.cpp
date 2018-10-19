#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
struct node
{
  int val;int id;
  bool operator<(const node &b)const
  {
    return val<b.val;
  }
}a[maxn];
int p[maxn];
int Find(int x)
{
  if(p[x]<0) return x;
  int y=Find(p[x]);
  return p[x]=y;
}
void Union(int x,int y)//y is root
{
  int x1=Find(x);
  int y1=Find(y);
  if(x1==y1) return;
  p[y1]+=p[x1];
  p[x1]=y1;
  return;
}
void init(int n)
{
  for(int i=0;i<=n;i++)
     p[i]=0;
}
map<int,int>mp;
map<int,int>::iterator it;
int main()
{
  // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  int n;
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)
      cin>>a[i].val,a[i].id=i;

    sort(a+1,a+1+n);
    // a[n+1].val=a[n].val+1;
    int daan=0;
    int cnt=0;
    init(n);
    for(int i=1;i<=n;i++)
   {
     int x=a[i].id;
     p[x]=-1;
     if(!p[x-1]&&!p[x+1])
     {
       mp[1]++;
     }
     if(p[x-1])
     {
       Union(x-1,x);
       mp[-p[x]-1]--;
      if(!mp[-p[x]-1])
         mp.erase(-p[x]-1);
       mp[-p[x]]++;
     }
     if(p[x+1])
     {
       Union(x+1,x);
       mp[-p[x]-1]--;
       if(!mp[-p[x]-1])
          mp.erase(-p[x]-1);
       mp[-p[x]]++;
     }
    if(mp.size()==1)
    {
      it=mp.begin();
     if(it->second>cnt)
        cnt=it->second,daan=a[i].val+1;
    }
  }
  printf("%d\n",daan);
  }
}
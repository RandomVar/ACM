/*
将点所在行与列相连
https://blog.csdn.net/u013578420/article/details/81304498
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=400100;
int p[maxn];
void init(int n)
{
    for(int i=0; i<=n; i++)
        p[i]=i;
}
int Find(int x)
{
    if(x==p[x])
        return p[x];
    int y=Find(p[x]);
    return p[x]=y;
}

int unin(int x,int y)
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)
        return 0;
    p[x1]=y1;
      return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     int n,m,q;
    while(cin>>n>>m>>q)
    {
        init(n+m);
       for(int i=0;i<q;i++)
       {
           int r,c;
           cin>>r>>c;
           unin(r,n+c);
       }
       int cnt=0;
       for(int i=1;i<=n+m;i++)
         if(Find(i)==i) cnt++;
         cout<<cnt-1<<endl;
    }
}
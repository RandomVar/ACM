/*表*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[25];
map<ll,int>mp;
int check()
{
    for(int i=1;i+2<=n;i++)
     if(a[i]==1&&a[i+1]==2&&a[i+2]==1) return 1;
     return 0;
}
int getst()
{
    ll st=0;
    for(int i=1;i<=n;i++)
       st=st*3+a[i];
       return st; 
}
int dfs()
{
  
    if(check()) return -1;
    int flag=0;
    for(int i=1;i<=n;i++)
     if(!a[i]) flag=1;
     if(!flag) return 0;
       ll st=getst();
    if(mp.find(st)!=mp.end()) return mp[st];
     flag=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]) continue;
        for(int j=1;j<=2;j++)
        {
            a[i]=j;
            int f=dfs();
               a[i]=0;
            if(f==-1) //无论怎么填都输  
              return mp[st]=1;//对手无论怎么填都输
         
            if(f==0)
              flag=1;
        }
    }
    if(flag) return mp[st]=0;
    else return mp[st]=-1;
}
int main()
{
    while(cin>>n)
    {
        mp.clear();
        memset(a,0,sizeof(a));
        int flag=dfs();
        if(flag) cout<<"yes"<<endl;
        if(flag==0) cout<<"p"<<endl;
        if(flag==-1) cout<<"no"<<endl;
    }
}
#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
string s[40];
int a[5];
int b[5];
int mp[20];
int daan;
struct node{
    int c[5];int cost;

};
vector<node>ans[10];
int getid(char c)
{
    if(c>='0'&&c<='9') return c-'0';
    if(c>='A'&&c<='F') return c-'A'+10;
}
int check(int x)
{
    
     for(int i=0;i<4;i++)
     {
         int sx=x*4;
         mem(mp,0);
        for(int k=0;k<4;k++)
          for(int j=0;j<4;j++)
          {
              int sy=k*4;
              if(a[k]==0)  
                  if(mp[getid(s[sx+i][sy+j])]) return 0;
                  else mp[getid(s[sx+i][sy+j])]=1;
                if(a[k]==3)
                    if(mp[getid(s[sx+j][sy+3-i])]) return 0;
                    else mp[getid(s[sx+j][sy+3-i])]=1;
                if(a[k]==2)
                   if(mp[getid(s[sx+3-i][sy+3-j])]) return 0;
                   else  mp[getid(s[sx+3-i][sy+3-j])]=1;
                if(a[k]==1)
                   if(mp[getid(s[sx+3-j][sy+i])]) return 0;
                   else mp[getid(s[sx+3-j][sy+i])]=1;
           }
            }
    return 1;
     }

bool check2(int y)
{
     for(int j=0;j<4;j++)
     {
         int sy=4*y;
         mem(mp,0);
         for(int k=0;k<4;k++)
         {
             int t=ans[k][b[k]].c[y];
        
           //  for(int e=0;e<4;e++)
           //   cout<<ans[k][b[k]].c[e]<<" ";
           //   cout<<endl;
             for(int i=0;i<4;i++)
             {
                 int sx=k*4;
                if(t==0)  
                  if(mp[getid(s[sx+i][sy+j])]) return 0;
                  else mp[getid(s[sx+i][sy+j])]=1;
                if(t==3)
                    if(mp[getid(s[sx+j][sy+3-i])]) return 0;
                    else mp[getid(s[sx+j][sy+3-i])]=1;
                if(t==2)
                   if(mp[getid(s[sx+3-i][sy+3-j])]) return 0;
                   else  mp[getid(s[sx+3-i][sy+3-j])]=1;
                if(t==1)
                   if(mp[getid(s[sx+3-j][sy+i])]) return 0;
                   else mp[getid(s[sx+3-j][sy+i])]=1;
             }
            //cout<<111<<endl;
         }
       // cout<<111<<endl;
     }
     return 1;
}

void dfs(int x,int val)
{
   if(x==4)   {
  //cout<<"*"<<val<<endl;
    for(int k=0;k<4;k++)
       if(check2(k)==0)
         return;
       daan=min(daan,val);
       return;
       }
  
   for(int i=0;i<ans[x].size();i++)
   {
       node e=ans[x][i];
       b[x]=i;
        dfs(x+1,val+e.cost);
   }

}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
      for(int i=0;i<8;i++)
       ans[i].clear();
       for(int i=0;i<16;i++)
        cin>>s[i];
        for(int i=0;i<4;i++)
        {
            for(int x=0;x<4;x++)
              for(int y=0;y<4;y++)
                for(int z=0;z<4;z++)
                  for(int k=0;k<4;k++)
                  {
                      a[0]=x;a[1]=y;a[2]=z;a[3]=k;
                      node f;
                      f.c[0]=x;f.c[1]=y;f.c[2]=z;f.c[3]=k;
                      f.cost=x+y+z+k;
                      if(check(i))
                        ans[i].push_back(f);
                  }
            }
          daan=1000;
           dfs(0,0);
           cout<<daan<<endl;
    
   }

 return 0;
  }


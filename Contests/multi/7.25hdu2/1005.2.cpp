/*误*/
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
char a[2000][2000];
int cnt[2000][2000];
int check(int n)
{
    mem(cnt,0);
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
       {
            if(a[i][j]=='1')
                {
                    for(int r=i+1;r<=n;r++)
                       if(a[r][j]=='1') {
                           cnt[i][r]++;
                           if(cnt[i][r]>1)
                              {cout<<i<<" "<<r<<" "<<j<<endl;return 1;}
                }
       }
    
    }
    return 0;
}

int main(){
   cout<<1978<<endl;
   int w=0;
   int cnt=0;
 /* for(int i=1;i<=43;i++)
    {
        a[1][(i-1)*43+1]='1';
       for(int j=2;j<=46;j++)
          {
              cnt++;
            //cout<<0;
          a[1][j+(i-1)*43]='0';
          }
    }
*/

for(int e=1;e<=43;e++)
  for(int f=1;f<=46;f++)
  {
    int k=(e-1)*46+f;
    for(int i=1;i<=43;i++)
    {
        int s=(f+e*i)%46;
        for(int j=1;j<s+1;j++)
         {
             cnt++;
           //  cout<<0;
         a[k][j+(i-1)*43]='0';
         }
        //cout<<1;
        cnt++;
        a[k][s+1+(i-1)*43]='1';
       for(int j=s+2;j<=46;j++)
          {
              cnt++;
            //cout<<0;
          a[k][j+(i-1)*43]='0';
          }
    }
     w++;
    //cout<<endl;
   }
   cout<<check(1978)<<endl;
   cout<<cnt<<endl;
  int n;
  cin>>n;
 return 0;
  }


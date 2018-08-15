#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
char s[5][5];
void solve(int x,int y,int flag)
{
  if(flag==1)//shun
  {
      char t=s[x][y];
      s[x][y]=s[x+1][y];
      char t2=s[x][y+1];
      s[x][y+1]=t;
      t=s[x+1][y+1];
      s[x+1][y+1]=t2;
      s[x+1][y]=t;
  }
  if(flag==0)
  {
      char t=s[x][y];
      s[x][y]=s[x][y+1];
     char t2=s[x+1][y];
      s[x+1][y]=t;
       t=s[x+1][y+1];
      s[x+1][y+1]=t2;
      s[x][y+1]=t;
  }
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n;
       scanf("%d",&n);
       for(int i=0;i<3;i++)
        scanf("%s",s[i]);
       char op[5];
       for(int i=0;i<n;i++)
       {
           
           scanf("%s",op);
           int a=op[0]-'0';
           int flag=0;
           if(op[1]=='C')
             flag=1;
             int x,y;
             if(a==1)
             {
                 x=0,y=0;
             }
             if(a==2)
             {
                 x=0;y=1;
             }
             if(a==3)
             {
                 x=1;y=0;
             }
             if(a==4 )
             {
                 x=1;y=1;
             }
           solve(x,y,flag);
       }
       for(int i=0;i<3;i++)
        {
             printf("%s\n",s[i]);
        }
   }
 return 0;
  }

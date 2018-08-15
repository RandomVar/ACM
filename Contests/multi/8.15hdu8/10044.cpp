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
int s[40][40];
 int n,m;
 int ans;
int check()
{
    int cnt=0;
  for(int i=0;i<n;i++)
  {
      int top=0;
      int flag=0;
   for(int j=0;j<m;j++)
     {
         if(s[i][j]==0) top++;
         else top--;
         if(top<0) {flag=1;break;}
     }
     if(top>0) {flag=1;} 
     if(flag==0) cnt++;
   }

    for(int j=0;j<m;j++)
  {
      int top=0;
      int flag=0;
   for(int i=0;i<n;i++)
     {
         if(s[i][j]==0) top++;
         else top--;
         if(top<0) {flag=1;break;}
     }
     if(top>0) {flag=1;} 
     if(flag==0) cnt++;
   }
   return cnt;
}

void dfs(int x)
{
    if(x==n*m) {
        ans=max(ans,check());
        return ;
    }
    int i=x/m;
    int j=x%m;
    s[i][j]=0;
    dfs(x+1);
    s[i][j]=1;
    dfs(x+1);
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
   while(cin>>n>>m)
   {
       ans=0;
    dfs(0);
    cout<<ans<<endl;
   }
 return 0;
  }


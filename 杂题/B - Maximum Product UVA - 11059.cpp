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
ll a[30];
int n;
ll dfs(int i,ll ans,int flag){
  if(i==n&&flag) return ans;
  if(i==n) return 0;
  ll cnt=dfs(i+1,ans,0);
  cnt=max(cnt,ans*a[i]);
  cnt=max(cnt,dfs(i+1,ans*a[i],1));

  return cnt;
}
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //int n;
  int cas=0;
  while(scanf("%d",&n)==1){
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
        ll ans=0;
       for(int i=0;i<n;i++)
       {
           for(int j=i;j<n;j++)
           {
               ll tmp=a[i];
               for(int k=i+1;k<=j;k++)
                  tmp*=a[k];
              ans=max(ans,tmp);
           }
       }
        printf("Case #%d: The maximum product is %lld.\n\n",++cas,ans);
       // cout<<"Case #"<<++cas<<": The maximum product is "<<dfs(0,1)<<"."<<endl<<endl;
    //cout<<dfs(0,1)<<endl;


  }


  }


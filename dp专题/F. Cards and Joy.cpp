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
vector<int>v;
int getid(int x){
 return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int dfs(int pos,int cnum,int alnum)
{
    //if(pos==cnum+1) return ans;
    
}
const int maxn=1e5+100;

int c[6000],f[600],h[600];
int num[maxn];
int cnt[maxn];
ll dp[600][6000];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k;
    while(cin>>n>>k)
    {
        int N=0;
       for(int i=1;i<=n*k;i++)
         cin>>c[i];
       for(int i=1;i<=n;i++)
         cin>>f[i];
       for(int i=1;i<=k;i++)
          cin>>h[i];
       //mem(num,0);
      // mem(cnt,0);
       for(int i=1;i<=n*k;i++)
       {
           num[c[i]]++;
           N=max(N,c[i]);
       }
       for(int i=1;i<=n;i++)
       {
           cnt[f[i]]++;
       }
       ll daan=0;
       for(int i=1;i<=N;i++)
       {
           if(num[i]==0) continue;
           ll ans=0;
           
           //mem(dp,0);
         //ans+=dfs(1,cnt[i],num[i]);
           for(int j=1;j<=cnt[i];j++)
           {  
               for(int s=0;s<=num[i];s++)
                 for(int x=0;x<=k&&x+s<=num[i];x++)
                     dp[j][s+x]=max(dp[j][s+x],dp[j-1][s]+h[x]);
            }
            daan+=dp[cnt[i]][num[i]];
        }
        cout<<daan<<endl;

    }
 //dp[i]=min(k,num[i])
 //dp[i][s-num]=max dp[i][s]+h[num]

 return 0;
  }


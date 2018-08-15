/*
给数组A，求数组B，使得对所有i<j,b[i]<b[j],a[b[i]]<a[b[j]],求出字典序第k小的序列B
即在A中寻找一个字典序第k小的严格上升子序列，输出其下标
n<=5e5,k<=1e18

设离散化后的数组A：3 1 2 3 4 6 5 
dp[i]表示以第i个数开头的子序列的个数
dp[i]=sum(dp[j])+1, j>i且a[j]>a[i]
从后往前扫一遍，用树状数组维护后缀和即可
注意dp有可能为超过longlong，需要做一些处理

*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=5e5+100;
ll dp[maxn];
ll a[maxn];
ll tree[maxn];
vector<ll>v;
ll n;
int getid(ll x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int lowbit(int x){
return x&(-x);
}
ll sum(int x){
  ll ret=0;
  while(x>0){
    ret+=tree[x];
    ret=min((ll)1e18+5,ret);//notice
    x-=lowbit(x);
  }
return ret;
}

void update(int x,ll d){
    if(x<0) return;
   while(x<=n){
    tree[x]+=d;
    tree[x]=min((ll)1e18+5,tree[x]);//notice
    x+=lowbit(x);
   }
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll k;
   while(cin>>n>>k)
   {
       v.clear();
       for(int i=1;i<=n;i++)
        cin>>a[i],v.pb(-a[i]);
      sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
      for(int i=1;i<=n;i++)
      {
          a[i]=getid(-a[i]);
      }
      for(int i=n;i>=1;i--)
      {
          dp[i]=1+sum(a[i]-1);
          update(a[i],dp[i]);
      }
      ll x=k;
      int tmp=maxn;
      vector<int>ans;
      for(int i=1;i<=n;i++)
      {
           if(a[i]<tmp)
           {
               if(dp[i]>=x)
                 ans.pb(i),tmp=a[i],x--;
                else
                   x-=dp[i];
           }
           if(x==0) break;
      }
      if(tmp==maxn) cout<<-1<<endl;
      else{
          cout<<ans.size()<<endl;
          for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            cout<<endl;
      }
   }
}

     


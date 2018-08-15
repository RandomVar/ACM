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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
map<ll,int>mp[1<<15+4];

map<ll,int>::reverse_iterator it1,it2;
map<ll,int>::iterator it3;
int main(){

   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;int cas=0;
  scanf("%d",&t);
  while(t--)
  {
      //init();
      queue<int>que;
      int n;
      scanf("%d",&n);
      for(int i=1;i<=(1<<n);i++)
      {
          mp[i].clear();
          for(int j=1;j<=n;j++)
          {
              ll t;
              scanf("%lld",&t);
             mp[i][t]=1;
          }
          que.push(i);
      }
     
      while(que.size()>1)
      {
           int p1=que.front();
           que.pop();
           int p2=que.front();
           que.pop();
           it1=mp[p1].rbegin();
           it2=mp[p2].rbegin();
          // cout<<it1->first<<" "<<it2->first<<endl;
           if(it1->first>it2->first)
           {
               it3=mp[p1].lower_bound(it2->first);
               mp[p1].erase(it3->first);
               que.push(p1);
              // cout<<p1<<endl;
           }
           else{
                it3=mp[p2].lower_bound(it1->first);
                mp[p2].erase(it3->first);
               que.push(p2);
               //cout<<p2<<endl;
           }
      }
      printf("Case #%d: ",++cas);
      printf("%d\n",que.front());
  }
 return 0;
  }


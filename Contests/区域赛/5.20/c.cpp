#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e5+100;
ll a[maxn];
ll v[maxn];
typedef pair<ll,int> P;
priority_queue<P,vector<P>,greater<P> >que;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;int cas=0;
   cin>>t;
   while(t--){
        while(!que.empty()){
            que.pop();
        }
      int n;
      cin>>n;
      ll pre=0;
      for(int i=1;i<=n;i++){
          ll t;
          cin>>t;
          a[i]=t-pre;
          pre=t;
          que.push(P{a[i],i});
      }
      memset(v,-1,sizeof(v));
      v[0]=0;
      ll ans=0;
     while(!que.empty()){
         P t=que.top();
         que.pop();
         //cout<<t.second<<endl;
         if(v[t.second-1]==-1&&v[t.second]==-1){
                 if(v[t.second+1]!=-1)  v[t.second-1]=v[t.second]=min(t.first,v[t.second+1]);
                 else v[t.second]=t.first;
                   ans+=(t.first+v[t.second]-1)/v[t.second];
         }
         else {
            if(v[t.second-1]!=-1&&v[t.second]!=-1){
//                ll x=(t.first*2)/(v[t.second]+v[t.second-1]);
                ll x=(t.first+v[t.second]-1)/(v[t.second]);
                // cout<<x<<endl;
                 ans+=x;
            }
           else if(v[t.second-1]!=-1){
                 if(v[t.second+1]!=-1)  v[t.second]=min(t.first,v[t.second+1]);
                 else v[t.second]=t.first;
//                    v[t.second]=t.first;
//                v[t.second]=max(t.first*2-v[t.second-1],v[t.second-1]);
                ans+=(t.first+v[t.second]-1)/v[t.second];
            }
           else if(v[t.second]!=-1){
//                ll x=floor(t.first/v[t.second]);
                ll x=(t.first+v[t.second]-1)/(v[t.second]);
                v[t.second-1]=v[t.second];
                ans+=x;
            }
         }
     }
     cout<<"Case #"<<++cas<<": ";
     cout<<ans<<endl;

   }


}

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
const int maxn=4*1e5+100;
vector<int>edge[maxn];
int st[maxn];
int cnt[maxn];
int  tot,n,d,k;
void bfs(int u){
    queue<int>que;
    for(int i=u;i<=d;i++)
     que.push(i);
   while(!que.empty()){
        int t=que.front();
        que.pop();
        if(st[t]>=d) continue;
        int c=cnt[t];
      for(int i=c+1;i<=k;i++){
       if(tot==n) break;
        edge[t].pb(++tot);
        que.push(tot);
        st[tot]=max(st[tot],st[t]+1);
      // cout<<tot<<" "<<st[tot]<<endl;
        cnt[t]++;
        cnt[tot]++;
      }
      if(tot==n) break;
   }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //ll n,d,k;
  while(cin>>n>>d>>k){
        if(k==1&&n==2&&d==1)
         {cout<<"YES"<<endl;
          cout<<1<<" "<<2<<endl;
         continue;}
        else if(k==1){
            {cout<<"NO"<<endl;continue;}
        }
        for(int i=0;i<=n;i++)
          edge[i].clear();
        int flag=0;
        //k--;
    // if(n>(2+(d-1)*k)) {cout<<"NO"<<endl;continue;}
      if(n<=d) {cout<<"NO"<<endl;continue;}
      mem(st,-1);
      mem(cnt,0);
      //cout<<"YES"<<endl;
      for(int i=1;i<=d;i++){
          edge[i].pb(i+1);
          cnt[i]++;cnt[i+1]++;
          st[i]=max(i-1,d-i+1);
         //cout<<st[i]<<endl;
       }
       st[d+1]=0;
       tot=d+1;
       bfs(2);
       for(int i=1;i<=n;i++)
       if(st[i]==-1) {flag=1;break;}
         if(flag) cout<<"NO"<<endl;
         else{
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
            {
                if(edge[i].size()){
                    for(int j=0;j<edge[i].size();j++)
                    {
                        int t=edge[i][j];
                         cout<<i<<" "<<t<<endl;
                    }
                }
            }
         }
      }
  }



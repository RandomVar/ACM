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
const int maxn=1e7+100;
queue<int>que;
int vis[maxn];
int n,k;
void bfs(){
   int s;
   vector<int>ans;
   while(!que.empty())
   {
     s=que.front();
     que.pop();
     for(int i=0;i<k;i++){
         int x=s^(1<<i);
         if(!vis[x])
                que.push(x),vis[x]=1;
        
     }

   }
   int x=k;
   while(x){
    x--;
    ans.pb(s%2);
     s/=2;
   }
   for(int i=ans.size()-1;i>=0;i--)
     cout<<ans[i];
   cout<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  while(cin>>n>>k){
      mem(vis,0);
    string s;
    while(!que.empty())
      que.pop();
    for(int i=1;i<=n;i++){
      cin>>s;
      int x=0;
      for(int j=0;j<k;j++)
      {
             x*=2;
            if(s[j]=='1') x+=1;
      }
      
      que.push(x),vis[x]=1;  
     
    }
     bfs();
  }
  return 0;
}


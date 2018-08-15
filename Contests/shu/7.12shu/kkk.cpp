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
string s[1100];
int vis[1100];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n)
  {  
      //vec.pb(0);
   for(int i=0;i<n;i++)
     {
         cin>>s[i];
     }
     mem(vis,0);
   // vec.pb(0);
    queue<int>que;
    que.push(0);
    vis[0]=1;
    vector<int>vec;
    vec.pb(0);
    while(!que.empty())
    {   
        int t=que.front();
        //vec.pb(t);
        que.pop();
        //cout<<t<<endl;
        for(int j=0;j<n;j++)
          if(!vis[j]&&s[t][j]=='1'){
              vec.pb(j);
              que.push(j);
              vis[j]=1;
          }
     }

     if(vec.size()<n) cout<<"impossible"<<endl;
     else {
         for(int i=n-1;i>=0;i--)
           cout<<vec[i]<<" ";
           cout<<endl;
     }

  }
  
  
  }


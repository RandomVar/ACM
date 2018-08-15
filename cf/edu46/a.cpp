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
int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
        string t;
        map<string,int>mp;
       map<string,int>mp2;
     for(int i=0;i<n;i++){
        cin>>t;
        mp[t]++;
     }
  int cnt=0;
     for(int i=0;i<n;i++)
      {
          cin>>t;

          if(mp.find(t)!=mp.end()&&mp[t]>0) mp[t]--;
          else{
            cnt++;
          }
      }
     cout<<cnt<<endl;

  }

}

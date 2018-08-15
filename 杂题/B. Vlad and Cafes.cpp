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
const int maxn=2*1e5+100;
int a[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n){
     map<int,int>mp;
     for(int i=1;i<=n;i++)
        cin>>a[i];
     for(int i=1;i<=n;i++){
        mp[a[i]]=i;

     }
     map<int,int>::iterator it;
    int ans=n+5,index=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
      if(ans>it->second)  ans=it->second,index=it->first;
    }
   cout<<index<<endl;
   }


}

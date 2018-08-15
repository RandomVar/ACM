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
int a[10];int sum;
int dfs(int x,int ans,int id){
  if(x==6&&id==3&&ans*2==sum) {
       return 1;
  }
  else if(x==6) return 0;
  if(dfs(x+1,ans,id)) return 1;
  ans+=a[x];
  if(dfs(x+1,ans,id+1)) return 1;
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  sum=0;
  for(int i=0;i<6;i++)
    cin>>a[i],sum+=a[i];
   if(dfs(0,0,0)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}

/**暴力，我真的……不会暴力**/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
int n,k;
int flag;ll ss;
ll ans;
ll a[100010];
void dfs(int u,int id,ll sum){
  //if(u==n) return;
  if(!flag&&id==k) {
        ans^=sum*sum;
        return;
        }
   else if(flag&&id==n-k){
     ans^=(ss-sum)*(ss-sum);
     return;
   }
    if(!flag){
        if(k-id==n-u+1) dfs(u+1,id+1,sum+a[u]);
        else{
            dfs(u+1,id+1,sum+a[u]);
            dfs(u+1,id,sum);
        }}
    else {
        if(n-k-id==n-u+1) dfs(u+1,id+1,sum+a[u]);
    else{
    dfs(u+1,id+1,sum+a[u]);
    dfs(u+1,id,sum);}}
  return;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    flag=0;
    cin>>n>>k;
    if(k>=n/2) flag=1;
    ss=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ss+=a[i];
    }
    //ll ans=0;
    ans=0;
    dfs(1,0,0);
   cout<<ans<<endl;
  }
return 0;
}

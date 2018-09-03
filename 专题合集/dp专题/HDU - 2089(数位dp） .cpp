#include<bits/stdc++.h>
#define ll long long
using namespace  std;

int bit[30];
ll dp[30][2][2];
ll dfs(int pos,int st,int flag){
   if(pos==0) return 1;
   if(flag&&dp[pos][st][flag]!=-1)
      return dp[pos][st][flag];
   int u=flag?9:bit[pos];
   ll ans=0;
   for(int i=0;i<=u;i++){
      if(i==4) continue;
      else if(st==0&&i==2) continue;
      else if(i!=6) ans+=dfs(pos-1,1,flag||i<u);
      else if(i==6) ans+=dfs(pos-1,0,flag||i<u);
   }
return ans;
}

ll solve(int n){
  int len=0;
  while(n){
     bit[++len]=n%10;
     n/=10;
  }
  return dfs(len,1,0);
}

int main(){
  int l,r;
  memset(dp,-1,sizeof(dp));
  while(cin>>l>>r){
        if(!l&&!r) break;
       // cout<<solve(r)<<endl;
    cout<<solve(r)-solve(l-1)<<endl;

  }
return 0;
}

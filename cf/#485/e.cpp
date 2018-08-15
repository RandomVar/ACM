#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int vis[maxn];
int a[maxn];
int dfs(int x,int cnt){
  vis[x]=1;
  if(!vis[a[x]]) return dfs(a[x],cnt+1);
return cnt;
}
int main(){
  int n;
  while(cin>>n){
        memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dfs(i,1)-1;
    }
    if((ans%2)==(n%2)) cout<<"Petr"<<endl;
    else cout<<"Um_nik"<<endl;
  }
return 0;
}

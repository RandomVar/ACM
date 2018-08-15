#include<bits/stdc++.h>
using namespace std;
struct node{
  int w,s,id;
  bool operator<(const node &b)const {
    if(w==b.w) return s>b.s;
    return w<b.w;
  }
}a[1100];
int dp[1100];
int path[1100];
void print(int x){
  if(path[x]!=-1) print(path[x]);
  cout<<a[x].id+1<<endl;

}
int main(){
   // freopen("data.in","r",stdin);
  // freopen("data.out","w",stdout);
  int m,s;int n=0;
  while(cin>>a[n].w>>a[n].s) {

        a[n].id=n;n++;
  }

  sort(a,a+n);
  //for(int i=0;i<n;i++)
    //cout<<a[i].id<<" "<<a[i].w<<" "<<a[i].s<<endl;
  memset(path,-1,sizeof(path));
 for(int i=0;i<n;i++)
    dp[i]=1;
  for(int i=0;i<n;i++){
     for(int j=0;j<i;j++){
         if(a[j].w<a[i].w&&a[j].s>a[i].s&&dp[j]+1>dp[i]) {
                dp[i]=dp[j]+1;
                path[i]=j;
  }
  }
  }
  int maxd=-1;int ans=-1;
  for(int i=0;i<n;i++){
    if(maxd<dp[i]){
        maxd=dp[i];
        ans=i;
    }
  }
  cout<<dp[ans]<<endl;
  print(ans);
}

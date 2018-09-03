#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
int a[250],b[250];
int path[250][450],dp[250][450];
vector<int>vec;
bool check(int u,int v,int x){
  for(int i=u;i>0;i--){
     if(path[i][v]==x) return 0;
      v=v-a[path[i][v]];
  }
  return 1;
}
int main(){
 int n,m;
 int cas=0;
 while(cin>>n>>m&&n){

    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
        memset(dp,0x3f,sizeof(dp));
        memset(path,0,sizeof(path));
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
         for(int k=1;k<=n;k++)
            for(int j=a[k];j<=m*20;j++){
            if(dp[i-1][j-a[k]]!=inf&&check(i-1,j-a[k],k)&&abs(j-(dp[i-1][j-a[k]]+b[k]))<abs(j-dp[i][j]))
            {
            dp[i][j]=dp[i-1][j-a[k]]+b[k];
            path[i][j]=k;
           // cout<<k<<endl;
            }
    }
   int ans=inf;int index=0;
   for(int j=0;j<=m*20;j++)
    {
        if(ans>=abs(dp[m][j]-j))
        {
            ans=abs(dp[m][j]-j);
            index=j;
        }
    }
    cout<<"Jury #"<<++cas<<endl;
     cout<<"Best jury has value "<<index<<" for prosecution and value "<<dp[m][index]<<" for defence:"<<endl;
   vec.clear();
   for(int i=m;i>=1;i--){
      vec.push_back(path[i][index]);
      index=index-a[path[i][index]];
   }
   sort(vec.begin(),vec.end());
   for(int i=0;i<vec.size();i++)
    cout<<" "<<vec[i];
  cout<<endl<<endl;
 }


}

#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int m[6][5];//i为5种装备
int r[6][1010];

int main(){
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    for(int j=1;j<=5;j++)
    cin>>r[j][i];
  }
  int ans=0;
  if(k>=5){
    for(int i=1;i<=5;i++)
      for(int j=0;j<n;j++)
        m[i][0]=max(m[i][0],r[i][j]);
    for(int i=1;i<=5;i++)
        ans+=m[i][0];
        cout<<ans<<endl;
  }
  else if(k==1){
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=1;j<=5;j++)
         cnt+=r[j][i];
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
  }

  else if(k<5){
    /*for(int i=1;i<=5;i++)
        sort(r[i],r[i]+n);
    int t=k;int ans[1<<21]=0;
    for(int i=1;i<=5;i++)
     for(int j=0;j<=5-k;j++){
       int index=m[i][j];

    }*/
  }
}

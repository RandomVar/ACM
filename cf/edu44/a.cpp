#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
  int n;
  while(cin>>n){
    for(int i=1;i<=n/2;i++){
         cin>>a[i];

    }
    sort(a+1,a+n/2+1);
    int ans=0;int cnt=2;
    for(int i=1;i<=n/2;i++){
        ans+=abs(a[i]-cnt);
        cnt+=2;
    }
    int ans2=0;cnt=1;
    for(int i=1;i<=n/2;i++){
        ans2+=abs(a[i]-cnt);
        cnt+=2;
    }
    ans=min(ans,ans2);
    cout<<ans<<endl;
  }


  return 0;
}

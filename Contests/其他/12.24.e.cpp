#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1010];
int main(){
  int t;
  cin>>t;
  while(t--){

    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        int cnt=0;int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==8){
                cnt=1;
         for(i=i+1;i<n;i++){
            if(a[i]==8) cnt++;
            else {  ans=max(ans,cnt);
                    break;}
         }
         if(i==n) ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
  }
}

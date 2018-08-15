#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1010];
int main(){
  int t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            for(int j=i-1;j>=1;j--){
                if(a[j]==-1) a[j]=(a[j+1]-1+m)%m;
            }
            for(int j=i+1;j<=n;j++){
                if(a[j]==-1) a[j]=(a[j-1]+1)%m;
            }
            break;
        }

    }
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
    cout<<a[n]<<endl;
  }

return 0;
}

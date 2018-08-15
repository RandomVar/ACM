#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int a[1010];

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int t;cin>>t;
    for(int j=1;j<=t;j++){
        cin>>a[j];
    }
    int ans=0;
    for(int j=1;j<=t;j++)
    for(int k=j+1;k<=t;k++){
        if(a[k]<a[j]) ans++;
    }
    cout<<"Scenario #"<<i+1<<":"<<endl;
    cout<<ans<<endl<<endl;
  }
}

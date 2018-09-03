#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  int t;
  cin>>t;int k=0;
  while(t--){
    ll n;
    cin>>n;
    cout<<"Case "<<++k<<": "<<n-(ll)sqrt(n)-(ll)sqrt(n/2)<<endl;
  }
 return 0;
}

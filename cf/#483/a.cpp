#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
  int n;
  while(cin>>n){
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    cout<<a[(n+1)/2]<<endl;
  }

}

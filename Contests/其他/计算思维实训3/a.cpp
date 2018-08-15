#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn];
void init(){
 a[1]=1;
 for(int i=2;i<maxn;i++){
        a[i]=1;
    for(int j=1;j<=i/2;j++){
        a[i]+=a[j];
    }
 }
}
int main(){

  int n;
  init();
  while(cin>>n){
    cout<<a[n]<<endl;
  }
}

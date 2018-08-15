#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int a[20];
int main(){
  int t;cin>>t;int k=0;
  while(k<t){
    k++;
    int n;cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    sort(a,a+n);
    int flag=0;
    if(a[0]>2||a[1]>2) flag=1;
    else{
    for(int i=2;i<n-1;i++){
        if(a[i]-a[i-1]>2) {
            flag=1;break;
        }
        else if(a[i]<=2) {
            flag=1;break;
        }
    }}
    if(flag) cout<<"Case #"<<k<<": "<<"Bad Problem Set"<<endl;
    else  cout<<"Case #"<<k<<": "<<"Good Problem Set"<<endl;
  }
}

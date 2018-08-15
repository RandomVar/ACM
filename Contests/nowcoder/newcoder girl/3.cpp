#include <iostream>
#include <cstdio>
using namespace std;
int a[100010];
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
    int cnt=0;
  for(int i=1;i<=n;i++){
    if(a[i]==i){
        if(a[i+1]==a[i+1]) {
                swap(a[i],a[i+1]);cnt++;
                i++;
    }
    else if(i<=1||a[i-1]==i||a[i]==i-1){
        swap(a[i],a[i+1]);cnt++;
    }
    else if(i==n||a[i+1]==i||a[i]==i+1){
        swap(a[i],a[i-1]);cnt++;
    }
  }}
   cout<<cnt<<endl;}
/*
5
1 4 3 5 2
*/

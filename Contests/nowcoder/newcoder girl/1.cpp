#include <iostream>
#include <cstdio>
using namespace std;
int p[100000];
int k;
void init(){
    k=0;
  for(int i=1;i*i<=1e9;i++){
    p[k++]=i*i;
  }
}
int main(){
  int n;
  init();
  cin>>n;
  int low=0;int high=k-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(n<p[mid]) high=mid-1;
    else if(n>=p[mid]) low=mid+1;
  }
  cout<<low*low<<endl;
}

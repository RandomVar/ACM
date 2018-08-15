#include <iostream>
#include <cstdio>
using namespace std;
char s[100000];
int main(){
  int n;
  cin>>n;
  int k=0;
  while(n){
    if(n%2==0) {
        s[k++]='G';
        n=(n-2)/2;
    }
    else{
        s[k++]='N';
        n=(n-1)/2;
    }
  }
  for(int i=k-1;i>=0;i--)
    cout<<s[i];
  cout<<endl;
}

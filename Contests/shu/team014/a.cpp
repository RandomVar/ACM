#include<iostream>
using namespace std;
int main(){
  int t;cin>>t;int k=0;
  while(k<t){
    k++;
    long long a,b,c;
    cin>>a>>b>>c;
    a*=a;
    b*=b;
    c*=c;
    int flag=0;
    if(a+b==c) flag=1;
    else if(a+c==b) flag=1;
    else if(b+c==a) flag=1;
    cout<<"Case #"<<k<<":";
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
  int v1,v2,v3,vm;
  while(cin>>v1>>v2>>v3>>vm){
    int flag=0;
    int ans1=0,ans2=0,ans3=0;
    for(int b1=v1;b1<=2*v1;b1++){
      for(int b2=v2;b2<=2*v2;b2++){
        for(int b3=max(v3,vm);b3<=min(2*v3,2*vm);b3++){
           if(b1>b2&&b2>b3&&(2*vm)<b2) {
            ans1=b1;ans2=b2;ans3=b3;flag=1;break;
           }
      }
      if(flag) break;}
      if(flag) break;}
      if(flag) cout<<ans1<<endl<<ans2<<endl<<ans3<<endl;
      else cout<<-1<<endl;
  }
}

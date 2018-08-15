#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   ll x,y;
   while(cin>>x>>y){
      double ans=y*log(x)-x*log(y);
      if(ans>0) cout<<">"<<endl;
      else if(ans<0) cout<<"<"<<endl;
      else cout<<"="<<endl;

   }


return 0;
}

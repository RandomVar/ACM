#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    string s;
    cin>>s;
    int ans=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='x') cnt++;
        else cnt=0;
        if(cnt==3) {ans+=1;cnt=2;}
    }
    cout<<ans<<endl;
  }


}

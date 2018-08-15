#include<bits/stdc++.h>
using namespace std;
int tt[1010];
int main(){
  int n,a,b,c,t;
  while(cin>>n>>a>>b>>c>>t){
    for(int i=0;i<n;i++)
        cin>>tt[i];
    int ans=n*a;
    if(b<c){
        for(int i=0;i<n;i++)
            ans+=(abs)((t-tt[i])*(b-c));}
        cout<<ans<<endl;

}}

#include<bits/stdc++.h>
using namespace std;
string s[2010];
int main(){
 int n,m;
 while(cin>>n>>m){
        getchar();
        set<int>st;
    for(int i=0;i<n;i++)
        cin>>s[i];
    int flag=1;
  for(int j=0;j<m;j++){
        int cnt=0;int index=-1;
    for(int i=0;i<n;i++){
        if(s[i][j]=='1') {cnt++;index=i;}
    }
 //cout<<cnt<<endl;
     if(cnt<=1) {st.insert(index);}
     }
  if(st.size()<n) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}}

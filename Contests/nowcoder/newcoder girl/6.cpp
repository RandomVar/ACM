#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m;
int cnt;
int l[30];
int r[30];
void dfs(int i,int s){
  if(i==n&&s==0) {cnt++;return;}
  if(i==n&&s!=0) return;
  if(s<l[i]) return;
  for(int k=l[i];k<=r[i];k++){
    dfs(i+1,s-k);
}}
int main(){
  //int n,m;
  cin>>n>>m;
  cnt=0;
  for(int i=0;i<n;i++)
    cin>>l[i]>>r[i];
    dfs(0,m);
    cout<<cnt<<endl;

}
/*
3 5
0 3
0 3
0 3
*/

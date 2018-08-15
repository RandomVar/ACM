#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5;
struct node{
 string name;
 string score;
}s[maxn+10];
bool cmp(node a,node b){
 int i;
 for(i=0;i<a.score.size()&&i<b.score.size();i++){
    if(a.score[i]>b.score[i]) return 1;
    else if(b.score[i]>a.score[i]) return 0;
 }
 if(i==a.score.size()&&i<b.score.size()) {
    if(b.score[i]>'0') return 0;
    else return a.name<b.name;
 }
  if(i=b.score.size()&&i<a.score.size()) {
    if(a.score[i]>'0') return 1;
    else return a.name<b.name;
 }
  return a.name<b.name;
}
int main(){
 int n;
 while(cin>>n){
    for(int i=0;i<n;i++){
        cin>>s[i].name;cin>>s[i].score;
    }
    sort(s,s+n,cmp);
  for(int i=0;i<n;i++){
    cout<<s[i].name<<" "<<s[i].score<<endl;
  }
}}

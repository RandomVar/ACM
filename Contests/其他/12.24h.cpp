#include<iostream>
#include<cmath>
using namespace std;
const int maxn=40000;
bool isprime[maxn];
void init(){
  isprime[1]=isprime[0]=0;
  for(int i=2;i<maxn;i++)
    isprime[i]=1;
  for(int i=2;i<sqrt(maxn*1.0);i++){
        if(isprime[i]){
    for(int k=2;k*i<maxn;k++){
        isprime[i*k]=0;
    }
  }}}
int main(){
  int n;
  init();
  while(cin>>n){
        if(n==0) break;
 // cout<<isprime[3]<<endl;
    if(n%2==1) {
        if(n>3&&isprime[n-2]) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else{
            int ct=0;
        for(int i=3;i<=n/2;i++){
            if(isprime[i]&&isprime[n-i])
              ct++;
        }
       cout<<ct<<endl;
    }

  }
  return 0;
}

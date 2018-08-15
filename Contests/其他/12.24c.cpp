#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long gcd(long long a,long long b){
         if(a < b){
                   long long temp;
                   temp = a;
                   a = b;
                   b = temp;
         }
         while(a % b){
             long long r = a % b;
                   a = b;
                   b = r;
                   r = a % b;
         }
         return b;}

int main(){
  ll a,b,c;
  while(cin>>a>>b>>c){
        //ll x,y;
    ll ans=gcd(a,b);
    if(a%c==0||b%c==0) cout<<"Yes"<<endl;
    else if(a>c||b>c) cout<<"No"<<endl;
    else if(c%ans==0) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
  }
  return 0;
}

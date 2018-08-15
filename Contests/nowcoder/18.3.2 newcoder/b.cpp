#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pre;
ll c[5];int b[]={0,1,5,10,50};
void cal(int i,int v){
 ll x=(v-pre)%b[i];
 c[i]-=(v-pre)/b[i]+1;
 x=b[i]-x;
 int y=i-1;
 while(x>0&&y>0){
   if(x>=b[y]){
    ll t=x/b[y];
    c[y]+=t;
    x-=t*b[y];
   }
   y--;
 }
 pre=0;

if(c[i]*b[i]>=v){
 ll f=v/b[i]+1;
 ll e=c[i]/f;
 c[i]=c[i]%f;
 ll x2=f*b[i]-v;
 int y2=i-1;
 while(x2>0&&y2>0){
   if(x2>=b[y2]){
    ll t=x2/b[y2];
    c[y2]+=t*e;
    x2-=t*b[y2];
   }
   y2--;
 }}

}

int main(){
 int t;ll v;
 cin>>t;
 while(t--){
    cin>>c[1]>>c[2]>>c[3]>>c[4]>>v;
    pre=0;
  if(v%5==0){
    cout<<c[1]<<endl;
  }
  else{
 for(int i=4;i>=2;i--){
    if(c[i]>0){
        if(pre+c[i]*b[i]>=v) {
        cal(i,v);
        pre=c[i]*b[i];
        }
        else {pre+=c[i]*b[i];}
    }
 }
 cout<<c[1]<<endl;}
// for(int i=1;i<=4;i++)
  //  cout<<c[i]<<" ";
 }
return 0;
}

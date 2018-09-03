#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
int a[100000];
void init(){
    memset(a,-1,sizeof(a));
  a[1]=0;
  for(int i=2;i*i<=66000;i++){

     for(int k=2;k*i*i+k<=66000;k++){
         if(a[k*i*i+k]==-1) a[k*i*i+k]=k;
     }
     a[i*i]=0;
  }


}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   init();
   while(t--){
        int s;
       cin>>s;
      if(a[s]==-1) cout<<-1<<endl;
      else {
        if(a[s]==0){

            int x=sqrt(s);
            cout<<x<<" ";
            for(int i=1;i<x;i++)
                cout<<x<<" ";
            cout<<x<<endl;

        }
        else{
            int x=sqrt((s-a[s])/a[s]);
            cout<<(a[s]-1)*x+1<<" ";
            cout<<a[s]<<" ";
            for(int i=1;i<(a[s]-1)*x;i++)
                cout<<a[s]*x<<" ";
            cout<<a[s]*x<<endl;

        }
      }
   }


}

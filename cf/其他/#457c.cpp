#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=1e9;
const int MAXN=100010;
bool notprime[MAXN];
void init() {
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
        if(!notprime[i]) {
            if(i>MAXN/i)continue;//防止溢出,或者i,j用long long
        for(int j=i*i;j<MAXN;j+=i)
        notprime[j]=true;}
     }
int main(){
  int n,m;
  while(cin>>n>>m){
    int t;
    for(int i=n-1;i<=MAXN;i++){
        if(notprime[i]==false) {t=i;break;}
    }
    cout<<t<<" "<<t<<endl;
   for(int i=1;i<n-1;i++){
    cout<<i<<" "<<i+1<<" "<<1<<endl;
   }
   cout<<n-1<<" "<<n<<" "<<t-n+1<<endl;
   int i=n;
    for(int j=1;j<=n;j++){
        for(int k=j+2;k<=n;k++)
         {cout<<j<<" "<<k<<" "<<INF<<endl;i++;
          if(i>m) break;
         }
         if(i>m) break;
    }
   }
  }

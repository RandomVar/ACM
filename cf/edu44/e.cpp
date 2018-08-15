#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5*1e5+100;

ll a[maxn];
int main(){
  ll n,k,d;
  while(cin>>n>>k>>d){
     for(int i=1;i<=n;i++)
        cin>>a[i];
     sort(a+1,a+1+n);
    int i=1;
    int flag=1;
    /*while(i<=n){
            int p1=upper_bound(a+i,a+n+1,a[i]+d)-a;
            if(p1-i<d) {flag=0;break;}
        //if(a[i+k-1]-a[i]>d) {flag=0;break;}
           i=p1;
    }*/
    //dp[i][j]=//i-j
    //dp[i][j]=dp[i][j]
   for(int i=1;i<=n;i++){
        dp[i][1]=1;
     for(int j=k;j<=n;j++){
         if(a[j+i-1]-a[i]<=d) dp[i][j]=dp[i][j-1];
   }
   }
   if(flag) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
  }


}

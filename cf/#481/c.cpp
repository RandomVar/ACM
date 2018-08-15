#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2*1e5+100;
ll sum[maxn];
ll a[maxn];

int main(){
  int n,m;
  while(cin>>n>>m){
        sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int pre=0;
    for(int i=1;i<=m;i++)
     {
         ll t;
         cin>>t;
         int p1=lower_bound(sum+pre,sum+n+1,t)-sum;//>=t

         //if(p1==n+1) cout<<p1<<" "<<a[n]<<endl;
         cout<<p1<<" "<<t-sum[p1-1]<<endl;
         pre=p1;
     }

}}

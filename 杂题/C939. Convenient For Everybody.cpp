#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int sum[maxn];
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<n;i++){
            int t;
        cin>>t;
        if(i) sum[i]=sum[i-1]+t;
        else sum[i]=t;
    }
    int s,f;
    cin>>s>>f;int ans=-1;int cnt=-1;
    for(int x=1;x<=n;x++){
            int a1=0;
        int i1=s-x;
        int i2=f-x-1;
        if(i2>=0) {
            if(i1<1) a1=sum[i2];
            else a1=sum[i2]-sum[i1-1];
        }
        i1=s-x;
        i2+=n;
        i1+=n;
        if(i1<=n){
            if(i2>=n) i2=n-1;
            a1+=sum[i2]-sum[i1-1];
        }
        if(cnt<a1) {cnt=a1;ans=x;}
    }
   // cout<<cnt<<endl;
    cout<<ans<<endl;
   /* int l=0;int r=n;
    while(l<=r){
        int mid=(l+r)/2;
        int i1=mid-s;
        int i2=mid-f-1;
        sum[i2]-sum[i1];
    }*/
  }

}

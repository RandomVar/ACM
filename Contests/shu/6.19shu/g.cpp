#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+100;
int a[maxn],m[maxn],s[maxn];
int main(){
  //  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  //cin>>t;
  scanf("%d",&t);
  while(t--){
     int n;
     scanf("%d",&n);
     //cin>>n;
     for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //cin>>a[i];
     }
     //m[0]=1e;s[n+1]=1e6+100;
     for(int i=1;i<=n;i++){
        if(i==1) m[i]=a[i];
        else m[i]=max(m[i-1],a[i]);

     }
     for(int i=n;i>=1;i--){
        if(i==n) s[i]=a[i];
        else s[i]=min(s[i+1],a[i]);
     }
     int cnt=0;
     for(int i=2;i<n;i++){
        if(m[i-1]<=a[i]&&s[i+1]>=a[i])
          {cnt++;}
     }
     printf("%d\n",cnt);
     //cout<<cnt<<endl;
  }

return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
int d[]={-2,-1,-1,0,0,0,1,1,2};
ll a[maxn];
int main(){
  int n;
  while(cin>>n){
        int xflag=0;
        int daan=n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1) {cout<<0<<endl;continue;}
    ll x=a[n-1]-a[0];
    int cnt;
  for(int j=0;j<=8;j++){
    ll ans;
    int flag=1;
    cnt=0;
     ll c=(x+d[j])/(n-1);
     if(c*(n-1)!=(x+d[j])) continue;
       if(j==0) ans=a[0]+1;//-2
        else if(j==1)
              ans=a[0]+1;//-1
        else if(j==2)
            ans=a[0];//-1
        else if(j==3)
            ans=a[0];//0
        else if(j==4)
            ans=a[0]+1;//0
        else if(j==5)
            ans=a[0]-1;//0
        else if(j==6)
            ans=a[0]-1;//1
        else if(j==7)
            ans=a[0];//1
        else if(j==8)
            ans=a[0]-1;//2
    for(int i=0;i<n;i++){
      if(abs(ans-a[i])>1) {flag=0;break;}
      else if(abs(ans-a[i])==1) cnt++;
       ans+=c;
    }
    if(flag) {xflag=1;daan=min(daan,cnt);}
   // cout<<ans<<" "<<cnt<<endl;
  }
  if(xflag) cout<<daan<<endl;
  else cout<<-1<<endl;
}
return 0;
}

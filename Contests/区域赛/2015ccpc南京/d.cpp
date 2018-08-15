#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
  int l;ll v;
  bool operator<(const node &b)const{
    long double x=(long double)v*1.0/l;
    long double y=(long double)b.v*1.0/b.l;
    if(x==y) return l>b.l;
    return x<y;

}
}a[1010];
int main(){
  int t;
  cin>>t;int cas=0;
  while(t--){
    int n,l;
    cin>>n>>l;
    int x1=0,x2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].v;
         if(a[i].l>x1) {
                x2=x1;
                x1=a[i].l;
         }
         else if(a[i].l>x2) x2=a[i].l;
    }

    sort(a+1,a+1+n);
    int res=0;ll ans=0,ans2,ans3;
    int i;
    int flag=0;
    for(int i=1;i<=n;i++)
       for(int s=l+(x1+x2)/2;s>=a[i].l;s--)
           if(dp[s-a[i].l].v+a[i].v>dp[s].v)
           {
               dp[s].v=dp[s-a[i].l].v+a[i].v;
               if(a[i].l>dp[s].x1){
                  dp[s].x2=dp[s].x1;
                  dp[s].x1=a[i].l;
               }
               else if(a[i].l>dp[s].x2) dp[s].x2=a[i].l;
           }

    /*
    for(i=n;i>=1;i--){
        if(res+a[i].l<=l){
            res+=a[i].l;
            ans+=a[i].v;
        }
        else break;
    }
    cout<<ans<<endl;
    ans2=ans+a[i].v;
    int x1=0;int x2=0;
    for(int j=n;j>=i;j--){
        if(x1<a[j].l) {x1=a[j].l;}
        else if(x2<a[j].l) {x2=a[j].l;}
    }
    if(res+(x2+x1+1)/2<=l) flag=1;
    if(flag){
        i++;
       ans3=ans2+a[i].v;
       if(a[i].l>=x1) {
          x2=x1;
          x1=a[i].l;
       }
      else if(a[i].l>x2){
        x2=a[i].l;
      }
      if(res+(x2+x1+1)/2<=l) flag=2;
    }*/
   cout<<"Case #"<<++cas<<": ";
   if(flag==0) cout<<ans<<endl;
   else if(flag==1) cout<<ans2<<endl;
   else cout<<ans3<<endl;
  }
  return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
const int mod=1e9+7;
ll ans[maxn];
int n;
struct node{
  ll val;int id;
  bool operator<(const node &c)const {

    return val<c.val;
  }
}b[maxn];
int find1(ll t){
 int lb=0;int ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(b[mid].val>=t) ub=mid;
    else lb=mid;
  }
  return ub;
}

int main(){
  int t;
  scanf("%d",&t);
  //cin>>t;
  while(t--){
    //int n;
    scanf("%d",&n);
    //cin>>n;
    for(int i=1;i<=n;i++){
        //cin>>b[i].val;
       scanf("%lld",&b[i].val);
       b[i].id=i;
    }
    sort(b+1,b+1+n);
    ll mm=1e9+7;
    for(int i=1;i<=n;i++){
            ans[b[i].id]=0;
            int p1=find1(mm-b[i].val);
            if(p1-1!=i&&p1-1>0){
                ans[b[i].id]=(b[i].val+b[p1-1].val)%mod;
            }
            else if(p1-1==i&&p1-2>0){
                ans[b[i].id]=(b[i].val+b[p1-2].val)%mod;
            }
           if(i!=n) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[n].val)%mod);
            else ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[n-1].val)%mod);
    }
            /*if(p1==0||p1==1){
                   if(i!=n) ans[b[i].id]=(b[i].val+b[n].val)%mod;
                   else if(i!=n-1) ans[b[i].id]=(b[i].val+b[n-1].val)%mod;
                   if(i!=1) ans[b[i].id]=(b[i].val+b[1].val)%mod;
            }
             else if(p1==n){
                 if(i!=n) ans[b[i].id]=(b[i].val+b[n].val)%mod;
                  else ans[b[i].id]=(b[i].val+b[n-1].val)%mod;
            }
            else if(p1-1==i){
                //ans[b[i].id]=(b[i].val+b[p1].val)%mod;
                if(p1-2>=1) ans[b[i].id]=(b[i].val+b[p1-2].val)%mod;
                else if(i!=n) ans[b[i].id]=(b[i].val+b[n].val)%mod;
                else if(i!=n-1&&n>=2) ans[b[i].id]=(b[i].val+b[n-1].val)%mod;
            }

           else {
             ans[b[i].id]=(b[i].val+b[p1-1].val)%mod;

           }

           int p2=find1(2*mm-b[i].val);
            if(p2==0||p2==1){
                   if(i!=n) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[n].val)%mod);
                   else if(i!=n-1) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[n-1].val)%mod);
                  if(i!=1) ans[b[i].id]=(b[i].val+b[1].val)%mod;
            }
             else if(p1==n){
                 if(i!=n) ans[b[i].id]=(b[i].val+b[n].val)%mod;
                  else ans[b[i].id]=(b[i].val+b[n-1].val)%mod;
            }
            else if(p2-1==i){
                //ans[b[i].id]=(b[i].val+b[p1].val)%mod;
                if(p2-2>=1) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2-2].val)%mod);
                else if(i!=n) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[n].val)%mod);
                else  if(i!=n-1&&n>=2) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[n-1].val)%mod);
            }
           else {
             ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2-1].val)%mod);

           }
    }
            //cout<<p1<<endl;
            /*if(p1==i) {
                if(p1+1<=n) ans[b[i].id]=(b[i].val+b[p1+1].val)%mod;
                if(p1-1>=1) ans[b[i].id]=max(ans[b[i].id],b[i].val+b[p1-1].val)%mod;

             }

            else if(p1==0) {
                    ans[b[i].id]=(b[i].val+b[1].val)%mod;
                   if(p1!=n) ans[b[i].id]=max(ans[b[i].id],b[i].val+b[n].val)%mod;
                    else ans[b[i].id]=max(ans[b[i].id],b[i].val+b[n-1].val)%mod;
            }
             else if(p1==i-1){
                ans[b[i].id]=(b[i].val+b[p1].val)%mod;
                if(p1-2>=1) ans[b[i].id]=max(ans[b[i].id],b[i].val+b[p1-2].val)%mod;

             }

            else {
                if(p1-1>=1)  ans[b[i].id]=max((b[i].val+b[p1-1].val)%mod,(b[i].val+b[p1].val)%mod);
                 else ans[b[i].id]=(b[i].val+b[p1].val)%mod;
            }
            int p2=find1(2*mm-b[i].val);
            if(p2==i) {
                if(p2+1<=n) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2+1].val)%mod);
                if(p2-1>=1) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2-1].val)%mod);
             }
            else if(p2==0) ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[0].val)%mod);
            else if(p2==i-1){
                ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2].val)%mod);
                if(p2-2>=1) ans[b[i].id]=max(ans[b[i].id],b[i].val+b[p2-2].val)%mod;

             }
            else {
                if(p2-1>=1)  ans[b[i].id]=max((b[i].val+b[p2-1].val)%mod,ans[b[i].id]);
                ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2].val)%mod);
            }

               // ans[b[i].id]=max(ans[b[i].id],(b[i].val+b[p2].val)%mod);
             //cout<<p2<<endl;
    }*/
        /* int p1=lower_bound(b,b+1+n,mm-a[i])-b;//>=
         ans[i]=(a[i]+b[p1-1])%mod;
         int p2=lower_bound(b,b+1+n,2*mm-a[i])-b;//>=
         ans[i]=max(ans[i],(a[i]+b[p2-1])%mod);
   */
    for(int i=1;i<n;i++)
        printf("%lld ",ans[i]);
        printf("%lld\n",ans[n]);
        //cout<<ans[i]<<" ";
    //cout<<ans[n]<<endl;
  }

return 0;
}

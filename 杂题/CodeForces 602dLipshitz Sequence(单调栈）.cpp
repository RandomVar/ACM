#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=100100;
ll h[maxn],a[maxn];
ll st[maxn];
ll cnt1[maxn],cnt2[maxn];
int n;
void zhan1(){
 int tot=-1;
 st[++tot]=0;
 cnt1[0]=1;
 for(int i=1;i<n-1;i++){
    if(h[i]>=h[st[tot]]){
        while(tot>=0&&h[i]>=h[st[tot]])
          tot--;
        if(tot==-1)
            st[++tot]=i,cnt1[i]=i+1;
        else
            cnt1[i]=i-st[tot],st[++tot]=i;
    }
    else{
       cnt1[i]=i-st[tot];
       st[++tot]=i;
    }
 }
}
void zhan2(){
 int tot=-1;
 st[++tot]=n-2;
 cnt2[n-2]=1;
 for(int i=n-3;i>=0;i--){
    if(h[i]>h[st[tot]]){
        while(tot>=0&&h[i]>h[st[tot]])
          tot--;
        if(tot==-1)
            st[++tot]=i,cnt2[i]=n-i-1;
        else
            cnt2[i]=st[tot]-i,st[++tot]=i;
    }
    else{
       cnt2[i]=st[tot]-i;
       st[++tot]=i;
    }
 }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int q;
  while(cin>>n>>q){
     for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++)
        h[i]=abs(a[i]-a[i+1]);
    zhan1();
    zhan2();
    for(int i=1;i<=q;i++){
        int l,r;
       cin>>l>>r;
       l--;r--;
       ll ans=0;
       for(int j=l;j<r;j++){
          ans+=min((ll)j-l+1,cnt1[j])*min(cnt2[j],(ll)r-j)*h[j];
         // cout<<cnt1[j]<<" "<<cnt2[j]<<" "<<h[j]<<endl;
         // cout<<j-l+1<<" "<<r-j<<endl;
          //cout<<ans<<endl;
       }
        cout<<ans<<endl;

    }

  }


}

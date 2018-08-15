
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//


struct node{
  ll l,r;
  bool operator<(const node &b)const{
  if(l==b.l) return r>b.r;
  return l<b.l;
  }
}a[100010];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n,m;
  while(cin>>n>>m){
    for(ll i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].r++;//[ ) is more convenience

    }
    sort(a,a+n);
    int k=0;
    for(ll i=0;i<n;i++){
        if(a[k].r>=a[i].l) a[k].r=max(a[k].r,a[i].r);
        else a[++k]=a[i];
    }
        ll ans=0;
    for(int i=0;i<=k;i++){
        ans=max(ans,a[i].r-a[i].l+m);// m of course should  be added
    }
    ll sum=0;ll res=m;int j=0;
    for(int i=0;i<=k;i++){
        if(i==j) {sum=a[i].r-a[i].l;j++;}//the init
        while(j<=k){
            if(a[j].l-a[j-1].r<=res) {
                sum+=a[j].r-a[j-1].r;//only add the add area
                res-=a[j].l-a[j-1].r;
                j++;
                }
            else break;
        }
        ans=max(ans,sum+res);//the res part should  be added
        if(j>i+1){
            res+=a[i+1].l-a[i].r;//i will move and we should re it
            sum-=a[i+1].l-a[i].l;
        }
    }
    cout<<ans<<endl;
  }
}

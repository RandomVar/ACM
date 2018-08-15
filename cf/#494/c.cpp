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
int a[5100];
struct node{
 ll val;
 int id;
 bool operator<(const node &b)const{
  return val*b.id>b.val*id;

 }

}cnt[5100];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k){
     for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int j=k;j<=n;j++){
        cnt[j-k].id=j;
        cnt[j-k].val=0;
        ll ans=0;
        for(int i=1;i<=j;i++){
            ans+=a[i];
        }
       cnt[j-k].val=max(cnt[j-k].val,ans);
        for(int i=j+1;i<=n;i++){
            ans+=a[i];
            ans-=a[i-j];
            cnt[j-k].val=max(cnt[j-k].val,ans);
        }

    }
    sort(cnt,cnt+n-k+1);

  printf("%.7lf\n",(double)cnt[0].val*1.0/cnt[0].id);
  //  cout<<<<endl;
  }

return 0;
}

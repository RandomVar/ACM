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
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll sum[200010];
ll a[200010];
int main(){
 int n,q;
 while(cin>>n>>q){
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
     }
        int index=1;
        ll pre=0;
    for(int i=1;i<=q;i++){
        ll k;
        cin>>k;
        int p1=upper_bound(sum+1,sum+n+1,k+pre)-sum;//>
        if(p1==n+1) {index=1;pre=0;cout<<n<<endl;}
        else{
            index=p1;
            pre+=k;
            cout<<n-p1+1<<endl;
         }
    }
 }
return 0;
}
